# Solution for Longest Substring Without Repeating Characters in cpp
# You can copy code manually from LeetCode
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int first=0,second=0,len=0;
        vector<bool>count(256,0);
        int n=s.size();
        while(second<n){
         while(count[s[second]]){
           count[s[first]]=0; 
           first++; 
         }
           
          count[s[second]]=1;
         len = max(len,second-first+1);
          second++;
        }
        return len;

    }
};
