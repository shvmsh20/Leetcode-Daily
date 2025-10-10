using u32 = uint32_t;
    [[nodiscard]] static constexpr int maximumEnergy(
        std::vector<int>& energy,
        u32 k)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        u32 n = static_cast<u32>(energy.size());
        for (u32 t = n; t-- > k;)
        {
            energy[t - k] += energy[t];
        }
        return *std::ranges::max_element(energy);
    }