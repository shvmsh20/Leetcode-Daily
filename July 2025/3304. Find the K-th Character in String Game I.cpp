char kthCharacter(int k) {
         return __builtin_popcount(k-1) + 'a';
    }