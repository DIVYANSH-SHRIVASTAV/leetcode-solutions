# Solution for Edit Distance in cpp
# You can copy code manually from LeetCode
class Solution {

public:
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int>prev(m+1,0);
        vector<int>cur(m+1,0);
        // for (int i = 0; i <= n; i++) {
        //     dp[i][0] = i;
        // }
        for (int j = 0; j <= m; j++) {
           prev[j] = j;
        }
        for (int i = 1; i <= n; i++) {
            cur[0]=i;
            for (int j = 1; j <= m; j++) {
                 
                if (str1[i - 1] == str2[j - 1])
                    cur[j]= 0 + prev[j - 1];
                else
                    cur[j] =
                        1 + min(prev[j], min(cur[j-1], prev[j - 1]));
            }
            prev=cur;
        }

        return prev[m];
    }
};
