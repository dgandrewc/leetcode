class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int flag=0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums.size(); j++)
            {
                if(i==j)
                    continue;
                if(nums[i]+nums[j]==target)
                {
                    flag=1;
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
            if(flag)
                break;
        }
        return ans;
    }
};