class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int>counter;
        counter[0]=1;
        for(int n:nums){
            unordered_map<int,int>temp;
            for(const auto&[total,cnt]:counter){
                temp[total+n]+=cnt;
                temp[total-n]+=cnt;
            }
            counter=temp;
        }
        return counter[target];


    }
};