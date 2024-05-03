int compareVersion(string v1, string v2) {
        int n = v1.size();
        int m = v2.size();
        int i=0, j=0;
        while(i<n || j<m){
            int t1=0, t2=0;
            int s1=0;
           
                
                while(i<n && v1[i]!='.'){
                    s1 = s1*10 + (v1[i]-'0');
                    i++;
                }
                i++;
            
            int  s2 = 0;
           
                while(j<m && v2[j]!='.'){
                    s2 = s2*10 + (v2[j]-'0');
                    j++;
                }
                j++;
            
            if(s1>s2){
                return 1;
            }else if(s2>s1){
                return -1;
            }
            
        }
        return 0;
    }