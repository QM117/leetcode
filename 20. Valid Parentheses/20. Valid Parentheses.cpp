class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        stack <char> stk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
                cout<<"!"<<endl;
            }
            else if(stk.empty()) return false;
            else {
                char x = stk.top();
                if(s[i] == ')' && x != '(') return false;
                if(s[i] == '}' && x != '{') return false;
                if(s[i] == ']' && x != '[') return false;
                stk.pop();
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};
