class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if(num==1){
            return  true;
        }
        long long temp = num;
        
        for (long long i = 2; 1LL*(i * i) <= temp; i++) {
            if (temp % (i * i) == 0) {
                temp = temp/(i * i);
                i--;
                if(temp == 1){
                    return true;
                }
            }
        }
       return temp == 1;
    }
};