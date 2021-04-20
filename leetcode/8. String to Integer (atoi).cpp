class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        long long sign=1;
        
        int i;
        for(i=0; i<s.size(); i++)
            if(s[i]!=' ')
                break;
        
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
            i++;

        for(; i<s.size(); i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans=ans+s[i]-'0';
                if(sign*ans>=pow(2, 31))
                    return 2147483647;
                else if(sign*ans<pow(-2, 31))
                   return -2147483648;

                if(s[i+1]>='0' && s[i+1]<='9')
                    ans*=10;
            }
            else
                break;
        }
        
        return sign*ans;
    }
};