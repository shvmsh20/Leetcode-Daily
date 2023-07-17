ListNode* reverse(ListNode *node){
        if(node==nullptr){
            return nullptr;
        }
        ListNode* prevNode = nullptr, *curr = node;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
        }
        return prevNode;
    }
    void display(ListNode* x){
        while(x){
            cout << x->val << " ";
            x = x->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* x = reverse(l1);
        ListNode* y = reverse(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        int carry = 0;
        while(x!=nullptr || y!=nullptr || carry!=0){
            int sum = carry;
            if(x){
                sum+= x->val;
                x = x->next;
            }
            if(y){
                sum+= y->val;
                y = y->next;
            }
            carry = sum/10;
            sum = sum%10;
            node->next = new ListNode(sum);
            node = node->next;
        }
        return reverse(dummy->next);
    }