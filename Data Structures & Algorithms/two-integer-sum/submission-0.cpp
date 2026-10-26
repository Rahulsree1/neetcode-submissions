class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> hashmap;
        for(int i=0; i<n; i++){
            if(hashmap.find(target-nums[i]) != hashmap.end()) return {hashmap[target-nums[i]], i};
            hashmap[nums[i]] = i;
        }

        return {-1, -1};
        
    }
};
