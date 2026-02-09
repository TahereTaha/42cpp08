#include <iostream>
#include <vector>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>

static void	fill_vector(std::vector<int> &vec, size_t size)
{
	std::srand(std::time(NULL));
	size_t	i = 0;
	while (i < size)
	{
		vec.push_back(std::rand() % 1000000000);
		i++;
	}
}

static void	print_vector(std::vector<int> vec)
{
	size_t i = 0;
	while (i < vec.size())
	{
		std::cout << "val at index " << i << ": " << vec[i] << std::endl;
		i++;
	}
}

//	std::vector<int> arr;
//	fill_vector(arr, 1000);
//	print_vector(arr);

int main(void)
{
	{
		Span	span1(3);
		
		span1.addNumber(4);
		span1.addNumber(5);
		span1.addNumber(7);
		try
		{
			span1.addNumber(4);
		}
		catch (std::exception &e)
		{
			std::cout << "exception caugth: " << e.what() << std::endl;
		}
	}
	{
		Span	span1(5);
		std::vector<int>	vec1;
		
		fill_vector(vec1, 6);
		print_vector(vec1);
		
		span1.addNumber(4);
		span1.addNumber(5);
		try {
			span1.addNumber(vec1.begin(), vec1.end());
		}
		catch (std::exception &e)
		{
			std::cout << "exception caugth: " << e.what() << std::endl;
		}
	}
	{
		Span	span1(10000);
		std::vector<int>	vec1;

		fill_vector(vec1, 10000);
		print_vector(vec1);
		span1.addNumber(vec1.begin(), vec1.end());
		std::cout << "shortest: " << span1.shortestSpan() << std::endl;
		std::cout << "longest: " << span1.longestSpan() << std::endl;
	}
}
