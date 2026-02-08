#pragma once 

#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &container, int val)
{
	return (std::find(container.begin(), container.end(), val));
}

template <typename T>
typename T::iterator easyfind(T &container, int val)
{
	return (std::find(container.begin(), container.end(), val));
}


