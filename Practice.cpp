#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> container;
    string answer = "num";
    for(int i = 0; i<numbers.size(); i++)
    {
        container.push_back(to_string(numbers[i]));
        cout << answer << ", ";
    }
    cout << endl;
    return answer;
}

int main()
{
    vector<int> number = {6, 10, 2};
    cout << solution(number) << endl;
}