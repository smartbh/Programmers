#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

//greedy algorithm, 탐욕법
//알고리즘의 각 단계에서 그 순간에 최적이라고 생각되는 것을 선택
//매 단계의 선택이 마지막 해답의 최적성을 해치지 않을때


// O(n)의 효율, for문을 쓰는법, N(학생의 수)와 체육복을 가져온 학생의 수가 비슷할때 효율적
/*
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
*/

// 만약 N(학생의수)가 엄청나게 큰데, 정작 체육복을 가져온 학생의 수가 적으면 낭비다
//set과 map으로 새로 짜줘야 함
int solution(int n, vector<int> lost, vector<int> reserve)
{
    unordered_set<int> l(lost.begin(),lost.end()); //원소들을 lost라는 벡터에 들어있는 원소로 초기화
    set<int> r; //체육복을 여벌로 가져온 학생들
    unordered_set<int> inter; //체육복을 가져왔는데 도난도 당한 학생들, L과 R의 교집합
    int answer;

    for(auto& x: reserve)
    {
        if(l.find(x) == l.end()) //l안에 x란 원소가 없으면 -> 도난 당하지 않음, 빌려줄수 있는 학생
            r.insert(x);
        else
            inter.insert(x);
    }

    for(auto& x:inter) l.erase(x); //
    for(auto& x : r)
    {
        if(l.find(x-1) != l.end()) l.erase(x-1);//체육복을 빌려야 하는 학생이면
        else if(l.find(x-1) != l.end() ) l.erase(x+1);
    }

    return n-l.size();
}

int main()
{
    int n = 5;
    vector<int> lost = {2,4};
    vector<int> reserve = {1,3,5};

    cout << solution(n,lost,reserve) << endl;
}