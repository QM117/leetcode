class Solution {
public:
    int numDecodings(string s) {
        return Decode(s);
    }
private:
    int Decode(string s) {
        if(s.size() > 0 && (s[0] - '0') == 0) return 0;
        if(s.size() == 1 && (s[0] - '0') == 0) return 0;
        if(s.size() == 1 && (s[0] - '0') != 0) return 1;
        if(s.size() == 2) {
            if((s[0] - '0') * 10 + (s[1] - '0') < 27 && (s[0] - '0') * 10 + (s[1] - '0') > 0) {
                if((s[0] - '0') != 0 && (s[1] - '0') != 0) return 2;
                else return 1;
            }
            else {
                if((s[0] - '0') != 0 && (s[1] - '0') != 0) return 1;
                else return 0;
            }
        } 
        //int L = s.size();
        int sum = 0;
        for(int i = 1; i < 3; i++) {   
            if(i == 2 && ((s[0] - '0') * 10 + (s[1] - '0') > 26 || (s[0] - '0') * 10 + (s[1] - '0') < 1)) {
                //cout<<"-1"<<endl;
                break;
            }
            
            string str = s.substr(i);
            //cout<<str<<","<<s.size()<<endl;
            sum += Decode(str);
        }
        return sum;
    }
};
//感觉上是能用的 但太慢了