#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
key에 의해서 원소에 접근하는 시간
map : O(log N) n = 맵 원소의 갯수
unordered_map = O(N)

라이브러리 내부 구현 차이
map : binary search tree 이중탐색트리 

unordered_map : hash table 해시 테이블
*/

using namespace std;

string solution(vector<string> participant, vector<string> completion) {    
    //참가 participant, 완료 completion
    unordered_map<string, int> complete;
    string answer = "";

    for(auto& i : participant) 
    {
        complete[i]++;
    }

    for(auto& i : completion) 
    {
        complete[i]--;
    }

    for(auto& i : complete)
    {
        if( i.second > 0)
        {
            answer = i.first;
            break;
        }
    }

    
    return answer;
}

int main()
{
    vector<string> participant = {"mislav", "stanko", "mislav", "ana"};
    vector<string> completion = {"stanko", "ana", "mislav"};

    cout << solution(participant, completion) << endl;
    return 0;
}