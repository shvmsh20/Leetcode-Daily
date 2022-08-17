int uniqueMorseRepresentations(vector<string>& words) {
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto x: words){
            string temp;
            for(int i=0; i<x.size(); i++){
                
                temp+= code[x[i]-'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }