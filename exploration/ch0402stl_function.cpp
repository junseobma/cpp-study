// STL 함수 정리 (sort(), binary_search(), lower_bound(), upper_bound(), next_permutation())

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	//-------------------------------
	// sort() 정렬
	//-------------------------------
	{
		cout << "----- sort() -----" << endl;

		vector<int> v = { 6, 2, 3, 9, 1, 4, 5, 7, 2, 5, 8 };

		sort(v.begin(), v.end());
		for (auto it : v)
			cout << it << " ";
		cout << endl;

		sort(v.rbegin(), v.rend());
		for (auto it : v)
			cout << it << " ";
		cout << endl;
	}

	// 커스텀 정렬
	{
		vector<int> v = { 2, 5, 7, 6, 2, 3, 5, 4, 1, 3 };

		// greater<int>()는 STL에 정의된 
		// 내림차순으로 정렬할 때 사용하는 비교 함수 객체(Functor)
		sort(v.begin(), v.end(), greater<int>());

		sort(v.rbegin(), v.rend());
		for (auto it : v)
			cout << it << " ";
		cout << endl;
	}

	// 구조체/객체 정렬
	{
		struct Person {
			string name;
			int age;
		};

		vector<Person> people = { {"Alice", 25}, {"Bob", 20}, {"Chulsoo", 15}, {"Dongtak", 30} };

		// 세 번째 매개변수로 비교 함수를 람다(lambda)로 전달
		// -> 반환형(반환 타입)을 생략할 수 있음
		// 컴파일러가 반환 타입을 자동으로 추론 할 수 있기 때문
		sort(people.begin(), people.end(), [](Person a, Person b) {
			return a.age < b.age; // 나이 기준 오름차순 정렬
			});

		for (auto it : people)
			cout << it.name << " " << it.age << endl;
	}

	//-------------------------------
	// binary_search() 이진 탐색
	//  - 배열이 정렬된 상태에서 빠르게 탐색할 때 (O(log N))
	//-------------------------------
	{
		cout << endl << "----- binary_search() -----" << endl;

		vector<int> v = { 2, 3, 9, 5, 2, 5, 8, 1, 6, 7, 4 };

		if (binary_search(v.begin(), v.end(), 8))
		{
			cout << "정렬전: 5 존재함" << endl;
		}

		sort(v.begin(), v.end());

		if (binary_search(v.begin(), v.end(), 8))
		{
			cout << "정렬후: 5 존재함" << endl;
		}
	}

	//-------------------------------
	// lower_bound(), upper_bound()
	//  - 정렬된 배열에서 특정 값 이상/초과를 찾을 때 (O(log N))
	//-------------------------------
	{
		cout << endl << "----- lower_bound() & upper_bound() -----" << endl;

		vector<int> v = { 0, 1, 2, 3, 4, 5 };

		auto lb = lower_bound(v.begin(), v.end(), 3);
		auto ub = upper_bound(v.begin(), v.end(), 3);

		cout << *lb << endl;
		cout << *ub << endl;
	}

	//-------------------------------
	// next_permutation() 순열
	//  - 순열을 구하는 문제에서 유용함
	//-------------------------------
	{
		cout << endl << "----- next_permutation() -----" << endl;

		vector<int> v = { 1, 2, 3 };
		do {
			for (int num : v) cout << num << " ";
			cout << endl;
		} while (next_permutation(v.begin(), v.end()));
	}

	return 0;
}