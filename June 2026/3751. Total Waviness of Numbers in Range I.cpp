int totalWaviness(int num1, int num2) {
        int res = 0;
        for(int n = num1; n<=num2; n++){
            string s = to_string(n);
            if(s.size()<3){
                continue;
            }
            for(int i=1; i<s.size()-1; i++){
                if(s[i]>s[i-1] && s[i]>s[i+1]){
                    res++;
                }else if(s[i]<s[i-1] && s[i]<s[i+1]){
                    res++;
                }
            }
        }
        return res;
    }