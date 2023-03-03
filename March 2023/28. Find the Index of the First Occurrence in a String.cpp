int strStr(string haystack, string needle) {
       int m = needle.length();
        int n = haystack.length();
        bool f = true;
        for(int i=0; i<n; i++){
            int k=i, j=0;
            while(k<n && j<m){
                if(haystack[k]==needle[j]){
                    k++;
                    j++;
                }else{
                    break;
                }
            }
            if(j==m){
                return i;
            }
        }
        return -1;
    }