int minDeletionSize(vector<string>& strs) {
        auto n {strs.size()};
        auto m {strs[0].length()};
        int counter {};
        std::vector<bool> sorted(99);       
        std::vector<bool> sorted_temp(99);
        for (size_t j {}; j < m; j++)
        {
            std::fill(sorted_temp.begin(), sorted_temp.end(), false);
            bool remove {false};
            for (size_t i {}; i < n - 1; i++)
            {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j])
                {
                    counter++;
                    remove = true;
                    break;
                }
                else if (strs[i][j] < strs[i + 1][j])
                {
                    sorted_temp[i] = true;
                }
            }
            if (!remove)
            {
                for (size_t i {}; i < n - 1; i++)
                {
                    sorted[i] = sorted[i] || sorted_temp[i];
                }
            }
        }
        return counter;
    }