string convertToTitle(int n) {
        string ans="";
        while(n>0){
            int c = n%26;
            n = n/26;
            if(c==0){
                ans = 'Z'+ans;
                n--;
            }else{
                char temp = 64+c;
                ans = temp +ans;
            }
            
        }
        return ans;
    }