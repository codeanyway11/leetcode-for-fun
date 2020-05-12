class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedList;
        for(int i=0; i<banned.size(); i++){
            bannedList.insert(banned[i]);
        }
        
        replace_if(paragraph.begin(), paragraph.end(), [](auto ch) { return ::isdigit(ch) || ::ispunct(ch); }, ' ');
            
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        string temp; 
        stringstream ss(paragraph);
        map<string, int> myMap;

        int maxCount = 0;
        string answer = "";
        while(getline(ss, temp, ' ')){
            if(temp== "" || bannedList.find(temp)!= bannedList.end()){
                continue;
            }
            
            
            if(myMap.find(temp)!= myMap.end()){
                myMap[temp]++;
            }else{
                myMap[temp] = 1;
            }
            
            if(myMap[temp] > maxCount){
                answer = temp;
                maxCount = myMap[temp];
            }
        }
        return answer;
        
    }
};