class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        int maxLen=0;
        for(const string& word:wordDict){
            maxLen=max(maxLen,(int)word.size());
        }
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=max(i-maxLen-1,0);j--){
                if(dp[j]&& find(wordDict.begin(),wordDict.end(),s.substr(j,i-j) )!=wordDict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
            
    }
};