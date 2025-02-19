int count = 0;
    string res = "";

    string getHappyString(int n, int k) {
        count = 0;
        res = "";
        string sb = "";
        backtrack(n, k, sb, ' ');
        return res;
    }

    void backtrack(int n, int k, string &sb, char lastChar) {
        if (sb.length() == n) {
            if (++count == k) {
                res = sb;
            }
            return;
        }

        char chars[] = {'a', 'b', 'c'};
        for (int i = 0; i < 3; i++) {
            char c = chars[i];
            if (c != lastChar) {
                sb.push_back(c);
                backtrack(n, k, sb, c);
                sb.pop_back();
                if (!res.empty()) return;
            }
        }
    }