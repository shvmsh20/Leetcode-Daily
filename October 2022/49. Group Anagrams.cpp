vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<map<char, int>, vector<string>> mp;
        vector<vector<string>> res;
        int n=0;
        for(string x: strs){
            map<char, int> freq;
            for(int i=0; i<x.length(); i++){
                freq[x[i]]++;
            }
            
            mp[freq].push_back(x);
            
        }
        
        for(auto it: mp){
            res.push_back(it.second);
        } 
        return res;
    }