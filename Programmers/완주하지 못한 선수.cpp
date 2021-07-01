#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(int i=0; i<completion.size(); i++)
        if(m.find(completion[i])!=m.end())
            m[completion[i]]++;
        else
            m.insert(pair(completion[i], 1));
    
    for(int i=0; i<participant.size(); i++)
    {
        m[participant[i]]--;
        if(m[participant[i]]==-1)
            answer=participant[i];
    }
    return answer;
}