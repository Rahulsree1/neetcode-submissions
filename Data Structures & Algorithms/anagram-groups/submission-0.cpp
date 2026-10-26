class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> hashmap;

        for(auto &i:strs){
            string temp = i;
            sort(temp.begin(), temp.end());

            hashmap[temp].push_back(i);
        }

        vector<vector<string>> ans;

        for(auto &i:hashmap) ans.push_back(i.second);
        return ans;
    }
};
