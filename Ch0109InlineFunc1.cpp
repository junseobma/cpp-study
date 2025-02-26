// 인라인(inline) 함수

// 매크로 함수의 
// 장점: 일반적인 함수에 비해서 실행 속도의 이점이 있다. 
// 단점: 복잡한 함수를 매크로의 형태로 정의하는데 한계가 있다. 

#include <iostream> 
#define SQUARE(x) ((x)*(x))

int main()
{
	std::cout << SQUARE(5) << std::endl;
	//std::cout << ((5)*(5)) << std::endl; // 전처리 과정 후

	return 0;
}

// 매크로 함수는 정의가 복잡하니, 일반 함수처럼 정의가 가능하면 좋겠다!