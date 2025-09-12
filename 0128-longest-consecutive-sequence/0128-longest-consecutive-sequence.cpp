class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
       if(n==0) return 0;
       unordered_set<int>st;
       for(int i=0;i<n;i++){
        st.insert(nums[i]);
       }
       int longest=0;
       for(auto it: st){
        //it is starting
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            //to get the end of consecutive series.
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest=max(cnt,longest);
        }
       }
       return longest;
    }
};