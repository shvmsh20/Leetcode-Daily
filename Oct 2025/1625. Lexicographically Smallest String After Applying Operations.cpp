#include <algorithm>
#include <string>
#include <unordered_set>

using u8 = uint8_t;

class Solution
{
public:
    std::unordered_set<std::string> visited;
    std::string r;
    u8 a = 0, b = 0, n = 0;

    void dfs(const std::string& s)
    {
        if (visited.contains(s)) return;
        visited.insert(s);
        if (s < r) r = s;

        auto copy = s;
        for (u8 i = 1; i < n; i += 2)
        {
            char& c = copy[i];
            c = static_cast<char>(((c + a - '0') % 10) + '0');
        }

        dfs(copy);
        copy = s;

        std::ranges::rotate(copy, copy.end() - b);
        dfs(copy);
    }

    [[nodiscard]] std::string
    findLexSmallestString(std::string& s, u8 a_, u8 b_) noexcept
    {
        r = s, a = a_, b = b_, n = s.size() & 0xFF;

        dfs(s);

        return r;
    }
};