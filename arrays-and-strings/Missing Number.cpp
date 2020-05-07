// Question : https://leetcode.com/problems/missing-number/	

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int value = n;
        for(int i=0; i<nums.size(); i++){
            value=value^i^nums[i];
        }
        
        return value;
    }
};