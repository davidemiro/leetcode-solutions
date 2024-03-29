class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = text1.size();
        int M = text2.size();
        int dp[N + 1][M + 1];
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= M; j++){
                
                if(text1[i] == text2[j]){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1; 
                    }
                    else{
                        dp[i][j] = 1 + dp[i - 1][j - 1]; 
                    }
                        
                }
                else{
                    if(i == 0 && j > 0){
                        dp[i][j] = dp[i][j - 1];
                            
                    }
                    else if(j == 0 && i > 0){
                        dp[i][j] = dp[i - 1][j];
                    }
                    else if(i == 0 && j == 0){
                        dp[i][j] = 0;
                    }
                    else
                        dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                    
                }    
            }
            
        }
        
        return dp[N - 1][M - 1];
        
        
    }
};