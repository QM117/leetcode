class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int index = digits.size() - 1; index >= 0; index--){
            if(digits[index]!= 9){
                digits[index]++;
                break;
            }      
            else if(index != 0) digits[index] = 0;
            else {
                digits[index] = 0;
                digits.insert(digits.begin(),1);
            }
        }
        return digits;
    }
};
//简单的一题 就是题目没看明白··· 看到一个是如果全是9的话 可以将第一位置1 push_back(0) 这种思路很棒 其实是对于特殊边界条件只有一个或几个时可以针对特殊边界条件进行特殊优化。