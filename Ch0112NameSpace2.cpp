// 이름공간(namespace)

// 함수의 선언과 정의를 분리하는 것이 일반적이다. 
// 함수의 선언은 헤더파일에 저장하고,
// 함수의 정의는 소스파일에 저장한다.

#include <iostream> 

namespace Chulsoo
{
	void SimpleFunc(void);
}

namespace Younghee
{
	void SimpleFunc(void);
}

int main()
{
	Chulsoo::SimpleFunc();
	Younghee::SimpleFunc();

	return 0;
}

void Chulsoo::SimpleFunc(void)
{
	std::cout << "Chulsoo 정의한 함수" << std::endl;
}

void Younghee::SimpleFunc(void)
{
	std::cout << "Younghee 정의한 함수" << std::endl;
}