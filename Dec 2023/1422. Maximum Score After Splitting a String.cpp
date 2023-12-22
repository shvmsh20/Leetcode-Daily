int maxScore(string s) {
        int totalOnes = 0, totalZeros = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                totalOnes++;
            }
        }
        int res = 0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='0'){
                totalZeros++;
            }else{
                totalOnes--;
            }
            res = max(res, totalZeros+totalOnes);
        }
        r