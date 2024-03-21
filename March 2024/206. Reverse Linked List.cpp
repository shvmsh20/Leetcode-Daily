ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* prev = nullptr, *next;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }