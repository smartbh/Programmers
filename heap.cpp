#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/*
//섞은 음식의 스코빌 지수 = 가장 맵지않은 음식의 스코빌 지수 + 두번째로 맵지 않은 음식의 스코빌 지수 * 2
int solution(vector<int> scoville, int K) { //스코빌, k = 목표 스코빌 지수
    int newScoville = 0;
    int num = scoville.size();
    int count = 0;

    for(int i = 0; i < num; i++)
    {
        if(scoville.size() == 1 && scoville[0] < K)
            return -1;
        else if(scoville.size() == 1 && scoville[0] >= K)
            return count;
        if(scoville[0] >= K)
            return count;
        else{
            newScoville = scoville[0] + scoville[1] * 2;
            scoville.push_back(newScoville);
            sort(scoville.begin(),scoville.end()); //정렬
            //정렬후 맨처음, 두번째 원소 없애기
            scoville.erase(scoville.begin()+1);
            scoville.erase(scoville.begin());
            count++;
        }
    }

    return count;
}
*/

//다 성공했으나 효율성 통과를 못함
//큐를 이용한 힙 정렬로 돌파해야한다.

//힙을 사용하는게 제일 최적화
//max heap, min heap을 해야

int solution(vector<int> scoville, int K) { //스코빌, k = 목표 스코빌 지수
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q; //비어있는 큐 생성

    for(auto& a : scoville) q.push(a); //

    while(1)
    {
        int min = q.top();
        q.pop();
        
        if(min >= K) break;
        
        else if(q.empty()) return -1;
        
        int min2 = q.top();
        q.pop();
        q.push((min + min2*2));
        answer++;
    }

    return answer;
}

//최대최소 빨리 꺼내야할때 -> 힙, 프라이어티 큐를 써야한다.

int main()
{
    vector<int> scoville = {1,2,3,9,10,11};
    int k = 7;

    cout << solution(scoville, k) << endl;
    //2가 나와야함
    return 0;
}