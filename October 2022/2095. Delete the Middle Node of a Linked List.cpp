ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy, *fast = dummy;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return dummy->next;
    }