// Question: https://leetcode.com/problems/integer-to-roman/


class Solution {
public:
    string intToRoman(int num) {
        
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};    
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string answer = "";
        
        for(int i=0; i<values.size(); i++){
            while(values[i] <= num){
                num-=values[i];
                answer += symbols[i];
                
            }
        }
        return answer;
    }
};