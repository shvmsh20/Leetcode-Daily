bool isValid(string &s) {
        if (s.empty()) return false;
        for (char ch : s) {
            if (ch == '_') continue;
            if (!isalnum(ch)) return false;
        }
        return true;
    }

    bool isValidCategory(string &cat) {
        return cat == "electronics" ||
               cat == "grocery" ||
               cat == "pharmacy" ||
               cat == "restaurant";
    }

    static int priority(const string &cat) {
        if (cat == "electronics") return 0;
        if (cat == "grocery")     return 1;
        if (cat == "pharmacy")    return 2;
        return 3; // restaurant
    }

    static bool comp(const pair<string,string> &a,
                     const pair<string,string> &b) {
        int pa = priority(a.first);
        int pb = priority(b.first);

        if (pa != pb)
            return pa < pb;

        return a.second < b.second;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        vector<pair<string,string>> data;

        for (int i = 0; i < code.size(); i++) {
            if (isValid(code[i]) &&
                isValidCategory(businessLine[i]) &&
                isActive[i]) {

                data.push_back({businessLine[i], code[i]});
            }
        }

        sort(data.begin(), data.end(), comp);

        vector<string> res;
        for (auto &it : data) {
            res.push_back(it.second);
        }

        return res;
    }