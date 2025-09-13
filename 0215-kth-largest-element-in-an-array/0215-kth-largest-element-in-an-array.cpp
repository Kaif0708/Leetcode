class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>maxheap;
        for(int i=0;i<n;i++){
            maxheap.push(nums[i]);
        }
        int f=k-1;
        while(f){
            maxheap.pop();
            f--;
        }
        return maxheap.top();
    }
};