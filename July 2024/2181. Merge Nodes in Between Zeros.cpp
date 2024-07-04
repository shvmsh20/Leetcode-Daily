ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy, *curr = head->next;
        int sum = 0;
        while(curr){
            if(curr->val==0){
                p->next = new ListNode(sum);
                p = p->next;
                sum = 0;
            }else{
                sum+= curr->val;
            }
            curr = curr->next;
        }
        return dummy->next;
    }