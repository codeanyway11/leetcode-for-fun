class Solution {
public:
    void colorTheGrid(vector<vector<int>>& image, int sr, int sc, int newColor, int initialColor, vector<vector<bool>>& visited){
        vector<vector<int> > neighbours{{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
        
        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        for(int i=0; i<4; i++){
            int x = sr+neighbours[i][0];
            int y = sc+ neighbours[i][1];
            
            if(x>=0 && y>=0 && x < image.size() &&  y<image[0].size()){
                if(!visited[x][y] && image[x][y] == initialColor){
                    cout<<x<<" -> "<<y<<endl;
                    colorTheGrid(image, x,y, newColor, initialColor, visited);
                    image[x][y] = newColor;
                    visited[x][y] = true;
                }
            }
        }
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool> > visited (image.size(), vector<bool>(image[0].size(), false));
        int oldColor = image[sr][sc];
       
        colorTheGrid(image, sr, sc, newColor, oldColor, visited);
        return image;
    }
};