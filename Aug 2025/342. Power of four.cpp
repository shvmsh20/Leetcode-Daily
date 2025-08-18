class Solution {
public:
    bool isPowerOfFour(int n) {
        int cpy = n;
        if(n==0 || n<0){
            return false;
        }
        int count=0;
        while(n!=1){
            count++;
            n = n>>1;
        }
        
        if((count%2==0) && ((1<<count)==cpy)){
            return true;
        }else{
            return false;
        }
    }
};