class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x <4) return 1;
        
        int l = 0;
        int r = x;
        while(l < r){
            long long mid =(r+l)/2;
            if(1LL*(mid*mid) <= 1LL*(x) && 1LL*(mid+1)*(mid+1) > 1LL*x) {return mid;}
            if(1LL*(mid*mid) < x) l = mid;
            else r = mid;
        }
        return l;
    }
};