static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        sort(props.begin(), props.end(), cmp);
        int n = props.size();
        int count=0;
        int mxDef = INT_MIN;
        for(int i=n-1; i>=0; i--){
            //cout << props[i][1] << " ";
            if(props[i][1]<mxDef){
                count++;
            }
            if(props[i][1]>mxDef){
                mxDef = props[i][1];
            }
        }
        return count;
    }