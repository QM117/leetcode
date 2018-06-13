class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(n == 2) return 2;
        if(n > 2) {
            int s = 0;
            for(int i = 0; i < n; i++)
                s = s + numTrees(i) * numTrees(n - i - 1);
            return s;
        }
    }
};
//对 对于每个节点下面分给左右子树的结果应该是乘法计算 之前用的加法是不对的