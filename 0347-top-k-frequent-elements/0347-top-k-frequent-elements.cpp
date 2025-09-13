class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>>heap;
        for(pair<int,int> entry: mpp){
            heap.push({entry.second,entry.first});
        }
        vector<int> ans;
        while(k){
            ans.push_back(heap.top().second);
            heap.pop();
            k--;
        }
        return ans;

    }
};