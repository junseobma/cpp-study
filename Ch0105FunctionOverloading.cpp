// 함수 오버로딩(Function Overloading)

// C언어에서 동일한 이름의 함수가 정의되는 것을 허용하지 않는다. 함수명으로만 호출대상을 찾기 때문이다.

// C++에서는 함수호출 시 전달되는 인자를 통해서 호출하고자 하는 함수의 구분이 가능하기 때문에 
// 매개변수의 선언형태가 다르다면, 동일한 이름의 함수를 정의 할 수 있다. 

// 함수 오버로딩이 가능하려면 매개변수의 자료형이 다르거나 매개변수의 개수가 달라야 한다. 
// 반환형으로는 호출되는 함수를 구분하는 기준이 될 수 없다. 

#include <iostream> 

void MyFunc(void)
{
	std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c)
{
	std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int a, int b)
{
	std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main()
{
	MyFunc();
	MyFunc('c');
	MyFunc(1, 2);

	return 0;
}
