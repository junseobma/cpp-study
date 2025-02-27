// 이름공간(namespace)

// 여러 개발자가 함수 및 변수의 이름이 같다면 충돌하는 문제가 발생할 수 있다.
// 프로젝트를 진행하기 전에 함수 및 변수의 이름을 모두 정해서 
// 이름 충돌이 발생하지 않게 하는것은 한계가 있으므로 근본적인 해결책이 되지 못한다.
// 이것을 해결하기 위해 이름공간(namespace)이라는 문법을 정의해서 근본적인 해결책을 제시하고 있다.
// 말 그대로 특정 영역에 이름을 붙여주기 위한 문법적 요소이다.

// :: 연산자
// 범위지정 연산자(scope resolution operator)라고 한다.
// 이름이 의미하듯 이름공간을 지정할 때 사용하는 연산자이다.

#include <iostream> 

namespace Chulsoo
{
	void SimpleFunc(void)
	{
		std::cout << "Chulsoo 정의한 함수" << std::endl;
	}
}

namespace Younghee
{
	void SimpleFunc(void)
	{
		std::cout << "Younghee 정의한 함수" << std::endl;
	}
}

int main()
{
	Chulsoo::SimpleFunc();
	Younghee::SimpleFunc();

	return 0;
}
