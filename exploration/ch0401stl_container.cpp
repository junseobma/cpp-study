// STL 컨테이너 정리 (vector, map, set, queue, stack)

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
	// vector (동적 배열)
	//  - 일반적인 배열보다 크기 조정이 필요할 때
	//  - 중간 삽입, 삭제가 적고, 맨 뒤에 추가, 삭제(push_back, pop_back)가 많을 때
	//-------------------------------
	{
		cout << "----- vector -----" << endl;

		vector<int> v = { 1,2,3,4,5 };

		// 마지막에 추가
		v.push_back(6);
		cout << v[v.size() - 1] << endl;

		// 마지막 요소 제거
		v.pop_back();
		cout << v[v.size() - 1] << endl;

		// 출력
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;

		// 값 섞기
		swap(v[0], v[1]);
		swap(v[2], v[3]);
		for (int num : v)
			cout << num << " ";
		cout << endl;

		// 오름차순 정렬
		sort(v.begin(), v.end());
		for (int num : v)
			cout << num << " ";
		cout << endl;

		// 내림차순 정렬
		sort(v.rbegin(), v.rend());
		for (int num : v)
			cout << num << " ";
		cout << endl;

		// find 주어진 범위에서 특정 값을 찾아서 해당 위치(이터레이터)를 반환
		int searchVal = 5;
		if (find(v.begin(), v.end(), searchVal) != v.end())
		{
			cout << searchVal << " is exist" << endl;

			cout << *find(v.begin(), v.end(), searchVal) << endl;
		}
	}

	//-------------------------------
	// map (Key-Value 구조, 정렬됨)
	//  - 정렬된 Key-Value 형태의 데이터 관리할 때
	//  - 이름 - 점수 저장 같은 경우
	//-------------------------------
	{
		cout << endl << "----- map -----" << endl;

		map<string, int> scores;
		scores["Chulsoo"] = 10;
		scores["Younghee"] = 20;
		scores["Maenggu"] = 30;
		scores["Jjanggu"] = 40;

		cout << scores["Chulsoo"] << endl;

		// map에서 특정 키(key)가 존재하는지 확인하는 함수
		if (scores.count("Younghee"))
		{
			cout << "Younghee is exist" << endl;
		}

		// 순회 출력
		// ab'C'defghi'J'kl'M'nopqrstuvwx'Y'z 정렬된것 확인
		for (pair<string, int> data : scores)
		{
			cout << "first: " << data.first << "  second: " << data.second << endl;
		}

		// 순회 auto 사용
		for (auto it : scores)
		{
			cout << it.first << ": " << it.second << endl;
		}
	}

	//-------------------------------
	// unordered_map (Key-Value, 해시 기반)
	//  - map보다 빠른 검색이 필요할 때
	//  - 데이터 정렬이 필요 없을 때
	//-------------------------------
	{
		cout << endl << "----- unordered_map -----" << endl;

		unordered_map<string, int> fruits;
		fruits["apple"] = 100;
		fruits["elderberry"] = 500;
		fruits["fig"] = 700;
		fruits["grape"] = 600;
		fruits["cherry"] = 300;
		fruits["dragonfruit"] = 400;
		fruits["banana"] = 200;

		for (auto it : fruits)
			cout << it.first << " " << it.second << endl;
	}

	//-------------------------------
	// set (중복 없는 정렬된 데이터)
	//  - 중복을 자동으로 제거해야 할 때
	//  - 데이터를 자동 정렬해야 할 때
	//-------------------------------
	{
		cout << endl << "----- set -----" << endl;

		set<int> s;
		s.insert(30);
		s.insert(10);
		s.insert(20);
		s.insert(10); // 중복 삽입 불가능
		s.insert(10); // 중복 삽입 불가능

		// 10이 중복됐으므로 중복 없이 사이즈는 3
		cout << s.size() << endl;

		// 30 10 20 10 10 이 아니라 
		// 중복 없이 10 20 30 으로 자동 정렬
		cout << *s.begin() << endl; // 10 출력

		// 순회 출력
		for (auto it : s)
			cout << it << " ";
		cout << endl;

		// 탐색
		if (s.find(20) != s.end())
		{
			cout << "20 존재함" << endl;
		}
	}

	//-------------------------------
	// queue (FIFO, 선입선출)
	//  - 먼저 들어온 게 먼저 나가는 구조가 필요할 때, BFS 탐색 등
	//-------------------------------
	{
		cout << endl << "----- queue -----" << endl;

		queue<int> q;
		q.push(100);
		q.push(300);
		q.push(500);
		q.push(200);
		q.push(400);

		cout << q.front() << endl;
		cout << q.back() << endl;

		q.pop(); // 선입선출

		cout << q.front() << endl;
		cout << q.back() << endl;
	}

	//-------------------------------
	// stack (LIFO, 후입선출)
	//  - 괄호 검사 같은 문제에서 사용됨
	//  - 백트래킹, DFS 탐색 등
	//-------------------------------
	{
		cout << endl << "----- stack -----" << endl;

		stack<int> st;
		st.push(10);
		st.push(20);
		st.push(30);

		cout << st.top() << endl;

		st.pop();

		cout << st.top() << endl;
	}

	return 0;
}