class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int> > myMap(N+1, vector<int>());
        vector<bool> trustsSomeone(N+1, false);
        for(int i=0; i<trust.size(); i++){
            int person = trust[i][0];
            trustsSomeone[person] = true;
            int potentialJudge = trust[i][1];
            myMap[potentialJudge].push_back(person);
            
        }
        
        for(int i=1; i<=N; i++){
                 if(myMap[i].size() == N-1 && !trustsSomeone[i]){
                    return i;
            }
        }
        return -1;
    }
};