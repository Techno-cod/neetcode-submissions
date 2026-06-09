class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int second=target-num;
            if(mpp.find(second)!=mpp.end()){
                return{mpp[second],i};
            }
            mpp[num]=i;


        }
        return{-1,1};
        
        
        
    }
};
