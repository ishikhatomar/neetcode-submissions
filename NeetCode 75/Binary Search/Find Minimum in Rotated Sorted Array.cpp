class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low =0, high = n-1, minElement = INT_MAX;
        while(low <= high){
            if(nums[low] < nums[high]){
                minElement = min(minElement ,  nums[low]);
                break;
            }
            int mid = low + (high - low) / 2;
            minElement = min(minElement , nums[mid]);
            if(nums[mid] >  nums[high])
                low = mid+1;
            
            else   high = mid-1;
        }
        return minElement;
    }
};
