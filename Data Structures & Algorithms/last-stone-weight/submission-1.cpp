class Solution {
    
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int s : stones)
            maxHeap.push(s);
        while(maxHeap.size()>1)
        {
            int first = maxHeap.top();maxHeap.pop();
            int sec = maxHeap.top();maxHeap.pop();
            if(first==sec)
                continue;
            if(sec < first)
                maxHeap.push(first-sec);
        } 
        maxHeap.push(0);
        return maxHeap.top();   
    }
};
