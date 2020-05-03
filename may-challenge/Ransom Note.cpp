// Question:
// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

// The avg time complexity for insert, search and delete in unordered_map is O(1)
// Thinking about the question made me wonder why use ordered_map at all ever then? ordered map uses RB Tree under the hood. 
// 1) it is ordered, used when order is important
// 2) also, when space optimization is required
// for more read: https://stackoverflow.com/questions/2196995/is-there-any-advantage-of-using-map-over-unordered-map-in-case-of-trivial-keys

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> myMap;
        for(int i=0; i<J.size(); i++){
            myMap[J[i]] = 0;
        }
        
        for(int i=0; i<S.size(); i++){
            if(myMap.find(S[i])!= myMap.end()){
                myMap[S[i]]++;
            }
        }
        
        int count = 0;
        for(int i=0; i<J.size(); i++){
            count += myMap[J[i]];
        }
        
        return count;
    }
};