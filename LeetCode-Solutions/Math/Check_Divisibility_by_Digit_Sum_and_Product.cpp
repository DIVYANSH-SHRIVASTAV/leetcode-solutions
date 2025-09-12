# Solution for Check Divisibility by Digit Sum and Product in cpp
# You can copy code manually from LeetCode
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int mul=1;
        int t=n;
        while(n!=0){
           sum+= n%10;
            mul*=n%10;
            n/=10;
        }
        return t%(sum+mul)==0;
    }
};
