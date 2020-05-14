class Solution {
public:
    vector<pair<int, int> > getNeighbours(pair<int, int> front, int rows, int cols, vector<vector<bool> > &matrix){
        vector<pair<int, int> > neighbours;
        vector<int> nR = {0, 0, -1, 1};
        vector<int> nC = {-1, 1, 0, 0};
        for(int i=0; i< nR.size(); i++){
            int rn = front.first + nR[i];
            int cn = front.second + nC[i];            
            if(rn >=0 && rn <rows && cn >=0 && cn < cols && !matrix[rn][cn]){
                neighbours.push_back(make_pair(rn, cn));
            }
        }
        return neighbours;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() <1 ) return 0;
        deque<pair<int, int> > q;
        int rows = grid.size(); int cols = grid[0].size();
        vector<vector<bool> > matrix (rows, vector<bool> (cols, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2){
                    q.push_back(make_pair(i, j));
                }
            }
        }
        
        q.push_back(make_pair(-1, -1));
        int count = 0;
        while(!q.empty()){
            pair<int, int> top = q.front();
            cout<<top.first<<" -> "<<top.second<<endl;
            q.pop_front();
            if(top.first == -1){
                if(q.empty()) continue;
                else{
                    q.push_back(top);
                    top = q.front();
                    q.pop_front();
                } 
                count++;
            }
            vector<pair<int, int> >neighbours = getNeighbours(top, rows, cols, matrix);
            for(int i=0; i<neighbours.size(); i++){
                if(grid[neighbours[i].first][neighbours[i].second] == 1){
                    cout<<neighbours[i].first<<" -> "<<neighbours[i].second<<endl;
                    q.push_back(neighbours[i]);
                    matrix[neighbours[i].first][neighbours[i].second] = 1;
                }
            }
            grid[top.first][top.second] = 2;
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        
        return count;
    }
};s