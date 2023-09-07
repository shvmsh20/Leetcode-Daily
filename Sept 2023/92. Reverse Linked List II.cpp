ListNode* reverse(ListNode* x, int len){
        ListNode* prev = nullptr, *curr = x;
        for(int i=0; i<len; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        for(int i=1; i<left; i++){
            curr = curr->next;
        }3
        ListNode* tmp = curr;
        ListNode* tmp1 = curr->next;
        curr = curr->next;
        for(int i=left; i<=right; i++){
            curr = curr->next;
        }
        ListNode* secondPart = curr;
        ListNode* reversedHead = reverse(tmp->next, right-left+1);
        tmp->next = reversedHead;
        tmp1->next = secondPart;
        return dummy->next;
    }