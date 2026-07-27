class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0; // Initializing the variable 'ans' to store the maximum product
        
        // Nested loops to iterate through pairs of elements in the 'nums' array
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // Calculating the product of (nums[i] - 1) and (nums[j] - 1)
                // and updating 'ans' to hold the maximum product found so far
                ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        
        return ans; // Returning the maximum product of two distinct elements
    }
};