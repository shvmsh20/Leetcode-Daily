int countHomogenous(string s) {
     const int MOD = 1e9 + 7;
        int prev_char = INT_MIN, length = 0;
        int result = 0;
        for (auto& c : s) {
            length = (prev_char == c) ? (length + 1) : 1;
            result = (result + length) % MOD;
            prev_char = c;
        }
        return result;
    }