class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> uhashmap;
        for(auto &i:nums) uhashmap[i]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto &i:uhashmap){
            if(pq.size() < k) pq.push({i.second, i.first});
            else if(pq.top().first < i.second){
                pq.pop();
                pq.push({i.second, i.first});
            }
        }


        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        } 
    
        return ans;
    }
};
