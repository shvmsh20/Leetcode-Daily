class Solution {
#define ll long long int

public:
    long long sumAndMultiply(int n) {
        ll s = 0, res = 0, m = 1;

        while (n) {
            int d = n % 10;

            if (d) {
                res = d * m + res;
                m *= 10;
                s += d;
            }

            n /= 10;
        }

        return res * s;
    }
};