string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for(string x: words){
            int weight = 0;
            for(char c: x){
                weight = (weight+weights[c-'a'])%26;
            }
            res.push_back('z'-weight);
        }
        return res;
    }