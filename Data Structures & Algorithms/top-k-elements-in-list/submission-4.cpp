class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> uhashmap;
        for(auto &i:nums) uhashmap[i]++;
        
        vector<vector<int>> buckets(n+1);

        for(auto &i:uhashmap) buckets[i.second].push_back(i.first);

        vector<int> ans;

        for(int i=n; i>=0; i--)
            for(auto &j:buckets[i]){
                ans.push_back(j);
                if(ans.size() == k) return ans;
            }
        
        return ans;
    }
};
