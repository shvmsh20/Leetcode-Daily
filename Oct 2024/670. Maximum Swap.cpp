int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        for(int i=0; i<n; i++){
            int mx = i;
            for(int j=i+1; j<n; j++){
                if(s[j]>=s[mx]){
                    mx = j;
                }
            }
            if(s[mx]!=s[i]){
                // cout << i << " " << mx;
                swap(s[mx], s[i]);
                return stoi(s);
            }
        }
        return num;
        
    }