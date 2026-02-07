int minimumDeletions(string s) {
        int n = s.size();
        int mn = INT_MAX;
        int leftB = 0, rightA = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                rightA++;
            }
        }
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                rightA--;
            }
            mn = min(mn, leftB+rightA);
            if(s[i]=='b'){
                leftB++;
            }
        }
        return mn;
    }