long long wonderfulSubstrings(string word) {
        int n=word.size();
        long long cnt=0;
        uint16_t freq[1024]={0};
        freq[0]=1;
        uint16_t sum=0;
        for(int c: word){
            int index=c-'a';
            sum^=(1<<index);
            cnt+=freq[sum]++;
            for(char i=0; i<10; i++){
                cnt+=freq[sum^(1<<i)];
            }
        }
        return cnt;
    }