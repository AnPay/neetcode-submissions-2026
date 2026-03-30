class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Method 1:
        // unordered_map<int, int> HT;

        // for(int a : nums)
        // {
        //     // if(HT.find(a)!=HT.end())
        //     //     HT[a]++;
        //     // else
        //     //     HT[a]=1;
        //     HT[a]++;
        // }
        // vector<pair<int,int>> arr;
        // for(auto p : HT)
        //     arr.push_back({p.second,p.first});
        // sort(arr.rbegin(),arr.rend());
        // vector<int>res;
        // for(int i =0;i<k;i++)
        //     res.push_back(arr[i].second);
        
        // return res;

        //Method 2:
        unordered_map<int, int> HT;

        for(int a : nums)
        {
            HT[a]++;
        }
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto p : HT)
            {
                heap.push({p.second,p.first});
                if(heap.size() > k)
                    heap.pop();
            }
        for(int i =0;i<k;i++){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
