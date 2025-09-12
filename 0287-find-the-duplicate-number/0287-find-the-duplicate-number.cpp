class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //consider the array as linklist and value at an index points to another node, so for duplicate it forms     a cycle
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};