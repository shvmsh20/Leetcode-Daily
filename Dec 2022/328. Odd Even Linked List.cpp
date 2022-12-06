ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* oddS = new ListNode(-1), *evenS = new ListNode(-1);
        ListNode* odd = oddS, *even = evenS;
        bool od = true;
        ListNode* curr = head;
        while(curr){
            if(od){
                odd->next = curr;
                odd = odd->next;
            }else{
                even->next = curr;
                even = even->next;
            }
            od = !od;
            curr = curr->next;
        }
        if(oddS->next==nullptr){
            return evenS->next;
        }
        if(evenS->next==nullptr){
            return oddS->next;
        }
        odd->next = nullptr;
        even->next = nullptr;
        evenS = evenS->next;
        oddS = oddS->next;
        odd->next = evenS;
        return oddS;

    }