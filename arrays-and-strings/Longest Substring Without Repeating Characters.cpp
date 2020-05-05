// Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/solution/


class Solution
{
    public:
        int lengthOfLongestSubstring(string s){
            if (s.size() < 1){
                return 0;
            }
            unordered_map<char, int> chars;
            int maxLength = 0;
            int length = 0;
            int start = 0;

            for (int i = 0; i < s.size(); i++){
                if (chars.find(s[i]) == chars.end() || chars[s[i]] < start){
                    length++;
                    chars[s[i]] = i;
                    maxLength = max(maxLength, length);
                }
                else{
                    maxLength = max(maxLength, i - chars[s[i]]);
                    start = chars[s[i]] + 1;
                    length = i - start + 1;
                    chars[s[i]] = i;
                }
            }

            maxLength = max(maxLength, length);

            return maxLength;
        }
};