// Question: https://leetcode.com/problems/string-to-integer-atoi/

// Edge cases to be handled:
// 1. Empty spaces or zeroes in the beginning
// 2. Get the sign correct

class Solution
{
    public:
        int myAtoi(string str){
            long long answer = 0;
            bool negative = false;
            bool digit = false;

            int size = str.size();
            int it = 0;
            while (it < size && (str[it] == ' ')){
                it++;
            }

            if (str[it] == '-'){
                negative = true;
                it++;
            }
            else if (str[it] == '+'){
                it++;
            }

            while (it < size && (str[it] == '0')){
                it++;
            }

            for (int i = it; i < size; i++){
                if (str[i]<'0' || str[i] > '9'){
                    break;
                }
                int value = str[i] - '0';
                answer = answer *10 + value;

                if (answer > INT_MAX){
                    if (negative){
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
            }

            if (negative){
                answer = -1 * answer;
            }

            return int(answer);
        }
};