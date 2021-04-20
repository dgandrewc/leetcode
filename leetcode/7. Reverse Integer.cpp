class Solution {
public:
    int reverse(int x) {
        string ans;
        long long ret;
        
        if(x>=0)
        {
            ans=to_string(x);
            std::reverse(ans.begin(), ans.end());
            ret=stol(ans);
        }
        else
        {
            ans=to_string(x);
            std::reverse(ans.begin(), ans.end());
            ret=-stol(ans);
        }
        
        if(ret<=pow(-2, 31) || ret>=pow(2, 31))
            return 0;
        
        return int(ret);
    }
};