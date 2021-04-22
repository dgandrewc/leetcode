class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int t=0;
        vector<int> ret;
        for(int i=0; i<nums.size(); i++)
        {
            ret.push_back(nums[i]+t);
            t+=nums[i];
        }
            
        return ret;
    }
};