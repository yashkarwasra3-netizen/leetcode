class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> vec(n2, -1);
        int j = n2 - 1;
        while (j >= 0) {
            while (!st.empty() && st.top() <= nums2[j]) {
                st.pop();
            }

            if (st.empty()) {
                vec[j] = -1;
                st.push(nums2[j]);
                j--;
            } else if (st.top() > nums2[j]) {
                vec[j] = st.top();
                st.push(nums2[j]);
                j--;
            }
        }
        vector<int> vect(n1, -1);
        for(int j=0; j<n2; j++){
            for(int i=0; i<n1; i++){
                if(nums1[i] == nums2[j]){
                    vect[i] = vec[j];
                }
            }
        }
        return vect;
    }
};