#include <string>
#include <vector>

using namespace std;

vector<int> nums;
int sz;
int answer=0;
int tar;

void dfs(int cnt, int val)
{
    if(cnt==sz-1)
    {
        if(val==tar)
            answer++;
    }
    else
    {
        dfs(cnt+1, val+nums[cnt+1]);
        dfs(cnt+1, val-nums[cnt+1]);
    }
}

int solution(vector<int> numbers, int target) {
    nums=numbers;
    sz=numbers.size();
    tar=target;
    
    dfs(0, numbers[0]);
    dfs(0, -numbers[0]);
    
    return answer;
}