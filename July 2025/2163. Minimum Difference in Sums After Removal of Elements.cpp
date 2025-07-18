long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n/3;

        priority_queue<ll> left(nums.begin(), nums.begin()+m);

        map<ll, int> mp;
        for(int i=m; i<n; i++) {
            ll x = (ll)nums[i];
            mp[x]++;
        }

        vector<ll> eraser;
        ll sumRight = 0;

        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            auto &[a, b] = *it;

            if(b <= m) {
                m-=b;
                sumRight += b*a;
                eraser.push_back(a);
                if(m == 0) break;
            } else {
                sumRight += m*a;
                b -= m;
                break;
            }
        }

        m = n/3;

        for(ll &a:eraser) {
            mp.erase(a);
        }

        ll sumLeft = accumulate(nums.begin(), nums.begin()+m, 0LL);

        ll ans = sumLeft-sumRight;

            // cout << "sumLeft: " << sumLeft << "  sumRight: " << sumRight << endl;
            // Line;

        for(int i=m+1; i<=2*m; i++) {

            ll num = nums[i-1];
            if(num < left.top()) {
                // cout<<"left: NUM; " <<num<<endl;
                sumLeft -= left.top();
                sumLeft += num;
                left.pop();
                left.push(num);
            }

            // for(auto&[a,b]:mp) {
            //     cout << "a: " << a << " b: " << b << endl;
            // }

            // Line;

            if(!mp.count(num)) {
                sumRight -= num;
                auto &[a, b] = *mp.rbegin();
                // cout << "right : if:: " << " a: " << a << " b: " << b << endl;
                sumRight += a;
                b--;
                if(b==0) mp.erase(a);
            } else {
                
                // cout << "right : else:: " << endl;
                mp[num]--;
                if(mp[num]==0) mp.erase(num);
            }
            
            // cout << "sumLeft: " << sumLeft << "  sumRight: " << sumRight << endl;

            ans = min(ans, sumLeft - sumRight);
        }

        return ans;
    }