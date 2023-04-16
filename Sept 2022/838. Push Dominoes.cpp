string pushDominoes(string dom) {
        int n = dom.size();
        vector<int> forces(n);
        int force=0;
        for(int i=0; i<n; i++){
            if(dom[i]=='R'){
                force = n;
            }else if(dom[i]=='L'){
                force = 0;
            }else{
                force = max(0, force-1);
            }
            forces[i]+=force;
        }
        force=0;
        for(int i=n-1; i>=0; i--){
            if(dom[i]=='L'){
                force = n;
            }else if(dom[i]=='R'){
                force = 0;
            }else{
                force = max(0, force-1);
            }
            forces[i]-=force;
        }
        for(int i=0; i<n; i++){
            if(forces[i]<0){
                dom[i] = 'L';
            }else if(forces[i]>0){
                dom[i] = 'R';
            }else{
                dom[i] = '.';
            }
        }
        return dom;
    }