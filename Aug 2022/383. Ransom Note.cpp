bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(char x: magazine){
            mp[x]++;
        }
        for(int i=0; i<ransomNote.size(); i++){
            if(mp.count(ransomNote[i]) && mp[ransomNote[i]]>=1){
                mp[ransomNote[i]]--;
            }else{
                return false;
            }
        }
        return true;
    }