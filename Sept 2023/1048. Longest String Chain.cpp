static bool sortbylength(string& s1,string& s2){
    return s1.length()<s2.length();
}
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0;
        sort(words.begin(),words.end(),sortbylength);
        for(string word:words){
            for(int i=0;i<word.size();i++){
               string preds=word.substr(0,i)+word.substr(i+1);
               mp[word]=max(mp[word],mp[preds]/*checking it is present or not*/+1);
            }
            ans=max(ans,mp[word]);
        }
        return ans;
    }