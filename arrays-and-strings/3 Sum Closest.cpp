// Quesiton: https://leetcode.com/problems/3sum-closest/



class Solution {
public:
    void getClosestValue(vector<int> &nums, int i, long long *value, int target){
        int lo = i+1;
        int hi = nums.size()-1;
        long long diff = INT_MAX;
        while(lo< hi){
            int sum = nums[i]+ nums[lo]+ numss[hi];
            long long currentDiff = abs(sum-target);
    
            if(currentDiff<diff){
                diff = currentDiff;
                *value = sum;
            }
            
            if(sum > target){
                hi--;
            }else if(sum < target){
                lo++;
            }else{
                return;
            }
        }
        
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int finalValue = INT_MAX;
        long long diff = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            long long value = INT_MAX;
            getClosestValue(nums, i, &value, target);
            long long currentDiff = 1LL*abs(value-target);
    
            if(currentDiff<diff){
                diff = currentDiff;
                finalValue = value;
            }
           
        }
        return finalValue;
    }
};
