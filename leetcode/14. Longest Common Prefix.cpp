class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int flag=0;
        
        for(int i=0; i<strs[0].size(); i++)
        {
            for(int j=0; j<strs.size(); j++)
            {
                if(strs[j][i]!=strs[0][i])
                    flag=1;
            }
            if(flag==1)
                break;
            
            ans+=strs[0][i];
        }
        return ans;
    }
};