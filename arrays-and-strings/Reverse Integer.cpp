class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if(x < 0){
            negative = true;
        }
        
        long long value = 0;
        x = abs(x);
        while(x){
            value = value*10+x%10;
            x=x/10;
        }
        
        if(negative){
            value= value*(-1);
        }
        if(value > INT_MAX || value <INT_MIN){
            return 0;
        }
        return int(value);
        
    }
};
