bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffX = abs(sx-fx), diffY = abs(fy-sy);
        int diag = min(diffX, diffY);
        if(sx==fx && fy==sy && t==1){
            return false;
        } 
        int minSteps = diffX+diffY - (2*diag) + diag;
       
        if(t<minSteps){
            return false;
        }
       
        return true;
    }