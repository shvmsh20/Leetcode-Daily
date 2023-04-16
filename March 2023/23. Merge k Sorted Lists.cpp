ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<=l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1){
            tail->next = l1;
        }
        if(l2){
            tail->next = l2;
        }
        return dummy->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for(int i=0; i<lists.size(); i++){
            res = merge(res, lists[i]);
        }
        return res;
    }