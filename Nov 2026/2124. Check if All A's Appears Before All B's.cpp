bool checkString(string s) {
         bool seenB = false;

        for (char ch : s) {
            if (ch == 'b') seenB = true;
            else if (seenB) return false;
        }

        return true;
    }