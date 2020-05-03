// Question:
// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/

// The avg time complexity for insert, search and delete in unordered_map is O(1)
// Thinking about the question made me wonder why use ordered_map at all ever then? ordered map uses RB Tree under the hood. 
// 1) it is ordered, used when order is important
// 2) also, when space optimization is required
// for more read: https://stackoverflow.com/questions/2196995/is-there-any-advantage-of-using-map-over-unordered-map-in-case-of-trivial-keys

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> myMap;
        for(int i=0; i<magazine.size(); i++){
            if(myMap.find(magazine[i]) != myMap.end()){
                myMap[magazine[i]]++;
            }else{
                myMap[magazine[i]] = 1;
            }   
        }
        
         for(int i=0; i<ransomNote.size(); i++){
            if(myMap.find(ransomNote[i]) == myMap.end() ){
                return false;
            }else{
                if(myMap[ransomNote[i]] == 0){
                    return false;
                }
                myMap[ransomNote[i]]--;
            }
        }
        
        return true;
    }
};