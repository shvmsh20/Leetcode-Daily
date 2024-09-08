int lengthLL(ListNode* head){
        int curr = 0;
        while(head){
            curr++;
            head = head->next;
        }
        return curr;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = lengthLL(head);
        int equalSize = n/k;
        int extra = n%k;
        vector<ListNode*> res;
        ListNode* curr = head;
        for(int i=0; i<k; i++){
            ListNode* partHead = curr, *prev = nullptr;
            for(int j=0; j<equalSize; j++){
                if(curr){
                    prev = curr;
                    curr = curr->next;
                }else{
                    break;
                }
            }
            if(extra){
                if(curr){
                    prev = curr;
                    curr = curr->next;
                }
                extra--;
            }
            if(prev){
                prev->next = nullptr;
            }
            res.push_back(partHead);
            partHead = curr;
        }
        return res;
    }