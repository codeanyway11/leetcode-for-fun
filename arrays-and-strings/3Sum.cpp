
// Question: https://leetcode.com/problems/3sum/

class Solution {
public:
    void twoSum(vector<int> &nums, int i, vector<vector<int> > &res){
        int lo = i+1, hi = nums.size()-1;
        while(lo < hi){
            int sum = nums[i] + nums[lo] + nums[hi];
            if(sum <0 || (lo> i+1 && nums[lo] == nums[lo-1])){
                lo++;
            }else if(sum >0 || (hi<nums.size()-1 && nums[hi] == nums[hi+1])){
                hi--;
            }else{
                res.push_back({ nums[i], nums[lo++], nums[hi--]});
            }
        }
    }
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> output;
        
    
        for(int i=0; i<nums.size() && nums[i]<=0; i++)
            if(i==0 || nums[i]!=nums[i-1])
                twoSum(nums, i, output);
        
        return output;
        
    }
};