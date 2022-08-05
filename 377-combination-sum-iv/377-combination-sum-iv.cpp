class Solution {
public:
    int helper(vector<int>& nums, int tar,unordered_map<int,int>&dp){
        if(tar<0){
            return 0;
        }
        if(tar==0){
            return 1;
        }
        if(dp.count(tar)>0){
            return dp[tar];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=helper(nums,tar-nums[i],dp);
        }
        dp[tar]=ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int,int>dp;
        return helper(nums,target,dp);
    }
};