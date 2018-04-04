class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        vector<int> tempm;
        vector<int> tempn;
        int m = matrix.size();
        int n = matrix[0].size();
        cout<<m<<" "<<n<<endl;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0){
                    tempn.push_back(j);
                    tempm.push_back(i);
                }
            }
        }
        if(tempm.empty()) return;
        for(int x = 0; x < tempm.size(); x++) {
            for(int y = 0; y < m; y++)
                matrix[y][tempn[x]] = 0;
            for(int k = 0; k < n; k++)
                matrix[tempm[x]][k] = 0;
        }
    }
};
//最蠢的方法 别人的方法是 先记录第一行第一列有没有0  然后用第一行第一列记录 哪里有0 然后把除1行1列的0补上 最后来处理1行1列