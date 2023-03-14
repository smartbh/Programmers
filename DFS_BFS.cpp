#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    //제일 먼저 티켓들 알파벳 순으로 정렬해줘야함
    sort(tickets.begin(), tickets.end(), greater<vector<string>>());
    unordered_map<string, vector<string> > routes;
    return answer;
}

int main()
{
    return 0;
}