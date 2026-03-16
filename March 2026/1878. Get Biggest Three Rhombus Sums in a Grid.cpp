class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mxSize = (min(n, m) + 1)/2;
        vector<int> v;
         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                v.push_back(grid[i][j]);
            }
         }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                for(int k=2; k<=mxSize; k++){
                    int x1=i, y1=j;
                    int x2=i+k-1, y2=j+k-1;
                    int x3=i+(2*(k-1)), y3=j;
                    int x4=i+(k-1), y4=j-(k-1);
                    if(x2>=0 && x2<n && x3>=0 && x3<n && x4>=0 && x4<n && y2>=0 && y2<m && y3>=0 && y3<m && y4>=0 && y4<m){
                        int sum = 0;
                        // top → right
                        for(int x=x1, y=y1; x<=x2; x++,y++)
                            sum+=grid[x][y];

                        // right → bottom
                        for(int x=x2+1, y=y2-1; x<=x3; x++,y--)
                            sum+=grid[x][y];

                        // bottom → left
                        for(int x=x3-1, y=y3-1; x>=x4; x--,y--)
                            sum+=grid[x][y];

                        // left → top
                        for(int x=x4-1, y=y4+1; x>x1; x--,y++)
                            sum+=grid[x][y];
                        v.push_back(sum);
                    }
                }
            }
        }
        sort(v.begin(), v.end(), greater<int>());
        vector<int> res;
        unordered_set<int> st;
        for(int i=0; i<v.size() && st.size()<3; i++){
            if(st.find(v[i])==st.end()){
                st.insert(v[i]);
                res.push_back(v[i]);
            }
        }
        return res;
       
    }
};