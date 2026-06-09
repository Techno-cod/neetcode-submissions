class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>uniqueTriplets;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int>seen;
            for(int j=i+1;j<n;j++){
                int third=-(nums[i]+nums[j]);
                if(seen.find(third)!=seen.end()){
                vector<int>triplets={nums[i],nums[j],third};
                sort(triplets.begin(), triplets.end());

                    uniqueTriplets.insert(triplets);
            }
             seen.insert(nums[j]);
        }
        }
        return vector<vector<int>>(uniqueTriplets.begin(),
                       uniqueTriplets.end());

        
    }
};
