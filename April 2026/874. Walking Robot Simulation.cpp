int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obs;
        for(vector<int> x: obstacles){
            obs.insert({x[0], x[1]});
        }
        int dir = 0;
        int i = 0, j = 0;
        int res = 0;
        for(int x: commands){
            if(x==-2){
                dir = (dir-1+4)%4;
            }else if(x==-1){
                dir = (dir+1)%4;
            }else{
                int ni = i, nj = j;
                for(int z=0; z<x; z++){
                    if(dir==0){
                        nj++;
                    }else if(dir==1){
                        ni++;
                    }else if(dir==2){
                        nj--;
                    }else{
                        ni--;
                    }
                    if(obs.find({ni, nj})==obs.end()){
                        i = ni;
                        j = nj;
                    }else{
                        break;
                    }
                }
                res = max(res, (i*i) + (j*j));
            }
        }
        return res;
    }