// 스마트 포인터 (std::unique_ptr, std::shared_ptr)

// std::unique_ptr (단독 소유)
// new를 직접 사용하지 않고 make_unique<T>()로 객체 생성
// delete를 직접 호출할 필요 없음(스코프에서 벗어나면 자동 삭제)
// 복사가 불가능, 하나의 포인터만 객체를 소유 가능 (소유권 이동은 std::move() 사용)

// std::shared_ptr(참조 카운팅)
// 여러 개의 포인터가 객체를 공유 가능
// 참조 카운트가 0이 되면(마지막 shared_ptr이 소멸될 때) 자동으로 객체 삭제됨  
// use_count()를 통해 참조 카운트를 확인 가능
// 순환 참조 문제가 발생할 수 있음 → 이를 해결하려면 weak_ptr 사용

#include <iostream> 
#include <memory>

using namespace std;

class Dog {
public:
	Dog() { cout << "Dog 생성됨" << endl; }
	~Dog() { cout << "Dog 소멸됨" << endl; }
	void Bark() { cout << "멍멍!" << endl; }
};

int main()
{
	{
		unique_ptr<Dog> dog = make_unique<Dog>();
		dog->Bark();

		// 오류 발생, unique_ptr은 복사가 불가능
		//unique_ptr<Dog> dog2 = dog; 
	}

	cout << endl;

	{
		shared_ptr<Dog> dog1 = make_unique<Dog>();
		shared_ptr<Dog> dog2 = dog1;

		cout << "참조 카운트: " << dog1.use_count() << endl;

		dog2.reset();
		cout << "참조 카운트: " << dog1.use_count() << endl;
	}

	return 0;
}
