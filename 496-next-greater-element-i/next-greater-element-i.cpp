#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::stack<int> st;
        std::unordered_map<int, int> next_greater;

        // Traverse nums2 from right to left
        for (int j = nums2.size() - 1; j >= 0; j--) {
            int current = nums2[j];

            // 1. Pop smaller or equal elements
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            // 2. Map current number to its next greater element
            next_greater[current] = st.empty() ? -1 : st.top();

            // 3. Push current element onto the stack
            st.push(current);
        }

        // Build the answer vector for nums1 in O(1) per element
        std::vector<int> ans;
        ans.reserve(nums1.size());
        for (int num : nums1) {
            ans.push_back(next_greater[num]);
        }

        return ans;
    }
};