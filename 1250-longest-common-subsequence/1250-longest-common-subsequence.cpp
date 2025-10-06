class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int>dp(n+1,0);
        int longest=0;
        for(char c:text2){
            int currLength=0;
            for(int i=0;i<n;i++){
                if(currLength<dp[i]){
                    currLength=dp[i];
                }else if(c==text1[i]){
                    dp[i]=currLength+1;
                    longest=max(longest,dp[i]);

                }
            }
        }
        return longest;
        
    }
};