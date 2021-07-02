#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    char arr[3]={'1', '2', '4'};
    
    int i=3;
    for(;n>0; n/=3)
    {
        n-=1;
        answer+=arr[n%3];
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}