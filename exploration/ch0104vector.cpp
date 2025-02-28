// vector 
// 동적 배열

#include <iostream> 
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,5 };
	v.push_back(6);

	{
		for (int num : v)
		{
			num = num * 2;
			cout << num << " ";
		}
		cout << endl;

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	cout << endl;

	{
		for (int& num : v)
		{
			num = num * 2;
			cout << num << " ";
		}
		cout << endl;

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	return 0;
}

// for (int num : v)의 문제점
// 값 복사이기 때문에 원본이 변경되지 않음
// 해결 방법: 참조(&) 사용
// int& num에서 num이 v의 요소 자체를 가리킴 (복사가 아니라 직접 참조)
// 따라서 num *= 2; 를 하면 v의 원본이 변경됨.