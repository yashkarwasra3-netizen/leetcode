class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        int low= *std::max_element(nums.begin(), nums.end());
        int high=std::accumulate(nums.begin(), nums.end(), 0);
        while(low<= high){
              int cntsub=1;
        int subsum=0;
            int mid=low+(high-low)/2;
            for(int i=0; i<n; i++){
                if(subsum+nums[i] <= mid){
                    subsum+=nums[i];
                }
                else{
                    cntsub++;
                    subsum=nums[i];
                }
            }
            if(cntsub<=k){
                 ans =mid;
                high=mid-1;
            }
            else 
            low=mid+1;
        }
        return ans;
    }
};