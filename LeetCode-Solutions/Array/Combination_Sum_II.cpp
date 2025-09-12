# Solution for Combination Sum II in cpp
# You can copy code manually from LeetCode
class Solution {
    void combinationSum(int ind, int t, vector<int>& temp, vector<int>& ca,
                        vector<vector<int>>& ans) {
                            if(t==0){
                                ans.push_back(temp);
                                return;
                            }
      for(int i=ind;i<ca.size();i++){
        if(i!=ind&&ca[i]==ca[i-1])continue;
        if(t>=ca[i]){
        temp.push_back(ca[i]);
         combinationSum(i+1, t-ca[i], temp, ca, ans);
         temp.pop_back();
        
         }
         else break;
         
      }
      
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& ca, int t) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(ca.begin(), ca.end());
        combinationSum(0, t, temp, ca, ans);
        return ans;
    }
};
