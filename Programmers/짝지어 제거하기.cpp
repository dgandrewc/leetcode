#include <iostream>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    
    for(int i=0; i<s.size(); i++)
    {
        if(st.empty() || st.top()!=s[i])
        {
            st.push(s[i]);
            continue;
        }
        
        while(!st.empty() && st.top()==s[i])
        {
            i++;
            st.pop();
        }
        i--;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    
    if(st.empty())
        answer=1;
    else
        answer=0;
    return answer;
}