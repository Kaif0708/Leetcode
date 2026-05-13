class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int ans=nums[0];
        // int maxsum=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     maxsum=max(nums[i],maxsum+nums[i]);
        //     ans=max(ans,maxsum);
        // }
        // return ans;
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>ans){
                ans=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
};