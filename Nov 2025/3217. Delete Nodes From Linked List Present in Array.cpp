ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = head, *prev = dummy;
        unordered_set<int> s;
        for(int x: nums){
            s.insert(x);
        }
        while(curr){
            if(s.find(curr->val)!=s.end()){
                prev->next = curr->next;
            }else{
                prev = prev->next;
            }
            curr = curr->next;
            
        }
        return dummy->next;
    }