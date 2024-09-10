int gcd(int a, int b){
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }
        if(a==b){
            return a;
        }
        if(a>b){
            return gcd(a-b, b);
        }
        return gcd(a, b-a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head, *curr = head->next;
        while(curr){
            ListNode* gcdNode = new ListNode(gcd(prev->val, curr->val));
            prev->next = gcdNode;
            gcdNode->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }