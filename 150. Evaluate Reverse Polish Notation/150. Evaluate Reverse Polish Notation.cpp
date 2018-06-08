class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        int l = tokens.size();
        stack <int> stk;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "-") stk.push(atoi(tokens[i].c_str()));
            else {
                int A = stk.top();
                stk.pop();
                int B = stk.top();
                stk.pop();
                int C;
                if(tokens[i] == "*")  C = B * A;
                else if(tokens[i] == "/")  C = B / A;
                else if(tokens[i] == "-")  C = B - A;
                else if(tokens[i] == "+")  C = B + A;
                stk.push(C);
            }
        }
        return stk.top();

    }
};
//主要问题是string转int 之前可以用- '0' 的方法 这里只能用atoi了