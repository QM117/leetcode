class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(compare_str(beginWord,endWord)) return 2;
        int Len = wordList.size();
        vector<int> length_path;
        bool flag = false;
        for(int i = 0; i < Len; i++)
            if(endWord == wordList[i])
                flag = true;
        cout<<flag<<endl;
        if(flag == false) return 0;
        for(int i = 0; i < Len; i++)
            if(compare_str(beginWord,wordList[i]))
                {
                int temp = ladder(endWord, wordList, i, Len);
                if(temp != 0) length_path.push_back(temp + 1);
                else length_path.push_back(0);
            }
        int Len_path = length_path.size();
        if(length_path.empty()) return 0;
        int min = length_path[0];
        for(int i = 0; i < Len_path; i++)
            if(length_path[i] != 0 && length_path[i] < min)
                min = length_path[i];
        cout<<length_path[0]<<"@"<<endl;
        if(min == 0) return 0;
        else return min + 1;
    }
    bool compare_str(string s1, string s2){
        int len = s1.size();
        int diff = 0;
        for(int i = 0; i < len; i++)
            if(s1[i] != s2[i])
                diff++;
        if(diff == 1) return true;
        else return false;
    }
    int ladder(string endWord, vector<string>& wordList, int x, int Len) {
        cout<<wordList[x]<<endl;
        if(compare_str(endWord,wordList[x])) return 1;
        vector<int> path;        
        for(int i = x + 1; i < Len; i++)
            if(compare_str(wordList[x],wordList[i])){
                int temp = ladder(endWord, wordList, i, Len);
                if(temp != 0) path.push_back(temp + 1);
                else path.push_back(0);
            }
        if(path.empty()) return 0;
        int min = path[0];
        int L = path.size();
        for(int i = 0; i < L; i++)
            if(path[i] < min)
                min = path[i];
        cout<<min<<"!"<<L<<endl;
        return min;
    }
};
//这是错误解法 别人用的是广度优先搜索 等我看完了再回来做 这里主要问题是 正常循环方法 会很难处理死循环的问题 导致边界条件过多