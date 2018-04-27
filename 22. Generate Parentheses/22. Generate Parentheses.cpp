class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> k;
        string S;
        cout<<S+S<<endl;
        par(n,n,k,S);
        return k;
    }
    void par(int l, int r, vector<string>& s, string S) {
        if(l == 0 && r == 0){
            s.push_back(S);
            return;
        }
        else {
            if(l > 0) par(l - 1, r, s, S + '(');
            if(r > 0 && l < r) par(l, r - 1, s, S + ')');
        }

    }
};
// 别人的方法 主要还是知道了对于多条路径的递归如何使用 