// 함수 오버로딩 Function Overloading

// 함수의 이름이 동일하지만, 매개변수 타입 또는 개수가 다르면 여러 개 정의 가능
// 리턴 타입이 다르더라도 오버로딩의 기준이 되지 않음. 반드시 매개변수가 달라야 함

#include <iostream> 

using namespace std;

void Print(int a)
{
	cout << "정수 : " << a << endl;
}

void Print(double a)
{
	cout << "실수 : " << a << endl;
}

void Print(string a)
{
	cout << "문자열 : " << a << endl;
}

int main()
{
	Print(10);
	Print(3.141592);
	Print("HELLO WORLD");
	
	return 0;
}
