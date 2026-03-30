class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> HT;
        for(int a : nums)
        {
            // if(HT.find(a)!=HT.end())
            //     HT[a]++;
            // else
            //     HT[a]=1;
            HT[a]++;
        }
        vector<pair<int,int>> arr;
        for(auto p : HT)
            arr.push_back({p.second,p.first});
        sort(arr.rbegin(),arr.rend());
        vector<int>res;
        for(int i =0;i<k;i++)
            res.push_back(arr[i].second);
        
        return res;
    }
};
