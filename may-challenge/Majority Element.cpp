// Question : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_elem = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=maj_elem){
                count--;
                if(count == 0){
                    maj_elem = nums[i];
                    count = 1;
                }
            }else{
                count++;
                if(count > nums.size()/2){
                    return maj_elem;
                }
            }
        }
        return maj_elem;
    }
};