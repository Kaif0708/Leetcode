class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=((m<n)?m:n) -1;
        double res=1;
        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;
        }
        return (int)res;
    }
    // int countpath(int i,int j,int m,int n,vector<vector<int>>&dp){
    //     if(i==(m-1)&&j==(n-1)) return 1;
    //     if(i>=m||j>=n)return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     else return dp[i][j]=countpath(i+1,j,m,n,dp)+countpath(i,j+1,m,n,dp);
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //     int num=countpath(0,0,m,n,dp);
    //     if(m==1&&n==1){
    //         return num;
    //     }
    //     return dp[0][0];
    // }

};