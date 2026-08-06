class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        for(int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }
        n= nums.size();
        vector<int> vec(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i]) st.pop();
            if(st.empty()){
                st.push(nums[i]);
                continue;
            }
            else if(st.top() > nums[i]){
                vec[i] = st.top();
                st.push(nums[i]);
            }
        }
        vector<int> vect(n/2, -1);
        for(int i=0; i<n/2; i++){
            vect[i]= vec[i];
        }
        return vect;
    }
};