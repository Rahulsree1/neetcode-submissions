class Solution {
public:
    vector<int> productExceptSelfv1(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1]*nums[i-1];
            suffix[n-i-1] = suffix[n-i]*nums[n-i];
        }

        vector<int> ans;

        for(int i=0; i<n; i++)
            ans.push_back(prefix[i]*suffix[i]);
    
        return ans;

    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        int tproduct = 1;

        for(auto &i:nums) tproduct *= i;

        vector<int> ans(n, 0);

        if(tproduct == 0){
            int ind = -1;
            int tpro = 1;
            for(int i=0; i<n; i++){
                if(ind != -1 && nums[i] == 0) return ans;
                else if(nums[i] == 0) ind = i;
                if(nums[i] != 0) tpro *= nums[i];
            }

            ans[ind] = tpro;
            return ans;
        }


        for(int i=0; i<n; i++)
            ans[i] = tproduct/nums[i];
    
        return ans;

    }
};
