#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    stack<int> s;
    stack<int> p;
    int time=0;
    
    for(int i=progresses.size()-1; i>=0; i--)
    {
        s.push(progresses[i]);
        p.push(speeds[i]);
    }
    
    while(!s.empty())
    {
        int cnt=0;
        
        while(!s.empty() && s.top()+p.top()*time>=100)
        {
            s.pop();
            p.pop();
            cnt++;
        }
        time++;
        
        if(cnt!=0)
            answer.push_back(cnt);
            
    }
    
    return answer;
}