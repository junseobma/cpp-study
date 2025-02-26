// 인라인(inline) 함수

// 매크로를 이용한 함수의 인라인화는 전처리기에 의해서 처리되지만,
// 키워드 inline을 이용한 함수의 인라인화는 컴파일러에 의해서 처리된다. 
// 따라서 컴파일러는 함수의 인라인화가 오히려 성능에 해가 된다면 이 키워드를 무시해버리기도 한다. 
// 또한 컴파일러는 필요한 경우 일부 함수를 임의로 인라인 처리하기도 한다. 

#include <iostream> 

inline int SQUARE(int x)
{
	return x * x;
}

int main()
{
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(10) << std::endl;

	std::cout << SQUARE(3.14) << std::endl;

	return 0;
}

// 위의 인라인 함수는 자료형에 의존적인 상태이기 때문에 매크로 함수의 장점을 완전히 대체하지 못했다.
// 템플릿을 이용하면 자료형에 의존적이지 않은 함수가 된다. 

//template <typename T>
//inline T SQUARE(T x)
//{
//	return x * x;
//}