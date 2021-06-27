#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    for(int i=0; i<new_id.size(); i++)
        new_id[i]=tolower(new_id[i]);
    
    for(int i=0; i<new_id.size(); i++)
    {
        if((new_id[i]<='z' && new_id[i]>='a') || (new_id[i]<='9' && new_id[i]>='0') || new_id[i]=='-' || new_id[i]=='_' || new_id[i]=='.')
            continue;
        else
        {
            new_id.erase(i, 1);
            i--;
        }
    }
    
    for(int i=1; i<new_id.size(); i++)
        if(new_id[i-1]=='.' && new_id[i]=='.')
        {
            new_id.erase(i-1, 1);
            i--;
        }
    
    if(new_id[0]=='.')
        new_id.erase(0, 1);
    
    if(new_id[new_id.size()-1]=='.')
        new_id.erase(new_id.size()-1, 1);
    
    if(new_id=="")
        new_id="a";
    
    if(new_id.size()>=16)
        new_id=new_id.substr(0, 15);
    
    if(new_id[new_id.size()-1]=='.')
        new_id.erase(new_id.size()-1, 1);
    
    if(new_id.size()<=2)
        while(new_id.size()<=2)
            new_id=new_id+new_id[new_id.size()-1];
    
    return new_id;
}