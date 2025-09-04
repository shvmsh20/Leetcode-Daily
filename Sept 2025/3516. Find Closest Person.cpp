int findClosest(int x, int y, int z) {
        int diffX = abs(x-z), diffY = abs(y-z);
        if(diffX<diffY){
            return 1;
        }else if(diffY<diffX){
            return 2;
        }else{
            return 0;
        }
    }