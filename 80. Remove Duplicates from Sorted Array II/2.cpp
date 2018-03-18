链接：https://www.nowcoder.com/questionTerminal/567f420f12ed4069b7e1d1520719d409
来源：牛客网

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2) return n;
        int index=2;//允许重复两次，可以修改为三次
        for(int i=2;i<n;i++)
        {
            if(A[i]!=A[index-2])//允许重复两次，可以修改为三次
                A[index++]=A[i];
        }
         
        return index;
    }
};