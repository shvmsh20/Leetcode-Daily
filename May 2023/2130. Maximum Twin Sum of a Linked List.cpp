int length(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* reverse(ListNode* x){
        ListNode* prev = nullptr;
        while(x){
            ListNode* temp = x->next;
            x->next = prev;
            prev = x;
            x = temp;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        int n = length(head);
        ListNode* lastOfFirst = head;
        for(int i=0; i<((n/2)-1); i++){
            lastOfFirst = lastOfFirst->next;
        }
        ListNode* reversedPart = reverse(lastOfFirst->next);
        lastOfFirst->next = reversedPart;
        ListNode* y = reversedPart, *x = head;
        int res = INT_MIN;
        while(y){
            res = max(res, (x->val+y->val));
            x = x->next;
            y = y->next;
        }
        return res;
    }