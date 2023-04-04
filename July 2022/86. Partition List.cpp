ListNode* partition(ListNode* head, int x) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* dummy1 = new ListNode(), *dummy2 = new ListNode(), *t1 = dummy1, *t2 = dummy2;
        ListNode* curr = head;
        while(curr){
            if(curr->val<x){
                t1->next = curr;
                t1 = t1->next;
            }else{
                t2->next = curr;
                t2 = t2->next;
            }
            curr = curr->next;
        }
        t1->next = nullptr;
        t2->next = nullptr;
        if(dummy1->next){
            t1->next = dummy2->next;
            return dummy1->next;
        }else{
            return dummy2->next;
        }
    }