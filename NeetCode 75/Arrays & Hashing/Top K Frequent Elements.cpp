class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        unordered_map<int,int> mp;
        for(int num: nums){
            mp[num]++;
        }
        
        for(auto it: mp){
            int num = it.first;
            int freq = it.second;
            pq.push({freq, num});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            int num = pq.top().second;
            ans.push_back(num);
            pq.pop();
        }
        return ans;
    }
};
