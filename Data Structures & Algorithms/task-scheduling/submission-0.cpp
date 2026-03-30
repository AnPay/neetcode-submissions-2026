class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> hash;
        for(char ch : tasks)
            hash[ch]++;
        priority_queue<pair<int,char>> maxHeap;
        unordered_map<char,int> :: iterator it;
        for(it = hash.begin();it!=hash.end();it++)
            {
                maxHeap.push({it->second,it->first});
                cout<<it->second<<it->first<<"\n";
            }
        queue<pair<int,int>>q;
        int cycle =0;
        int totCycle=0;
        
        while(!maxHeap.empty() || !q.empty())
        {
            totCycle++;
            if(!maxHeap.empty())
            {
                pair<int,char> task = maxHeap.top();
                maxHeap.pop();
                int freq = task.first-1;
                if(freq>0)
                    {
                        q.push({freq,totCycle+n});
                        cout<<task.second<<"pushed\n";
                    }
            }
            
            
            if(!q.empty() && q.front().second == totCycle) {
                maxHeap.push({q.front().first, 'A'}); 
            // char doesn't matter anymore
                 q.pop();
            }
        }
        return totCycle;
    }
};
