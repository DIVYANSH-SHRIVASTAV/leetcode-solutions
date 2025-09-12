# Solution for Count Partitions with Even Sum Difference in cpp
# You can copy code manually from LeetCode
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tsum=0;
        int left=0;
        int right=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
            
        }
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            right=tsum-left;
            if((right-left)%2==0)ans++;
        }
        return ans;
    }
};
