int getDecimalValue(ListNode* head) {
        int res = 0;
        int cnt = 0;
        while(head){
           res = res << 1;
           res = res | head->val;
           head = head->next;
        }
        return res;
    }