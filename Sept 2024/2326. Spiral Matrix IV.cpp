vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> res(n, vector<int>(m, -1));
        ListNode* curr = head;
        int t=0, r=m-1, d=n-1, l=0;
        while(curr){
            // l->r
            for(int i=l; i<=r; i++){
                res[t][i] = curr->val;
                // cout << curr->val << endl;
                curr = curr->next;
                if(!curr){
                    break;
                }
            }
            t++;
            if(!curr){
                break;
            }
            //  t-d
            for(int i=t; i<=d; i++){
                res[i][r] = curr->val;
                // cout << curr->val << endl;
                curr = curr->next;
                if(!curr){
                    break;
                }
            }
            r--;
            if(!curr){
                break;
            }
            // r->l
            for(int i=r; i>=l; i--){
                res[d][i] = curr->val;
                // cout << curr->val << endl;
                curr = curr->next;
                if(!curr){
                    break;
                }
            }
            d--;
            if(!curr){
                break;
            }
            
            // d->t
            for(int i=d; i>=t; i--){
                res[i][l] = curr->val;
                // cout << curr->val << endl;
                curr = curr->next;
                if(!curr){
                    break;
                }
            }
            l++;
            if(!curr){
                break;
            }
            
        }
        return res;
    }