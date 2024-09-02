int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0, n = chalk.size();
        for(int x: chalk){
            sum+= x;
        }
        k = k%sum;
        for(int i=0; i<n; i++){
            if(k< chalk[i]){
                return i;
            }
            k-=chalk[i];
        }
        return -1;
    }