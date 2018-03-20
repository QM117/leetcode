/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return intervals;
        int len = intervals.size();
        for(int i = 1; i < len; i++){
            for(int j = i; j > 0 && intervals[j - 1].start > intervals[j].start; j--)
           {
                         //   cout<<j<<" "<<i<<endl;
                    swap(intervals[j - 1],intervals[j]);                    
            }

        }
        
        //cout<<"1"<<endl;
        for(int i = 1; i < len; i++){
            if(intervals[i - 1].end >= intervals[i].start){
                if(intervals[i].start > intervals[i - 1].start)
                    intervals[i].start = intervals[i - 1].start;
                if(intervals[i].end < intervals[i - 1].end)
                    intervals[i].end = intervals[i - 1].end;
                intervals.erase(intervals.begin() + (i--) - 1);
                len--;
            }
        }
        return intervals;
    }
};
//想法是先排序 后删除元素 这是一个插入排序 2 是快排 快排果然非常不熟 好吧 别人直接用的sort函数。。。