class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // map<int,int>mpp;
        // int n=nums.size();
        // int mini=int(n/3)+1;
        // vector<int>ans;
        
        // for(int i=0;i<n;i++){
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]]==mini){
        //         ans.push_back(nums[i]);
        //     }
        //     if(ans.size()==2) break;
        // }
        // return ans;

        //optime using boyre moore voting algo( cnt and element logic)

        int cnt1=0,cnt2=0;
        int el1=INT_MIN,el2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else{
                cnt1--,cnt2--;
            }
        }
        vector<int>ans;
        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1) cnt1++;
            if(nums[i]==el2) cnt2++;
        }
        int n=nums.size();
        int mini=int(n/3)+1;
        if(cnt1 >=mini) ans.push_back(el1);
        if(cnt2>=mini) ans.push_back(el2);
         return ans;
        
    }
};