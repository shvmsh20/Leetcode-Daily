using Set = unordered_set<char>;
    bool halvesAreAlike(string s, Set V = {'a','e','i','o','u','A','E','I','O','U'}) {
        return count_if(s.begin(), s.begin() + s.size() / 2, [&](auto c) { return V.find(c) != V.end(); })
            == count_if(s.begin() + s.size() / 2, s.end(), [&](auto c) { return V.find(c) != V.end(); });
    }