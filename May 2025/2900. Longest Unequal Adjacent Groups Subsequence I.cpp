vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int zeroSt = 0, oneSt = 0;
        bool lookingForZero = true;
        int n = words.size();
        for(int i=0; i<n; i++){
            if(lookingForZero &&  groups[i]==0){
                zeroSt++;
                lookingForZero = !lookingForZero;
            }else if(lookingForZero==false && groups[i]==1){
                zeroSt++;
                lookingForZero = !lookingForZero;
            }
        }
        lookingForZero = false;
        for(int i=0; i<n; i++){
            if(lookingForZero &&  groups[i]==0){
                oneSt++;
                lookingForZero = !lookingForZero;
            }else if(lookingForZero==false && groups[i]==1){
                oneSt++;
                lookingForZero = !lookingForZero;
            }
        }
        if(zeroSt>=oneSt){
            lookingForZero = true;
        }else{
            lookingForZero = false;
        }
        vector<string> res;
        for(int i=0; i<n; i++){
            if(lookingForZero && groups[i]==0){
                res.push_back(words[i]);
                lookingForZero = !lookingForZero;
            }else if(lookingForZero==false && groups[i]==1){
                res.push_back(words[i]);
                lookingForZero = !lookingForZero;
            }
        }
        return res;
    }