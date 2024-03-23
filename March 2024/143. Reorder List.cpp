void reorderList(ListNode* head) {
        ListNode* fast = head->next, *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr, *second = slow->next, *temp;
        slow->next = nullptr;
        while(second){
            temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        second = prev;
        ListNode* first = head, *t1, *t2;
        while(second){
            t1 = first->next;
            t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
    }