#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <iostream>

template<typename T>

class Container 
{
public:
	Container() 
	{

	}
	
	~Container() 
	{
		container.clear();
	}

	void AddElement(T t_) 
	{
		container.push_back(t_);
	}

	void PrintElements() 
	{
		for (auto element : container) 
		{
			std::cout << element <<
				std::endl;
		}
	}

private:
	std::vector<T> container;
};

#endif