vector<int> diffWaysToCompute(string s) {
        vector<int> res;
        int n = s.length();
        for(int i=0; i<n; i++){
            char op = s[i];
            if(op=='+' || op=='-' || op=='*'){
                vector<int> left = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i+1));
                for(int x: left){
                    for(int y: right){
                        if(op=='+'){
                            res.push_back(x+y);
                        }else if(op=='-'){
                            res.push_back(x-y);
                        }else{
                            res.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(res.size()==0){
            return {stoi(s)};
        }
        return res;
    }