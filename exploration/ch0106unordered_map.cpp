// map 
// 빠른 해시맵

// map(정렬된 키 - 값 구조, 이진 탐색 트리 기반)
// 내부적으로 Red - Black Tree(레드-블랙 트리) 자료구조를 사용
// Key가 항상 정렬된 상태로 유지됨
// 탐색 속도 : O(log N)
// 키를 정렬된 상태로 유지해야 하는 경우 유리함
   
// unordered_map(정렬되지 않은 해시맵)
// 내부적으로 해시 테이블을 사용
// 키가 정렬되지 않음 for (auto x : umap) 하면 순서가 일정하지 않음
// 탐색 속도 : O(1) (이론적으로 더 빠름, 해시 충돌이 많으면 O(N)까지 가능)
// 빠른 검색이 필요한 경우 유리
   
// map 키를 정렬된 상태로 유지해야 할 때 사용
// unordered_map 빠른 탐색이 필요할 때 사용(일반적으로 더 빠름)

#include <iostream> 
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<string, int> data;
	data["apple"] = 5;
	data["cherry"] = 2;
	data["banana"] = 10;

	cout << data["apple"] << endl;
	cout << data["cherry"] << endl;
	cout << data["banana"] << endl;
	cout << endl;

	// pair를 사용한 순회
	for (pair<const string, int> i : data) 
	{
		cout << i.first << " : " << i.second << endl;
	}
	cout << endl;

	// auto를 사용한 순회
	for (auto i : data)
	{
		cout << i.first << " : " << i.second << endl;
	}
	cout << endl;

	return 0;
}