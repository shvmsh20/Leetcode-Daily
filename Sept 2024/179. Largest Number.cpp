static bool cmp(string &x, string &y){
        return x+y>y+x;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int x: nums){
            temp.push_back(to_string(x));
        }
        sort(temp.begin(), temp.end(), cmp);
        string res;
        for(string x: temp){
            res+= x;
        }
        int i=0;
        for(; i<res.size(); i++){
            if(res[i]!='0'){
                break;
            }
        }
        if(i!=0){
            res = res.substr(i);
            if(res==""){
                res = "0";
            }
        }
        return res;
    }