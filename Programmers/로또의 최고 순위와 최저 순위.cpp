#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int ans=0;
    int joker=0;
    
    for(int i=0; i<lottos.size(); i++)
        if(lottos[i]==0)
            joker++;
    
    for(int i=0; i<lottos.size(); i++)
        for(int j=0; j<win_nums.size(); j++)
            if(lottos[i]==win_nums[j])
                ans++;
    
    int highest=ans+joker;
    int lowest=ans;
    
    if(highest!=0)
        answer.push_back(7-highest);
    else
        answer.push_back(6);
    
    if(lowest!=0)
        answer.push_back(7-lowest);
    else
        answer.push_back(6);
    return answer;
}