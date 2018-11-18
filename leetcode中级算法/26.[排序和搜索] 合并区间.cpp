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
        int i=0,j=0;
        vector<Interval> res;
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start<b.start;});
        while(j<intervals.size()){
            while(j<intervals.size()-1&&intervals[j].end >= intervals[j+1].start){
                intervals[j+1].end = max(intervals[j].end,intervals[j+1].end);
                j++;
            }
            intervals[i].end = intervals[j].end;
            res.push_back(intervals[i]);
            i = j+1;
            j++;
        }
        return res;
    }
};
