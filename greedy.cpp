#include <iostream>
#include <string>
#include <vector>

using namespace std;

//greedy algorithm, 탐욕법
//알고리즘의 각 단계에서 그 순간에 최적이라고 생각되는 것을 선택
//매 단계의 선택이 마지막 해답의 최적성을 해치지 않을때

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> u(n + 2,1); //전부 1로 초기화 전부 가지고 있다고 가정하는것
    for(int i = 0; i< reserve.size(); i++)
    {
        u[reserve[i]]++;  //예비 운동복 가지고 있는 친구들 갯수 하나씩 추가
    }
    //도둑당한 친구들 운동복 갯수 한개씩 까기
    for(int i = 0; i<lost.size(); i++)
    {
        u[lost[i]]--;
    }
    //벡터 u의 갯수들이 이제 정해졌을것
    //앞과 뒤에 운동복이 없으면 빌려주는 로직을 짜야한다.
    for(int i = 1; i<=n; i++)
    {
        //앞 번호의 친구가 없을때
        if(u[i-1] == 0 && u[i] ==2)
            u[i-1] = u[i] = 1; //둘다 한개로 만들어버리기~
        //뒷 번호의 친구가 없을때
        else if(u[i] == 2 && u[i+1] == 0)
            u[i] = u[i+1] = 1;
    }

    for(int i =1; i<=n; i++)
    {
        if(u[i] > 0)
            answer++;
    }


    
    return answer;
}

int main()
{
    int n = 5;
    vector<int> lost = {2,4};
    vector<int> reserve = {1,3,5};

    cout << solution(n,lost,reserve) << endl;
}