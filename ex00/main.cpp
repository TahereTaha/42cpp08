#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int>	vec1;

	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(42);
	vec1.push_back(7);
	vec1.push_back(5);

	size_t	i = 0;
	while (i < vec1.size())
	{
		std::cout << "val in index " << i << " is: " << vec1[i] << std::endl;
		i++;
	}
	{
		std::cout << "trying to find the value of: " << 42 << std::endl;
		std::vector<int>::iterator	result = easyfind(vec1, 42);
		if (result == vec1.end())
			std::cout << "didn't find the value." << std::endl;
		else 
			std::cout << "finded the value of " << *result << std::endl;
	}
	{
		std::cout << "trying to find the value of: " << 53 << std::endl;
		std::vector<int>::iterator	result = easyfind(vec1, 53);
		if (result == vec1.end())
			std::cout << "didn't find the value." << std::endl;
		else 
			std::cout << "finded the value of " << *result << std::endl;
	}
	return (0);
}
