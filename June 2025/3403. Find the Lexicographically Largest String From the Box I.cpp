string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends==1) return word;
        int mxLength = n-(numFriends-1);
        // cout << mxLength << endl;
        string res = word.substr(0, mxLength);
        // cout << res << endl;
        for(int i=1; i<=n; i++){
            // cout << word.substr(i, mxLength) << endl;
            res = max(res, word.substr(i, mxLength));
        }
        return res;
    }