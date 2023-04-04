int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        
        //Converting divisors and dividend to their positive values
        long int dd = abs(dividend), dv = abs(divisor);
        
        //Result Variables
        int res=0;
        while(dd-dv>=0){
            int count=0;
            while(dd-(dv<<1<<count) >=0){
                count++;
            }
            res+= (1<<count);
            dd = dd - (dv<<count);
        }
        
        //If either of dividend or divisor is negative our result will be negative
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -res;
        
        return res;
        
    }