ListNode* findMid(ListNode * node){
        ListNode* slow = node, *fast = node;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* node){
        if(node->next==nullptr){
            return node;
        }
        ListNode* temp = node->next;
        ListNode* head = reverse(node->next);
        temp->next = node;
        node->next = nullptr;
        return head;
    }
    
    bool chckPal(ListNode* a, ListNode* b){
        while(b!=nullptr){
            if(a->val!=b->val){
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }
        ListNode* mid = findMid(head);
        ListNode* sndHlf;
        sndHlf = reverse(mid->next);
        mid->next = sndHlf;
        return chckPal(head, sndHlf);
        
    }