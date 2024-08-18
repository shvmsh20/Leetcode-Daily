int nthUglyNumber(int n) {
        if(n==1){
            return 1;
        }
        unordered_set<long long int> vis;
        vector<long long int> v2 = {2}, v3 = {3}, v5 = {5};
        n--;
        long long int num = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        while(n--){
            if(index2!=v2.size() && v2[index2]<v3[index3] && v2[index2]<v5[index5]){
                num = v2[index2];
                index2++;
            }else if(index3!=v3.size() && v3[index3]<v2[index2] && v3[index3]<v5[index5]){
                num = v3[index3];
                index3++;
            }else{
                num = v5[index5];
                index5++;
            }
            if(vis.find(2*num)==vis.end()){
                v2.push_back(2*num);
                vis.insert(2*num);
            }
            if(vis.find(2*num)==vis.end()){
                v2.push_back(2*num);
                vis.insert(2*num);
            }
            if(vis.find(3*num)==vis.end()){
                v3.push_back(3*num);
                vis.insert(3*num);
            }
            if(vis.find(5*num)==vis.end()){
                v5.push_back(5*num);
                vis.insert(5*num);
            }
        }
        return num;
    }