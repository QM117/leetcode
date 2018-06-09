class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        if(heights.size() == 1) return heights[0];
        stack <int> stk;
        int max = 0;
        int rect = 0;
        int min = 0;
        int last = 0;
        int top = 0;
        int k = 0;
        stk.push(heights[0]);
        for(int i = 1; i < heights.size(); i++) {
            if(heights[i] >= stk.top()) stk.push(heights[i]);
            else if(heights[i] < stk.top()) {
                int j = 0;
                while(!stk.empty() && heights[i] < stk.top()) {
                    j++;
                    rect = j * stk.top();
                    if(rect > max) max = rect;
                    stk.pop();
                    //cout<<j<<endl;
                }
               
                while(j >= 0) {
                    stk.push(heights[i]);
                    j--;
                }
            }
        }
        cout<<stk.size()<<"!"<<endl;
        
        int i = 1;
        last = stk.top();
        if(last > max) max = last;
        while(!stk.empty()) {
            
            if(last == stk.top() && stk.size() > 1) {
                cout<<stk.size()<<"1"<<i<<endl;
                i++;
                stk.pop();
            }
            else {
                cout<<stk.top()<<"2"<<i<<endl;
                rect = (i - 1) * last;
                if(rect > max) max = rect;
                rect = i * stk.top();
                if(rect > max) max = rect;
                last = stk.top();
                i++;
                stk.pop();
            }

        }
        return max;
    }
};
//别人的思路 主要是使用了先对于非顺序高的部分求面积 再对于低的顺序部分求面积 使用了。empty来作为判断条件