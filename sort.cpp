#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(int n1, int n2)
{
    string a = to_string(n1) + to_string(n2);
    string b = to_string(n2) + to_string(n1);

    return a > b;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(),cmp);

    for(int i = 0; i<numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
    }

    return answer;
}

int main()
{
    vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};
    cout << solution(numbers) << endl;
    return 0;
}