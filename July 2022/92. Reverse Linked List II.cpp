ListNode* reverse(ListNode* head, ListNode* end){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=end){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        cout << prev->val << endl;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head, *start=nullptr, *end=nullptr, *prevStart = nullptr, *dummy=new ListNode(), *prev;
        dummy->next =head;
        prev = dummy;
        int currIndex=1;
        while(curr){
            if(currIndex==left){
                prevStart = prev;
                start = curr;
            }
            if(currIndex==right){
                end = curr;
            }
            prev = curr;
            curr = curr->next;
            currIndex++;
        }
        if(start==end){
            return head;
        }
        ListNode* t = end->next;
        prevStart->next = nullptr;
        ListNode* reversedList = reverse(start, end->next);
        prevStart->next = reversedList;
        start->next = t;
        return dummy->next;
        
    }