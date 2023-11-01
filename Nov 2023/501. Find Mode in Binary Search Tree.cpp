void inorder(TreeNode* root, int& currentVal, int& currentCount, int& maxCount, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        inorder(root->left, currentVal, currentCount, maxCount, result);
        
        if (root->val == currentVal) {
            currentCount++;
        } else {
            currentVal = root->val;
            currentCount = 1;
        }
        
        if (currentCount > maxCount) {
            maxCount = currentCount;
            result.clear();
            result.push_back(currentVal);
        } else if (currentCount == maxCount) {
            result.push_back(currentVal);
        }
        
        inorder(root->right, currentVal, currentCount, maxCount, result);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int currentVal = 0;
        int currentCount = 0;
        int maxCount = 0;
        
        inorder(root, currentVal, currentCount, maxCount, result);
        
        return result;
    }