ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int cnt = 1;
        ListNode* tail = head;
        while(tail->next!=nullptr){
            cnt++;
            tail = tail->next;
        }
        k = k % cnt;
        if(k==0) return head;
        int till = cnt-k-1;
        ListNode* curr = head;
        while(till--){
            curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = nullptr;
        tail->next = head;
        return newHead;
    }