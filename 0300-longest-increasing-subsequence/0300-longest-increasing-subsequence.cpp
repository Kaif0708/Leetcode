class Solution {
public:
    // int ans(vector<int>&nums,int n,int ind,int prev_ind,vector<vector<int>>&dp){
    //     if(ind==n) return 0;
    //     if(dp[ind][prev_ind + 1]!=-1) return dp[ind][prev_ind+1];

    //     int not_take=0+ans(nums,n,ind+1,prev_ind,dp);
    //     int take=0;
    //     if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
    //         take=1+ans(nums,n,ind+1,ind,dp);
    //     }
    //     return max(take,not_take);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return ans(nums,n,0,-1,dp);
    // }
    int binarySearch(vector<int>&nums,int target){
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int m=(l+r)>>1;
            if(nums[m]==target) return m;
            else if(nums[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for(auto n:nums){
            if(res.empty()||res.back()<n){
                res.push_back(n);
            }else{
                int idx=binarySearch(res,n);
                res[idx]=n;
            }
        }
        return res.size();
    }
};