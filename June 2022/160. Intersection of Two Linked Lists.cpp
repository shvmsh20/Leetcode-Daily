ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }
        ListNode *a = headA;
        ListNode *b = headB;
        while(a!=b){
            a = (a==nullptr)?headB:a->next;
            b = (b==nullptr)?headA:b->next;
        }
        return a;
    }