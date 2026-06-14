class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxL=0;
        int maxR=0;
        int water=0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=maxL){
                    maxL=height[left];
                }
                else{
                    water+=maxL-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxR){
                    maxR=height[right];
                }
                else{
                    water+=maxR-height[right];
                }
                right--;
            }
        }
        return water;
    
        
    }
};
