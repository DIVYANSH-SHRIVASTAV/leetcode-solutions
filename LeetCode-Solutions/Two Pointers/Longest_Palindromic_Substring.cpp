# Solution for Longest Palindromic Substring in cpp
# You can copy code manually from LeetCode
class Solution {
    int checkPalindromeSize(string s,int l,int r){
        while(l>=0&&r<s.size()&&s[l]==s[r]){

            l--;
            r++;
        }
        return r-l-1;
    }
   
public:
    string longestPalindrome(string s) {
        int st=0;
        int end=0;
        for(int i=0;i<s.size();i++){
            int odd=checkPalindromeSize(s,i,i);
            int even=checkPalindromeSize(s,i,i+1);
            int maxLength=max(odd,even);
           if(maxLength>end-st){
            st=i-(maxLength-1)/2;
            end=i+(maxLength/2);
           }
        }
        string ans=s.substr(st,end-st+1);
        return ans;
    }
};
