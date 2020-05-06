// Question: https://leetcode.com/problems/roman-to-integer/


class Solution {
public:
    int romanToInt(string s) {
        if(s.size()<1){
            return 0;
        }
        map<char, int> myMap;
        myMap['I'] = 1;
        myMap['V'] = 5;
        myMap['X'] = 10;
        myMap['L'] = 50;
        myMap['C'] = 100;
        myMap['D'] = 500;
        myMap['M'] = 1000;
        
        map<char, int> rank;
        rank['I'] = 1;
        rank['V'] = 5;
        rank['X'] = 10;
        rank['L'] = 50;
        rank['C'] = 100;
        rank['D'] = 500;
        rank['M'] = 1000;

        int totalValue = 0;
        int currentRank = 0;
        bool lastTaken = false;
        for(int i=s.size()-1; i>0; i--){
            currentRank = rank[s[i]];
            if(rank[s[i-1]]>=currentRank){
                totalValue += myMap[s[i]];
            }else{
                if(i==1){
                   lastTaken = true; 
                }
                totalValue +=myMap[s[i]];
                totalValue -=myMap[s[i-1]];
                i--;
                
            }
        }
        
        if(!lastTaken){
            totalValue += myMap[s[0]];
        }
        
        return totalValue;
    }
};