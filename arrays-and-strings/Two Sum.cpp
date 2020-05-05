// Question: https://leetcode.com/problems/two-sum/

class Solution
{
	public:
		vector<int> twoSum(vector<int> &nums, int target){
			unordered_map<int, int> numbers;
			vector<int> output;
			for (int i = 0; i < nums.size(); i++){
				int complement = target - nums[i];
				if (numbers.find(complement) != numbers.end()){
					output.push_back(numbers[complement]);
					output.push_back(i);
					return output;
				}

				numbers[nums[i]] = i;
			}
			return output;
		}
};