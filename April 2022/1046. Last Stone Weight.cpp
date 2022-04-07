int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(int i=0; i<stones.size();i++){
            p.push(stones[i]);
        }
        while(p.size()>1){
            int a = p.top();
            p.pop();
            int b = p.top();
            p.pop();
            if(a!=b){
                int t = max(a,b)- min(a,b);
                p.push(t);
            }
                
            
        }
        return p.size()==1?p.top():0;
    }