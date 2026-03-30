class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>>dict;
    string res;
    TimeMap() {
        dict.clear();
        res="";
    }
    
    void set(string key, string value, int timestamp) {
        if(dict.find(key)==dict.end())
        {
            vector<pair<string, int>> temp;
            temp.push_back({value,timestamp});
            dict.insert({key,temp});
        }
        else
            dict[key].push_back({value,timestamp});
        //return nullptr;
    }
    
    void bs(vector<pair<string,int>> &ts, int timestamp)
    {
        int size = ts.size();
        int lo =0;int hi=size-1;
        while(lo<=hi)
        {
            int mid = lo +(hi-lo)/2;
            if(ts[mid].second<=timestamp)
            {
                res=ts[mid].first;
                lo=mid+1;
            }
            else
                hi = mid-1;
        }
    }
    string get(string key, int timestamp) {
        res="";
        if(dict.find(key)==dict.end())
            return "";
        else{
            bs(dict[key],timestamp);
            return res;
        }
    }
};
