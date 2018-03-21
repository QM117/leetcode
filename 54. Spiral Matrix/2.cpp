class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> order;
        if(matrix.empty()) return order;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0, u = 0, x = 0;
        //cout<< matrix.size() / 2.0 + 1 / 2.0<<endl;
        while(x < m * n){
            order.push_back(matrix[i][j]);
            x++;
            if(n == 1){
                while(i + 1 < m) order.push_back(matrix[++i][j]);
                break;
            }
            while(j + 1 <= n - u - 1) {order.push_back(matrix[i][++j]); x++;}
            if(x >= m * n) break;
            while(i + 1 <= m - u - 1) {order.push_back(matrix[++i][j]); x++;}
            if(x >= m * n) break;
            while(j - 1 >= u && m != 1) {order.push_back(matrix[i][--j]); x++;}         
            while(i - 1 > u) {order.push_back(matrix[--i][j]); x++;}
            j++;
            u++;
        }
        return order;
    }
};