// 이름공간(namespace)

// 동일한 이름공간에 정의된 함수를 호출할 때에는 이름공간을 명시할 필요가 없다. 

#include <iostream> 

namespace Chulsoo
{
	void SimpleFunc(void);
}

namespace Chulsoo
{
	void PrettyFunc(void);
}

namespace Younghee
{
	void SimpleFunc(void);
}

int main()
{
	Chulsoo::SimpleFunc();

	return 0;
}

void Chulsoo::SimpleFunc(void)
{
	std::cout << "Chulsoo 정의한 함수" << std::endl;
	PrettyFunc();
	Younghee::SimpleFunc();
}

void Chulsoo::PrettyFunc(void)
{
	std::cout << "So Pretty!" << std::endl;
}

void Younghee::SimpleFunc(void)
{
	std::cout << "Younghee 정의한 함수" << std::endl;
}