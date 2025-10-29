int smallestNumber(int n) {
         int x = n;
        while ((x & (x + 1)) != 0) {
            x++;
        }
        return x;
    }