class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int> > indexes(26, make_pair(-1, -1));
        for(int i=0; i<s.size(); i++){
            int first = indexes[s[i]-'a'].first;
            if(first == -1){
                indexes[s[i]-'a'].first = i;
                indexes[s[i]-'a'].second = i;
            }else{
                indexes[s[i]-'a'].second = i;
            }
        }
        
        sort(indexes.begin(), indexes.end());
        int index=0; 
        while(index< indexes.size() && indexes[index].first == -1){
            index++;
        }
        index++;
        for(int i=index; i<indexes.size(); i++){
            if(indexes[i].first < indexes[i-1].second){

                indexes[i].first = indexes[i-1].first;
                indexes[i].second = max(indexes[i-1].second, indexes[i].second);
                indexes.erase(indexes.begin()+(i-1));
                i--;
                
            }
        }
        
        vector<int> output;
        for(int i=index-1; i<indexes.size(); i++){
            output.push_back(indexes[i].second - indexes[i].first +1);
        }
        
        return output;
        
    }
};