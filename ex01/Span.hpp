/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:43:30 by tatahere          #+#    #+#             */
/*   Updated: 2026/02/09 03:50:13 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <vector>
# include <stdexcept>

class Span
{
	private:
		size_t				_size;
		std::vector<int>	_storage;

		Span(void);
	public:

		Span(size_t size);
		Span(const Span & src);
		~Span(void);
		Span & operator = (const Span & src);

		void	addNumber(int);

		template <typename It>
		void	addNumber(It begin, It end)
		{
			if (this->_storage.size() + std::distance(begin, end) > this->_size)
				throw std::length_error("exeded the storage capacity");
			this->_storage.insert(this->_storage.end(), begin, end);
		}

		int	shortestSpan(void) const ;
		int	longestSpan(void) const ;
};
