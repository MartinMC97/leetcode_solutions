// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, high = n;
        while(left < high){
            int median = left + (high - left) / 2;
            if(isBadVersion(median)){
                high = median;
            }else{
                left = median + 1;
            }
        }
        
        return left;
    }
};