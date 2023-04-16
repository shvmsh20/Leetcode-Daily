TreeNode* solve(int l, int h, vector<int> &nums){
        if(l>h){
            return nullptr;
        }
        int mid = (l+h)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = solve(l, mid-1, nums);
        node->right = solve(mid+1, h, nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        return solve(l, h, nums);
    }