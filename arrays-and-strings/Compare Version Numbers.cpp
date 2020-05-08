class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        string word;
        stringstream s(version1);
        while(getline(s, word, '.')){
            v1.push_back(stoi(word));
        }
        
        vector<int> v2;
        stringstream ss(version2);
        while(getline(ss, word, '.')){
            v2.push_back(stoi(word));
        }
        
        for(int i=0; i<min(v1.size(), v2.size()); i++){
            if(v1[i] >v2[i]){
                return 1;
            }else if(v1[i]< v2[i]){
                return -1;
            }
        }
        
        int i= v1.size()-1;
        while(i>=0 && v1[i] == 0){
            v1.pop_back();
            i--;
        }
        
        
        i= v2.size()-1;
        while(i>=0 && v2[i] == 0 ){
            v2.pop_back();
            i--;
        }
        
        if(v1.size()== v2.size()){
            return 0;
        }else if(v1.size() > v2.size()){
            return 1;
        }
        return -1;
        
        
    }
};