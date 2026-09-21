class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashMap(128,-1);
        int n = s.length(), maxLen =0, i=0;
        for(int j =0; j<n; j++){
            char ch = s[j];
            if(hashMap[ch] != -1 )
                i = max(i,hashMap[ch]+1); //IMP LINE
            hashMap[ch] = j;
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};
