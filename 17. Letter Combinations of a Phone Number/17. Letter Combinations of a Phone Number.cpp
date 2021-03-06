class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        if(digits.length() <= 0) return output;
        string S = "";
        string list[12] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letter(0,digits.length(),S,output,digits, list);
        return output;
    }
    void letter(int l, int L, string S, vector<string>& output, string digits, string list[]) {
        if(l >= L) {
            output.push_back(S);
            return;
        }
        for(int i = 0; i < list[digits[l] - '0'].length(); i++) letter(l+1,L,S + list[digits[l] - '0'][i], output,digits, list);
    }
};
//回顾了字符串的用法 不知道为什么字符串数组的应用要用list[] 这个方法也不是很简洁 最重要的是将char类型转换成int 这里是使用的别人的-'0'方法 这里的相减是char的用法 对于string里的[x]是char类型 计算ASCII码的差值来实现的