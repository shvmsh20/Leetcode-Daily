int countBits(int n){
        int count = 0;
        for(int i=0; i<32; i++){
            if(n&(1<<i)){
                count++;
            }
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int hours=0; hours<=11; hours++){
            for(int mins=0; mins<=59; mins++){
                if(countBits(hours)+countBits(mins)==turnedOn){
                    string sHours = to_string(hours);
                    string sMins = to_string(mins);
                    sMins = sMins.size()!=2? ("0"+sMins):sMins;
                    res.push_back(sHours +":"+ sMins);
                }
            }
        }
        return res;
    }