class Compare {
public:
	bool operator()(vector<int> a, vector<int> b) {
		return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
	}
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> minHeap;
        for( int i =0;i<points.size();i++)
        {
            minHeap.push({points[i][0],points[i][1]});
        }
        vector<vector<int>> res;
        for(int i =0;i<k;i++)
        {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;
    }
};
