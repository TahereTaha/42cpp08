/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:23:33 by tatahere          #+#    #+#             */
/*   Updated: 2026/02/09 03:52:50 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

//	canonical orthodox form.
Span::Span(void)
{
	std::cout << "Span default constructor." << std::endl;
	this->_size = 0;
}

Span::Span(const Span & src)
{
	std::cout << "Span copy constructor." << std::endl;
	*this = src;
}

Span & Span::operator = (const Span & src)
{
	std::cout << "Span copy assigment." << std::endl;
	if (this != &src)
	{
		this->_storage = src._storage;
		this->_size = src._size;
	}
	return (*this);
}

Span::~Span(void)
{
	std::cout << "Span default destructor." << std::endl;
}

//	constructors.
Span::Span(size_t size)
{
	std::cout << "Span constructor." << std::endl;
	this->_size = size;
}

//	methods.
void		Span::addNumber(int number)
{
	if (this->_storage.size() == this->_size)
		throw std::length_error("exeded the storage capacity");
	this->_storage.push_back(number);
}

int		Span::shortestSpan(void) const 
{
	if (this->_storage.size() < 2)
		throw std::out_of_range("unable to get a span with less than 2 elements");
	std::vector<int>	tmp = this->_storage;
	std::sort(tmp.begin(), tmp.end());
	int		span = tmp[1] - tmp[0];
	size_t	i = 1;
	while (i < tmp.size() - 1)
	{
		int	new_span = tmp[i + 1] - tmp[i];
		if (span > new_span)
			span = new_span;
		i++;
	}
	return (span);
}

int		Span::longestSpan(void) const 
{
	if (this->_storage.size() < 2)
		throw std::out_of_range("unable to get a span with less than 2 elements");
	int	min = *std::min_element(this->_storage.begin(), this->_storage.end());
	int	max = *std::max_element(this->_storage.begin(), this->_storage.end());
	return (max - min);
}







