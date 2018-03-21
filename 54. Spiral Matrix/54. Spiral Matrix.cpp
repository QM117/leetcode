class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> order;
        if(matrix.empty()) return order;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0;
        cout<< matrix.size() / 2.0 + 1 / 2.0<<endl;
        for(int u = 0; u < int(min(m,n) / 2.0 + 1 / 2.0); u++){
            cout<<u<<endl;
            order.push_back(matrix[i][j]);
            if(n == 1){
                while(i + 1 < m) order.push_back(matrix[++i][j]);
                break;
            }
            while(j + 1 <= n - u - 1) order.push_back(matrix[i][++j]);
            if(i + 1 > m - u - 1) break;
            while(i + 1 <= m - u - 1) order.push_back(matrix[++i][j]);
            if(j - 1 < u && m != 1) break;
            while(j - 1 >= u && m != 1) order.push_back(matrix[i][--j]);
            
            while(i - 1 > u) order.push_back(matrix[--i][j]);
            j++;
        }
        return order;
    }
};
//使用循环次数做的 2是用赋值次数做的