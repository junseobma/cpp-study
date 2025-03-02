#include <iostream> 

using namespace std;

void modify(int& x)
{
	x = 100; // 원본 변수 변경됨
}

int main()
{
	{
		int a = 10;
		int& ref = a;

		cout << "a: " << a << " ref: " << ref << endl;

		ref = 20;
		cout << "a: " << a << " ref: " << ref << endl;
	}

	{
		int num = 5;
		modify(num);
		cout << num << endl;
	}

	return 0;
}