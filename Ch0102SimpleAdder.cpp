#include <iostream> // 표준 헤더파일의 선언에서는 확장자를 생략하기로 약속되어 있다. 

// C++에서는 데이터의 입출력에 별도의 포맷을 지정할 필요가 없다.
int main()
{
	int val1;
	std::cout << "첫 숫자 입력: ";
	std::cin >> val1; 

	int val2;
	std::cout << "둘 숫자 입력: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "덧셈결과: " << result << std::endl;

	return 0;
}
