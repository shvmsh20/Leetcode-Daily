int countVowelStrings(int n) {
        int a=1, e=1, i=1, o=1, u=1;
        for(int x=1; x<n; x++){
            o+=u;
            i+=o;
            e+=i;
            a+=e; 
        }
        return a+e+i+o+u;
    }