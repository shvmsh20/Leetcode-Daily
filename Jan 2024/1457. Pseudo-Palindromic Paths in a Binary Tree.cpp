bool isPal(vector<int> &freq){
        unordered_map<int, int> mp;
        int oddFreqCount = 0;
        for(auto x: freq){
            if(x&1){
                oddFreqCount++;
            }
            if(oddFreqCount>1){
                return false;
            }
        }
        return true;
    }
    void solve(TreeNode* node, vector<int> &freq, int &res){
        if(node==nullptr){
            return;
        }
        freq[node->val]++;
        solve(node->left, freq, res);
        if(node->left==nullptr && node->right==nullptr && isPal(freq)){
            res++;
        }
        solve(node->right, freq, res);
        freq[node->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        vector<int> freq(10, 0);
        solve(root, freq, res);
        return res;
    }