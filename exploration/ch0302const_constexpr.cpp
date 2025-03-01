// const, constexpr 차이점

//			const							constexpr(constant expression)
// 역할:	변수/함수의 값 변경 방지		컴파일 시간에 값이 확정됨
// 적용:	런타임 또는 컴파일 타임			반드시 컴파일 타임
// 사용:	객체, 포인터, 함수				상수, 함수, 반복문 최적화

#include <iostream>

using namespace std;

constexpr int SQUARE(int x) {
	return x * x;
}

int main()
{
	// const
	{
		const int a = 10;
		a = 20; // 오류, const 변수는 변경 불가

		int b = 20;
		const int* ptr = &b;
		*ptr = 30; // 오류, ptr이 가리키는 값 변경 불가
	}

	//constexpr
	{
		constexpr int num = SQUARE(5); // 컴파일 타임에 계산됨
		cout << "5의 제곱: " << num << endl;

		int a = 10;
		constexpr int num2 = SQUARE(a); // 오류, a는 런타임 값이라 컴파일 타임에 확정 안됨
	}

	return 0;
}