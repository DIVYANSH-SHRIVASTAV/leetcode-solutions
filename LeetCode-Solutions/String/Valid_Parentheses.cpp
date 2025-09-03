# Solution for Valid Parentheses in cpp
# You can copy code manually from LeetCode

class Solution {
public:
    bool isValid(string s) {
        stack<char>pa;
        for(int i=0;i<s.size();i++){
           if(s[i]=='('||s[i]=='{'||s[i]=='['){
            pa.push(s[i]);
           }
           else{
            if(pa.empty())return false;
            else{
               char temp= pa.top();
               pa.pop();
               if(temp=='('&&s[i]==')'||temp=='{'&&s[i]=='}'||temp=='['&&s[i]==']'){
                continue;
               }
               else{
                return false;
               }
            }
           }
        }
        return pa.empty();
    }
};
