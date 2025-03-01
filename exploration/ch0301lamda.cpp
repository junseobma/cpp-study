// 람다(Lambda) 표현식

// 익명 함수(anonymous function)를 쉽게 작성할 수 있도록 도와주는 기능
// 주로 간단한 콜백 함수, STL 알고리즘(std::sort, std::for_each 등)과 함께 사용

// [캡처](매개변수) -> 반환타입 {
//     함수 본문
// };

// [] 캡처 리스트: 외부 변수를 람다 내부에서 어떻게 사용할지 지정
// () 매개변수 리스트: 일반적인 함수의 매개변수처럼 사용
// ->반환타입: 생략 가능(자동 추론됨)
// {} 함수 본문: 실행될 코드

#include <iostream>

using namespace std;

int main()
{
	// 기본 형태
	{
		auto hello = []() {
			cout << "Hello Lamda!" << endl;
			};

		hello();
	}

	// 매개변수와 반환값
	{
		auto add = [](int a, int b) -> int
			{
				return a + b;
			};

		cout << "add result: " << add(10, 20) << endl;
	}

	// 캡처 리스트 사용 []
	{
		int x = 500;

		auto printx = [x]() // 캡처 리스트 [x]를 사용하면, x의 값을 복사해서 사용함 
			{
				cout << "x = " << x << endl;
			};

		x = 600; // x를 변경해도 람다 내부의 값은 그대로.
		printx();
	}

	// 변수 참조 캡처 &
	{
		int x = 8000;

		auto modify = [&x]() {
			x = 9000;
			};

		cout << "before x: " << x << endl;
		modify();
		cout << "after x: " << x << endl;
	}

	// 모든 변수 캡처 
	// [=] 모든 변수 복사
	// [&] 모든 변수 참조
	{
		int a = 123, b = 456;

		auto copyLamda = [=]() {
			cout << "a: " << a << " b:" << b << endl;
			};

		auto refLamda = [&]() {
			a = 321;
			b = 654;
			};

		copyLamda();
		refLamda();
		cout << "a: " << a << " b:" << b << endl;
		copyLamda();
	}

	return 0;
}