struct DSU {
        std::vector<int> f, siz;
        
        DSU() {}
        DSU(int n) {
            init(n);
        }
        
        void init(int n) {
            f.resize(n);
            std::iota(f.begin(), f.end(), 0);
            siz.assign(n, 1);
        }
        
        int find(int x) {
            while (x != f[x]) {
                x = f[x] = f[f[x]];
            }
            return x;
        }
        
        bool same(int x, int y) {
            return find(x) == find(y);
        }
        
        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            }
            siz[x] += siz[y];
            f[y] = x;
            return true;
        }
        
        int size(int x) {
            return siz[find(x)];
        }

        void reset(int x) {
            f[x] = x;
            siz[x] = 1;
        }
    };

    static bool cmp(vector<int> &a,vector<int> &b) {
        return a[2] < b[2];
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),cmp);
        DSU dsu(n);
        dsu.merge(0,firstPerson);
        
        int i = 0,N = meetings.size();
        while(i < N) {
            int currTime = meetings[i][2];
            set<int> pool;
            while(i < N && meetings[i][2] == currTime) {
                pool.insert(meetings[i][0]);
                pool.insert(meetings[i][1]);
                dsu.merge(meetings[i][0],meetings[i][1]);
                i++;
            }
            for(auto &e :pool) {
                if(!dsu.same(e,0)) dsu.reset(e); 
            }
        }

        vector<int> ans;
        for(int i = 0;i < n;++i) {
            if(dsu.same(i,0)) ans.push_back(i);
        }
        return ans;
    }