// Question: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/


class Solution
{
    public:
        int bitwiseComplement(int N)
        {
            if (N == 0)
            {
                return 1;
            }
            int base = N;
            int xorNumber = 1;

            while (base != 0)
            {
                N = N ^ xorNumber;
                xorNumber = xorNumber << 1;
                base = base >> 1;
            }

            return N;
        }
};