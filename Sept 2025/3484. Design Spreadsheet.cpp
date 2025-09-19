class Spreadsheet {
public:
    int n = 0, m = 26;
    vector<vector<int>> v;
    Spreadsheet(int rows) {
        n = rows+1;
        v.resize(n, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        int row = 0;
        for(int i=1; i<cell.size(); i++){
            int lastDigit = cell[i]-'0';
            row = (row*10) + lastDigit;
        }
        v[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        int row = 0;
        for(int i=1; i<cell.size(); i++){
            int lastDigit = cell[i]-'0';
            row = (row*10) + lastDigit;
        }
        v[row][col] = 0;
    }
    
    int getValue(string formula) {
        string first = "";
        string second = "";
        int sz = formula.size();
        int index = 1;
        while(index<sz && formula[index]!='+'){
            first+=formula[index];
            index++;
        }
        index++;
        while(index<sz){
            second+= formula[index];
            index++;
        }
        // cout << first << " " << second << endl;
        int x = 0, y = 0;
        if(first[0]>='A' && first[0]<='Z'){
            int col = first[0]-'A';
            int row = 0;
            for(int i=1; i<first.size(); i++){
                int lastDigit = first[i]-'0';
                row = (row*10) + lastDigit;
            }
            x = v[row][col];
        }else{
            for(int i=0; i<first.size(); i++){
                x = (x*10) + (first[i]-'0');
            }
            
        }
        if(second[0]>='A' && second[0]<='Z'){
            int col = second[0]-'A';
            int row = 0;
            for(int i=1; i<second.size(); i++){
                int lastDigit = second[i]-'0';
                row = (row*10) + lastDigit;
            }
            y = v[row][col];
        }else{
            for(int i=0; i<second.size(); i++){
                y = (y*10) + (second[i]-'0');
            }
        }
        // cout << x << " " << y << endl;
        return x+y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */