#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int c=0; c<commands.size(); c++)
    {
        vector<int> arr;
        
        int i=commands[c][0];
        int j=commands[c][1];
        int k=commands[c][2];
        
        for(int a=i-1; a<j; a++)
            arr.push_back(array[a]);
        
        sort(arr.begin(), arr.end());
        answer.push_back(arr[k-1]);
    }
    return answer;
}