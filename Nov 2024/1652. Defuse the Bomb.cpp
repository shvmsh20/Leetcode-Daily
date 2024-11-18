vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k==0){
            for(int i=0; i<n; i++){
                code[i] = 0;
            }
            return code;
        }
        vector<int> res;
        if(k>0){
            int sum = 0;
            for(int i=1; i<=k; i++){
                int index = i%n;
                sum+= code[index];
            }
            for(int i=0; i<n; i++){
                res.push_back(sum);
                sum-= code[((i+1) % n)];
                sum+= code[((i+1+k)%n)];
            }
        }else{
            k = abs(k);
            int sum = 0;
            int index = n-1, cnt = k;
            while(cnt--){
                sum+= code[index];
                index--;
            }
            index++;
            for(int i=0; i<n; i++){
                res.push_back(sum);
                sum-= code[(index+i)%n];
                sum+= code[i];
            }

        }
        return res;
    }