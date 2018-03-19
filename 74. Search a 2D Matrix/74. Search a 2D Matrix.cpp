class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        //cout<<m<<" "<<n<<endl;
        int row = 0; 
        if (m != 1){
            for (int i = 1; i < m; i++){
                //cout<< "?" <<endl;
                if (target >= matrix[i - 1][0] && target <= matrix[i][0]){
                    
                    //cout<< "!" <<endl;
                    if (target == matrix[i - 1][0] || target == matrix[i][0]) return true;
                    row = i - 1;
                    break;
                }
                row = i;
            }
        }
        
        if (n == 1) {
            if (target == matrix[row][n - 1]) return true;
            else return false;
        }
        else {
            for (int i = 1; i < n; i++){
                //cout<< row <<endl;
                if (target >= matrix[row][i - 1] && target <= matrix[row][i]){
                    if (target == matrix[row][i - 1] || target == matrix[row][i]) return true;
                    else return false;
                }
            }
        }
        return false;
    }
};
//这题可以完全用单一数组的查找来写 这里用的是先纵列查找 在横向查找 比较麻烦 对于列数为1的数据还得单独判断 这增加了复杂度 2是用二分查找做的 