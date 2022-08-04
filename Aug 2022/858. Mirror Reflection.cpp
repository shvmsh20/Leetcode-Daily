int mirrorReflection(int p, int q) {
        if(p==q)return 1;
        if(p%(2*q)==0)return 2;
        int x=p,y=q; // first coordinates 
        
        bool up=true; // to check whether ray is upward or downward
        while(true){
            
            // basic conditions
            if(x==p && y==0)return 0;
            if(x==p && y==p)return 1;
            if(x==0 && y==p)return 2;
            
            //calculating the coordinate of next reflection 
            if(up){
                x= x>0? 0:p;
                if(y+q<=p){
                    y=y+q;
                }
                else{
                    up=false;
                    y=2*p-y-q;
                }
            }
            else{// when motion is downward
                x=x>0? 0:p;
                if(y-q>=0){
                    y=y-q;
                }
                else{
                    up=true;
                    y=q-y;
                } 
            }  
        }
        return 0;
    }