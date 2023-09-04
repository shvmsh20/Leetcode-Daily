bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr){
            return false;
        }
        ListNode* fast = head, *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }

        return false;
    }