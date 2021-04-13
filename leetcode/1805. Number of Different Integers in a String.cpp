class Solution {
public:
    int numDifferentIntegers(string word) {
        int ans=0;
        set<string> s;
        for(int i=0; i<word.size(); i++)
        {
            string temp="";
            int zero_flag=0;
            if(word[i]>='0' && word[i]<='9')
            {
                while(word[i]=='0')
                    i++;
                for(;word[i]>='0' && word[i]<='9'; i++)
                {
                    zero_flag=1;
                    temp+=word[i];
                }
                if(zero_flag==0)
                    s.insert("0");
            }
            s.insert(temp);
        }
        s.insert("");
        return s.size()-1;
    }
};