//n & (n-1) removes the rightmost 1 bit.  Every iteration removes exactly one set bit (1). That's why the number of iterations = number of 1s.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt =0;
        while(n){ 
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
};
