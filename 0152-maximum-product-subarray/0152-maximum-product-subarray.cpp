class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd=nums[0];
        int pre=1,suf=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suf==0) suf=1;
            pre*=nums[i];
            suf*=nums[n-i-1];
            maxProd=max(maxProd,max(pre,suf));
        }
        return maxProd;
        
    }
};