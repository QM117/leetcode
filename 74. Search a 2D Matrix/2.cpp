class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int front = 0, back = m * n - 1;
        int mid = 0;
        while(front <= back){
            mid = (front + back) / 2;
            if(matrix[mid / n][mid % n] < target)
                front = mid + 1;
            else if(matrix[mid / n][mid % n] > target)
                back = mid - 1;
            else return matrix[mid / n][mid % n] == target;
        }
        return false;
    }
};