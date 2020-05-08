class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> myMap;
        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(myMap.find(temp)!= myMap.end()){
                myMap[temp].push_back(strs[i]);
            }else{
                myMap[temp] = {strs[i]};
            }
        }
        
        vector<vector<string> > output;
        for(auto it= myMap.begin(); it!=myMap.end(); it++){
            output.push_back(it->second);
        }
        return output;
    }
};