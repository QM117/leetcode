class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n == 0) return;
        if (m == 0){
            for (int x = 0; x < n; x++) A[x] = B[x];
            return;
        }
        int C[m + n];
        int i = 0,j = 0;
        while (i + j < m + n){
            if (i >= m && j<n){
                C[i + j] = B[j];
                j++;
            }
            else if (i < m && j >= n){
                C[i + j] = A[i];
                i++;
            }
            else if(A[i] <= B[j]){
                C[i + j] = A[i];
                i++;
            }
            else if(A[i] > B[j]){
                C[i + j] = B[j];
                j++;
            }
        }
        for (int x = 0; x < m + n; x++) A[x] = C[x];
        return;
    }
};
//这是数组的 但是用另一个数组赋值过来的 看了解答 是反向遍历比较然后再从A的尾部赋值 不用开辟新的存储空间 对于边界条件 有2种想法 一是将边界条件优先放入算法中考虑 使之优先级高于主体算法 其次是 将边界去掉 先考虑算法主体 然后主体出循环再考虑边界 避开了同时考虑边界与主体的做法