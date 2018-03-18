class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0){
            nums1 = nums2;
            return;
        }
        int add = 0;
        int i = 0, j = 0;
        while(i + j < m + n){
            if(j >= n) return;
            else if (nums1[i + add] >= nums2[j] || i >= m) {
                nums1.insert(nums1.begin() + i + add, nums2[j]);
                nums1.erase(nums1.end()-1);
                add++;
                j++;
            }
            else i++;
        }
        return;
    }
};
//简单的两有序数组融合 结果是边界条件一直没考虑好 应该在主体算法考虑完之后 就考虑所有的边界条件 比如 输入是否为0 越界处理 而且这个向量一开始就在后面补好零的 这个是我没想到的 我以为他给向量就是避开了这个数组大小的问题 对于向量的操作还要总结一下
