bool pal(string x){
        int end = x.length()-1, st = 0;
        while(st<end){
            if(x[st]!=x[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;

    }
    string firstPalindrome(vector<string>& words) {
        for(string x: words){
            if(pal(x)){
                return x;
            }
        }
        return "";
    }