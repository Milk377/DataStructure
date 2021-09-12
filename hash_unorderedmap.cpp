#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

	string answer = "";

	unordered_map<string, int> m1;

	// "key로 value 에 접근. " 따라서 m1[i] 로 해도 되는 것.
	// c++ stl 은 미정의시 기본값을 설정해둠
	// int 의 기본값은 0 이기 때문에 ++ 하면 1이 되는 것.

	for (auto& i : participant) { m1[i]++; }
	for (auto& i : completion) { m1[i]--; }

	for (auto& i : m1) { if (i.second == 1) answer = m1[i]; }

	return answer;

}