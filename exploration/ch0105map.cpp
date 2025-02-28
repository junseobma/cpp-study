// map 
// key-value 구조

#include <iostream> 
#include <map>

using namespace std;

int main()
{
	map<string, int> score;
	score["Alice"] = 90;
	score["Bob"] = 80;

	cout << score["Alice"] << endl;
	cout << score["Bob"] << endl;

	return 0;
}