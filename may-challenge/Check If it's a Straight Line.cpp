class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float slope =0;
        if(coordinates.size() <=2){
            return true;
        }
        
        slope = float(coordinates[1][1]- coordinates[0][1])/float(coordinates[1][0]- coordinates[0][0]);
        
        int tempSlope = 0;
        for(int i=2; i<coordinates.size(); i++){
            int diffX = coordinates[i][0]- coordinates[i-1][0];
            int diffY = coordinates[i][1]- coordinates[i-1][1];
            if (diffX == 0){
                if(diffY!=0){
                    return false;
                }
            }else{
                tempSlope = float(diffY)/float(diffX);
                if(tempSlope != slope){
                    return false;
                }
            }
        }
        
        return true;
    }
};