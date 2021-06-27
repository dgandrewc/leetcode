#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> t1={1, 2, 3, 4, 5};
    vector<int> t2={2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> t3={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> score;
    int highest=0;
    int s[3]={0, 0, 0};
    
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i]==t1[i%t1.size()])
            s[0]++;
        
        if(answers[i]==t2[i%t2.size()])
            s[1]++;
        
        if(answers[i]==t3[i%t3.size()])
            s[2]++;
        
        highest=max(s[0], s[1]);
        highest=max(highest, s[2]);
    }
    
    for(int i=0; i<3; i++)
        if(s[i]==highest)
            answer.push_back(i+1);
    
    return answer;
}