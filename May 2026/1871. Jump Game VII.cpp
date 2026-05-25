bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]=='1') return false;
        vector<int> prefix(n);
        if(minJump<n){
            prefix[minJump] = 1;
        }
        if(maxJump+1<n){
            prefix[maxJump+1]--;
        }
        for(int i=1; i<n; i++){
            prefix[i] += prefix[i-1];
            if(s[i]=='0' && prefix[i]){
                if(i+minJump<n){
                    prefix[i+minJump]++;
                    if(i+maxJump+1<n){
                        prefix[i+maxJump+1]--;
                    }
                }
            } 
        }
        return prefix[n-1];
    }