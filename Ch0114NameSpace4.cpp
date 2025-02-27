// 이름공간(namespace)

// 이름공간은 다른 이름공간 안에 삽입될 수 있다.

#include <iostream> 

namespace MainName
{
	int num = 0;

	namespace SubNameOne
	{
		int num = 1;
	}

	namespace SubNameTwo
	{
		int num = 2;
	}
}

int main()
{
	std::cout << "MainName: " << MainName::num << std::endl;
	std::cout << "SubNameOne: " << MainName::SubNameOne::num << std::endl;
	std::cout << "SubNameTwo: " << MainName::SubNameTwo::num << std::endl;

	return 0;
}