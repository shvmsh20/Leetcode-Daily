Node* copyRandomList(Node* head) {
        Node* curr = head;
        //step-1
        while(curr){
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        curr = head;
        //step-2
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }else{
                curr->next->random = nullptr;
            }
            curr = curr->next->next;
        }
        Node* dummy = new Node(0), *cpy = dummy, *org = head;
        while(org){
            Node* t = org->next->next;
            cpy->next = org->next;
            cpy = cpy->next;
            org->next = t;
            org = org->next;
        }
        return dummy->next;
    }