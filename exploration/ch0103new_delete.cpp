#include <iostream> 

using namespace std;

int main()
{
	{
		int* ptr = new int(10);
		cout << "동적 할당된 값: " << *ptr << endl;

		delete ptr;
		ptr = nullptr;
	}

	{
		// 배열 동적 할당
		int* arr = new int[5];
		for (int i = 0; i < 5; i++)
		{
			arr[i] = (i + 1) * 10;
			cout << arr[i] << " ";
		}
		cout << endl;

		delete[] arr;
		arr = nullptr;
	}

	{
		// delete 후에도 포인터는 그대로 남아 있음
		int* ptr = new int(42);
		delete ptr;

		cout << ptr << endl;  // 여전히 포인터 주소는 출력됨
		cout << *ptr << endl; // 해제된 메모리에 접근하면 예측 불가능한 동작 발생
	}

	return 0;
}

// delete는 포인터가 가리키는 메모리(힙 영역)를 해제함.
// 하지만 포인터 변수 자체를 삭제하거나 초기화하지 않음.
// 따라서 delete 이후에 포인터가 쓰레기 주소를 가리킬 수 있어 위험함.
// 이를 방지하려면 nullptr로 초기화하는 것이 안전한 방법.