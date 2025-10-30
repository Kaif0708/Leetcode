class Solution {
public:
    int trap(vector<int>& height) {
        // int n=height.size();
        // int water=0;
        // int premax[n],suffmax[n];
        // premax[0]=height[0];
        // for(int i=1;i<n;i++){
        //     premax[i]=max(premax[i-1],height[i]);
        // }
        // suffmax[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--){
        //     suffmax[i]=max(suffmax[i+1],height[i]);
        // }
        // for(int i=0;i<n;i++){
        //     // int j=i;
        //     // int leftmax=0,rightmax=0;
        //     // while(j>=0){
        //     //     leftmax=max(leftmax,height[j]);
        //     //     j--;
        //     // }
        //     // j=i;
        //     // while(j<n){
        //     //     rightmax=max(rightmax,height[j]);
        //     //     j++;
        //     // }
        //     water+=min(premax[i],suffmax[i])-height[i];
        // }
        // return water;
        int n=height.size();
        int left=0,right=n-1;
        int maxleft=0,maxright=0;
        int water=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>maxleft){
                    maxleft=height[left];
                }else{
                    water+=maxleft-height[left];
        
                }
                left++;
            }else{
                if(height[right]>maxright){
                    maxright=height[right];
                }else{
                    water+=maxright-height[right];
                    
                }
                right--;
            }
        }
        return water;
    }
};