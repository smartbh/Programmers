#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;


//k 숫자를 뺄 횟수
string solution(string number, int k) {
    //vector<int> num = to_integer<string>(number);
    string answer = "";
    
    for(int i = 0; i<number.size(); i++)
    {
        while(!answer.empty() && answer.back() < number[i] && k > 0)
        { 
            //한글자 숫자들을 비교할땐 정수로 변환해서 비교하지 않아도됨
            answer.pop_back();
            k--;
        }
        if(k == 0)
        {
            answer+=number.substr(i,number.length()-i);
            break;
        }
        answer.push_back(number[i]);
            
    }

    
    return answer.substr(0,answer.length()-k);
}

int main()
{
    string number = "1924";
    int k = 2;

    cout << solution(number,k);
}