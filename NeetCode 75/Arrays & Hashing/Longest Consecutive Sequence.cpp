class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num:nums)
            st.insert(num);

        int maxLen =0;
        for(int num:nums){
            if(st.count(num-1)) continue;
            else{
                int len =0;
                int first = num;
                while(st.count(first++))
                    len++;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
