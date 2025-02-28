// 함수 오버라이딩 Function Overriding

// 부모 클래스의 함수를 자식 클래스에서 같은 이름으로 재정의
// 부모 함수는 virtual 키워드로 선언해야 함
// 자식 클래스에서 override 키워드를 추가하면 실수 방지 가능
// 업캐스팅(Animal* ptr = new Dog();)시 동적 바인딩을 통해 자식 클래스의 함수가 호출됨

#include <iostream> 

using namespace std;

class Animal {
public:
	virtual void Speak()
	{
		cout << "동물 소리" << endl;
	}
};

class Dog : public Animal
{
public:
	void Speak() override {
		cout << "멍멍" << endl;
	}
};

int main()
{
	{
		// 업캐스팅: 부모 타입의 포인터(또는 참조자)를 사용하여 자식 클래스의 객체를 가리키는 것
		Animal* animal = new Dog();
		// 동적 바인딩: Animal의 Speak()함수가 virtual로 선언되었기 때문에, 
		// 런타임에서 실제 객체의 타입(Dog)을 보고 Dog의 Speak()가 호출됨.
		animal->Speak();

		// 여기서 댕글링 포인터(Dangling Pointer) 발생
		// 포인터 변수 자체는 그대로 남아 있으며, 
		// 이전에 할당되었던 메모리 주소를 그대로 가지고 있다.
		delete animal;

		// 댕글링 포인터 상태를 방지,
		// 이후 코드에서 실수로 해제된 메모리에 접근하는 것을 방지
		animal = nullptr;
	}

	{
		Animal* animal = new Animal();
		animal->Speak();

		delete animal;
		animal = nullptr;
	}

	return 0;
}

// 정적 바인딩(Static Binding)
// 만약 Speak()에 virtual 키워드가 없다면, 
// 정적 바인딩(Static Binding)이 적용돼서 Animal의 Speak()가 호출됨.