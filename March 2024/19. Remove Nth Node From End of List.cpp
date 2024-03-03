ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(), *first, *second;
        dummy->next = head;
        first = dummy;
        second = dummy;
        while(n--){
            second = second->next;
        }
        while(second->next){
            second = second->next;
            first = first->next;
        }
        ListNode* nodeToDelete = first->next;
        first->next = first->next->next;
        delete nodeToDelete;
        return dummy->next;
    }