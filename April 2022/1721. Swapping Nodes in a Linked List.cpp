int length(ListNode *head){
        int count=0;
        while(head!=nullptr){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *x_prev = nullptr, *x = head;
        ListNode *y_prev = nullptr, *y = head;
        int n = length(head);
        if(2*k-1==n) return head;
        for(int i=1; i<k; i++){
            x_prev = x;
            x = x->next;
        }
        for(int i=1; i<n-k+1; i++){
            y_prev = y;
            y = y->next;
        }
        
        if(x_prev){
            x_prev->next = y;
        }
        if(y_prev){
            y_prev->next = x;
        }
        
        ListNode *temp = x->next;
        x->next = y->next;
        y->next = temp;
        
        if(k==1){
            return y;
        }
        if(k==n){
            return x;
        }
        return head;
    }