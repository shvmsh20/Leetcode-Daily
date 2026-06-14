ListNode* reverse(ListNode* node){
        ListNode* prev = nullptr, *curr = node;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        ListNode* l1 = head, *l2 = slow->next;
        int res = INT_MIN;
        while(l2){
            res = max(res, l1->val+l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }
        return res;
    }