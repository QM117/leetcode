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
        sort(intervals, 0, len - 1);
        
        
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
    void sort(vector<Interval>& x, int l, int r){
        if(l>= r) return;
        int j = depart(x, l, r);
        sort(x, l, j - 1);
        sort(x, j + 1, r);
    }
    int depart(vector<Interval>& x, int l, int r){
        int i = l, j = r + 1;
        while(true){
            while(x[l].start > x[++i].start) if(i == r) break;
            while(x[l].start < x[--j].start) if(i == l) break;
            cout<<i<<" "<<j<< endl;
            if(i >= j) break;            
            swap(x[i],x[j]);    
        }
        swap(x[l],x[j]);
        
        return j;
    }
};