# Solution for Find Valid Pair of Adjacent Digits in String in cpp
# You can copy code manually from LeetCode
class Solution {
public:
    string findValidPair(string s) {
        vector<int>ind(11,0);
        vector<int>fre(11,0);
        string ans="";
        int k;
        int n;
         
        for(int i=0;i<s.size();i++){
            k=s[i]-'0';
            fre[k]++;
            if(ind[k]==0)ind[k]=i;
           
        }
       
          for(int i=0;i<s.size()-1;i++){
               k=s[i]-'0';
               n=s[i+1]-'0';
              
             
         
              if(fre[k]==k&&fre[n]==n&&k!=n){
                ans+=s[i];
                  ans+=s[i+1];
                  
                    fre[k]=0;
                  fre[n]=0;
                  return ans;
              }
          }
        return ans;
    }
};
