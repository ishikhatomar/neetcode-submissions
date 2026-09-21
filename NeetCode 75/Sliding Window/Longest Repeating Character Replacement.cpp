class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.length(), maxFreq =0, maxLen =0, i=0;
        vector<int> hash(26,0);
        for(int j =0; j<n; j++){
            hash[s[j]-'A']++;
            maxFreq = max(maxFreq, hash[s[j]-'A']);
            if((j-i+1)-maxFreq > k){
                hash[s[i]-'A']--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};
