void func(vector<string>& list, string& ch, int index,
              int open, int close) {

        if (open == 0 && close == 0) {
            list.push_back(ch);
            return;
        }

        if (open > 0) {
            ch[index] = '(';
            func(list, ch, index + 1, open - 1, close);
        }

        if (close > open) {
            ch[index] = ')';
            func(list, ch, index + 1, open, close - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> list;
        string ch(2 * n, ' ');

        func(list, ch, 0, n, n);

        return list;
    }