ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* curr=head, *prev=nullptr, *nex, *temp, *newHead;
        while(curr && curr->next){
            nex = curr->next;
            temp = nex->next;
            nex->next = curr;
            curr->next = temp;
            if(prev){
                prev->next = nex;
            }else{
                newHead = nex;
            }
            prev = curr;
            curr = temp;
        }
        return newHead;
    }