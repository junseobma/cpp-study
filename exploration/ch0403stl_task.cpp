// 코딩 문제

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
	// -------------------------------
	// 문제1
	// 사용자로부터 정수 N개를 입력받아, 
	// 오름차순 정렬한 후 중복을 제거하여 출력하는 프로그램을 작성하시오.
	// -------------------------------
	{
		cout << endl << "----- Task 1 -----" << endl;

		// 해결1
		vector<int> v = { 10, 20, 10, 30, 20, 40, 50, 10 };

		sort(v.begin(), v.end());

		//unique(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		for (auto it : v)
			cout << it << " ";
		cout << endl;

		// 해결2
		set<int> s = { 10, 20, 10, 30, 20, 40, 50, 10 };
		for (auto it : s)
			cout << it << " ";
		cout << endl;

		// 데이터가 많으면 vector + sort + unique + erase가 더 빠를 수도 있음
		// 코드가 깔끔한 건 set 방식
	}

	// -------------------------------
	// 문제2
	// 사용자로부터 단어를 여러 개 입력받아, 
	// 각 단어가 몇 번 등장했는지 출력하는 프로그램을 작성하시오.
	// -------------------------------
	{
		cout << endl << "----- Task 2 -----" << endl;

		vector<string> v = { "apple", "banana", "apple", "orange", "banana", "apple" };

		map<string, int> m;
		for (auto it : v)
		{
			m[it]++;
		}

		for (auto it : m)
		{
			cout << it.first << " " << it.second << endl;
		}

		// map의 삽입 및 조회 연산은 O(log N)
		// 총 N개의 단어를 삽입하고 출력하므로 O(N log N)
		// 만약 단어 순서가 중요하지 않다면, unordered_map을 사용 O(1)
	}

	// -------------------------------
	// 문제3
	// 사용자로부터 정수 N개를 입력받고, 
	// 특정 값 X가 있는지 빠르게 찾아 출력하는 프로그램을 작성하시오.
	// -------------------------------
	{
		cout << endl << "----- Task 3 -----" << endl;

		vector<int> v = { 10,20,30,40,50 };
		int num = 30;

		sort(v.begin(), v.end());
		if (binary_search(v.begin(), v.end(), num))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}

		// sort(v.begin(), v.end()) 
		// 정렬을 먼저 수행해야 binary_search() 사용 가능, O(N log N)

		// binary_search(v.begin(), v.end(), num) 
		// O(log N) 시간복잡도로 탐색

		// 전체: O(N log N)
	}

	// -------------------------------
	// 문제4
	// 주어진 문자열이 올바른 괄호 문자열인지 판별하는 프로그램을 작성하시오.
	// 괄호는 (), {}, [] 만 주어진다.
	// -------------------------------
	{
		cout << endl << "----- Task 4 -----" << endl;

		vector<char> v = { '{', '[', '(', ')', ']','}' };
		//vector<char> v = { '{', '[', '(', ']', ')','}' };

		stack<char> st;
		if (st.empty())
		{
			if (v[0] == '{' || v[0] == '[' || v[0] == '(')
			{
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i] == '{' || v[i] == '[' || v[i] == '(')
					{
						st.push(v[i]);
					}
					else
					{
						if (v[i]=='}' && st.top() == '{')
						{
							st.pop();
						}
						else if (v[i] == ']' && st.top() == '[')
						{
							st.pop();
						}
						else if (v[i] == ')' && st.top() == '(')
						{
							st.pop();
						}
						else
						{
							break;
						}
					}
				}

				if (st.empty())
				{
					cout << "Yes" << endl;
				}
				else
				{
					cout << "No" << endl;
				}
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}

	// -------------------------------
	// 문제5
	// 정렬된 카드 묶음에서 주어진 숫자보다 큰 가장 작은 수를 찾아라.
	// -------------------------------
	{
		cout << endl << "----- Task 5 -----" << endl;

		vector<int> v = { 10, 20, 30, 40, 50 };
		//vector<int> v = { 60, 20, 80, 10, 70, 20, 40, 90 };
		int num = 25;

		set<int> s;
		for (auto it : v)
			s.insert(it);

		cout << *upper_bound(s.begin(), s.end(), num) << endl;
	}
	{
		// 개선된 코드

		vector<int> v = { 10, 20, 30, 40, 50 };
		// vector<int> v = { 60, 20, 80, 10, 70, 20, 40, 90 };
		int num = 25;

		set<int> s(v.begin(), v.end()); // 자동 정렬 & 중복 제거

		auto it = upper_bound(s.begin(), s.end(), num);

		// 예외처리, 못 찾았을 경우 end()가 반환되므로
		if (it != s.end()) {
			cout << *it << endl; 
		}
		else {
			cout << "No result" << endl;
		}
	}

	return 0;
}