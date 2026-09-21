class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = 1;
       
        for(int i=1; i<n; i++) //[-1,0,0,0,0]
            prefix[i] = prefix[i-1]*nums[i-1];
        
        int mul =1;
        for(int i =n-1; i>=0; i--){
            prefix[i] = prefix[i]*mul;
            mul *= nums[i];
        }
        return prefix;
        
    }
};
