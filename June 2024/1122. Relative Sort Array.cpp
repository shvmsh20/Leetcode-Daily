vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<int, int> mp;
    unordered_set<int> s(arr2.begin(), arr2.end());
    int index = arr1.size() - 1;
    for (int i = index; i >= 0; i--)
    {
        if (s.find(arr1[i]) == s.end())
        {
            arr1[index] = arr1[i];
            index--;
        }
        else
        {
            mp[arr1[i]]++;
        }
    }
    int i = 0;
    for (int num : arr2)
    {
        int cnt = mp[num];
        while (cnt)
        {
            arr1[i++] = num;
            cnt--;
        }
    }
    sort(arr1.begin() + i, arr1.end());
    return arr1;
}