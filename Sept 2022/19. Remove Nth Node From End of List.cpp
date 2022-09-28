ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fast = head, *slow = dummy;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return dummy->next;
    }