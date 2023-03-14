#include <iostream>
#include <unordered_set>

using namespace std;

int solution(int N, int number)
{
    //return 최대 8, 그걸 넘기면 -1 리턴
    //최소 몇번을 사용해서 만들수 있는가를 찾기 원하는것
    int answer = -1;

    unordered_set<int> s[8]; //중복을 허용하지 않는 집합이 필요하기때문에 set 사용
    int base = 0;

    for(int i = 0; i<8; i++)
    {
        base = 10 * base +1;
        s[i].insert(base*N); //5, 55, 555 등 모두 사용해서 만든 수들을 미리 계산
    }

    for(int i = 1; i<8; i++)
    {
        for(int j = 0; j<i; j++)
        {
            //ex i = 3, j = 0,1,2
            for(auto& op1 : s[j])
                for(auto& op2 : s[i-j-1])
                    {
                        s[i].insert(op1 + op2);
                        s[i].insert(op1 - op2);
                        s[i].insert(op1 * op2);
                        if(op2 != 0)
                            s[i].insert(op1 / op2);
                    }
        }
        if(s[i].count(number) > 0)
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}


//동적 계획법의 대표적인 문제로 가방문제가 있음
//무게 제한이 있는 가방에 각각 무게가 다른 물건을을 최대한 많이 담게하기

int main()
{
    cout << solution(12,5) << endl;
}