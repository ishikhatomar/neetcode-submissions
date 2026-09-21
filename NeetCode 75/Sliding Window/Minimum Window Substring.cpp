class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256,0);
        for(char ch:t)
            freq[ch]++;
        int n= s.length(), minLen =INT_MAX, i=0, strtInd =-1, cnt=0;

        for(int j =0; j<n; j++){
            if(freq[s[j]] > 0)
                cnt++;
            freq[s[j]]--;
            while(cnt ==t.size()){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    strtInd = i;
                }
                freq[s[i]]++;
                if(freq[s[i]]>0)
                    cnt--;
                i++;
            }
        }
        return strtInd == -1?"":s.substr(strtInd, minLen);
    }
};
