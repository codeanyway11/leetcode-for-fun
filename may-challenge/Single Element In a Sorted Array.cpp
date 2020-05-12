class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int l= 0;
        int r = arr.size()-1;
        int mid;
        if(arr.size()<1){
            return 0;
        }
        
        if(arr.size()==1){
            return arr[0];
        }
        while(l <=r){
            
             mid = (l+r)/2;
            if(mid+1 <=r && mid>0){
                 if(arr[mid-1]!= arr[mid] && arr[mid+1]!= arr[mid]){
                    return arr[mid];
                 }
            }
            if(mid %2 == 0 && mid+1 <=r){
               if(arr[mid+1]!= arr[mid]){
                    r= mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if(arr[mid+1]!= arr[mid]){
                    l= mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return arr[mid];
    }
};