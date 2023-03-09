ListNode *detectCycle(ListNode *head) {
        if(head==nullptr){
            return head;
        }
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast){
                break;
            }
        }
        if(fast==nullptr || fast->next==nullptr){
            return nullptr;
        }
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }