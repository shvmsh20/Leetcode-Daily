int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        int count = 0;
        for(int i=0; i<chars.size(); i++){
            mp[chars[i]]++;
        }
        for(int i=0; i<words.size(); i++){
            unordered_map<char, int> freq;
            bool flag = true;
            for(int j=0; j<words[i].size(); j++){
                freq[words[i][j]]++;
                if(freq[words[i][j]]>mp[words[i][j]]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                count+= words[i].size();
            }
        }
        return count;
    }