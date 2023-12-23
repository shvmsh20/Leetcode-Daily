bool isPathCrossing(string path) {
        set<pair<int, int>> vis;
        int x = 0, y = 0;
        vis.insert({0, 0});
        for(int i=0; i<path.length(); i++){
            if(path[i]=='N'){
                y++;
            }else if(path[i]=='S'){
                y--;
            }else if(path[i]=='E'){
                x++;
            }else{
                x--;
            }
            if(vis.find({x, y})!=vis.end()){
                return true;
            }
            vis.insert({x, y});
        }
        return false;
    }