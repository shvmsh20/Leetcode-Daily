ListNode* middleNode(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* s=head, *f=head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }