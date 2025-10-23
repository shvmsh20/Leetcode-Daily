bool hasSameDigits(string s) {
        int n = s.size();
        while(s.size()!=2){
            string temp;
            int n =  s.size();
            for(int i=0; i<n-1; i++){
                int newD = ((s[i]-'0') + (s[i+1]-'0'))%10;
                temp+= to_string(newD);
            }
            s = temp;
        }
        return s[0]==s[1];
    }