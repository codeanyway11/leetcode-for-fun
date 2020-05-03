// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// Since, the question says you have to optimise the number of calls to isBadVersion API, that is a good enough hint.
// We know here that if one number is a bad version, all the later ones are too.
// Two ways to search through this - Linear: O(n) Time Complexity & Binary O(logn) TC


class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0;s
        int r = n;
        int answer = n;
        while(l<=r){
            long long mid = (r-l)/2 + l;
            if(isBadVersion(mid)){
                answer = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return answer;
    }
};