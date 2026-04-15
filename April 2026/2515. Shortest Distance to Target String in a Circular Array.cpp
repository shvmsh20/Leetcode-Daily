int closestTarget(vector<string>& words, string target, int startIndex) {
        int res = 0, n = words.size(), index = startIndex;
        do {
            if(words[index]==target){
                break;
            }
            index = (index+1)%n;
            res++;
        }while(index!=startIndex);
        if(res==n){
            return -1;
        }
        int ans = 0;
        index = startIndex;
        do {
            if(words[index]==target){
                break;
            }
            index = (index-1+n)%n;
            ans++;
        }while(index!=startIndex);
        return min(ans, res);
    }