# Solution for Roman to Integer in cpp
# You can copy code manually from LeetCode
class Solution {
private:
int symToVal(char c){
    switch(c){
        case 'I':  return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return -1;
}
public:
    int romanToInt(string s) {
       
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(symToVal(s[i]) <symToVal(s[i+1])){
                ans -= symToVal(s[i]);
            }
            else{
                ans += symToVal(s[i]);
            }
        }
        return ans;
    }
};
