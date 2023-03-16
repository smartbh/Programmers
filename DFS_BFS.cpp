#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    //제일 먼저 티켓들 알파벳 순으로 정렬해줘야함
    sort(tickets.begin(), tickets.end(), greater<vector<string>>());
    unordered_map<string, vector<string>> routes;

    //원소 채우기
    for(int i =0; i< tickets.size(); i++)
    {
        
        routes[tickets[i][0]].push_back(tickets[i][1]); //i번째의 첫번째와 두번째, 즉 출발지와 도착지
    }


    //스택 나타내기
    vector<string> stack = vector<string> {"ICN"}; 
    //시작지역, 빈거로 초기화 해도 되지만 무조건 인천공항 출발이니 ICN으로 초기화

    while(!stack.empty())
    {
        string airport = stack.back();
        if(routes.find(airport) == routes.end() || //표가 없거나
            routes[airport].size() == 0) //표가 있는데 없는 경우
            {
                answer.push_back(airport);
                stack.pop_back();
            }
        else
        {
            stack.push_back(routes[airport].back());
            routes[airport].pop_back();
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<vector<string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};

    for(int i =0; i<solution(tickets).size(); i++)
        cout << solution(tickets)[i] << endl;
    return 0;
}