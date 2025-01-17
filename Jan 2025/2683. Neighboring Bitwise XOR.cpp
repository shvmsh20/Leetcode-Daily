bool check(int first, int n, vector<int> &derived){
        int curr = first;
        for(int i=0; i<n; i++){
            if(i!=n-1){
                int next = derived[i]==0?(curr==0?0:1):(curr==0?1:0);
                curr = next;
            }else{
                if(curr^first==derived[n-1]){
                    return true;
                }
            }
        }
        return false;
    }
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int first = derived[0];
        
        if(check(0, n, derived) || check(1, n, derived)){
            return true;
        }else{
            return false;
        }
       
    }