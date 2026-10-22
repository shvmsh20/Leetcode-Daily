int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool leftToRight = true, rightToLeft = true;
        int zeroIndex = -1;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zeroIndex = i;
                break;
            }
        }
        int i = zeroIndex;
        int x = 0;
        do{
            if(nums[i]!=x){
                leftToRight = false;
                break;
            }
            x++;
            i = (i+1)%n;
        }while(i!=zeroIndex);
        i = zeroIndex;
        x = 0;
        do{
            if(nums[i]!=x){
                rightToLeft = false;
                break;
            }
            x++;
            i = (i-1+n)%n;
        }while(i!=zeroIndex);
        if(!leftToRight && !rightToLeft){
            return -1;
        }
        if(leftToRight){
            return min(zeroIndex, n-zeroIndex+2);
        }
        return min(zeroIndex+2, n-zeroIndex);
    }