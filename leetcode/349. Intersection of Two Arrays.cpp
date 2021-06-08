class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(1001, 0);
        vector<int> ret;
        
        for(int i=0; i<nums1.size(); i++)
            if(ans[nums1[i]]==0)
                ans[nums1[i]]=1;
        
        for(int i=0; i<nums2.size(); i++)
        {
            if(ans[nums2[i]]==1)
            {
                ret.push_back(nums2[i]);
                ans[nums2[i]]=0;
            }
        }
        return ret;
    }
};