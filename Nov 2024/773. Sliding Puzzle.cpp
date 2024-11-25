int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string s;
        int index = 0;
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                s.push_back(board[i][j]+'0');
                if(board[i][j]==0){
                    index = 3*i + j;
                }
            }
        }
        string target = "123450";
        if(s==target){
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({s, index});
        unordered_set<string> set;
        int moves = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                pair<string, int> p = q.front();
                q.pop();
                string s = p.first;
                int pos = p.second;
                if(s==target){
                    return moves;
                }
                for(int x: adj[pos]){
                    swap(s[pos], s[x]);
                    if(set.find(s)==set.end()){
                        q.push({s, x});
                        set.insert(s);
                    }
                    swap(s[pos], s[x]);
                }
            }
            moves++;
        }
        return -1;
    }