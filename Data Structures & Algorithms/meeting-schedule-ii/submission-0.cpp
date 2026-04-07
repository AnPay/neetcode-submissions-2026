/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
/*
min number if MRs=nuumber of conflicts*/
bool mycompare(const Interval& a, const Interval& b)
{
    if(a.start==b.start)
        return a.end<b.end;
    return a.start<b.start;
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), mycompare);
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto& interval: intervals)
        {
            //room free
            if(!pq.empty() && interval.start>=pq.top())
               pq.pop();
            pq.push(interval.end);

        }    
        return pq.size();
    }
};
