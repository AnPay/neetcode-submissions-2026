class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> frequency;
        for(int n : hand)
            frequency[n]++;
        if(hand.size()%groupSize !=0)
            return 0;
        // cout<<"original\n";
        // for(auto it = frequency.begin();it!=frequency.end();it++)
        //     std::cout<<it->first<<" "<<it->second<<"\n";
        for(auto it = frequency.begin();it!=frequency.end();it++)
        {
            
            if(it->second>0)
            {
                int count = it->second;
                for(int i =0;i<groupSize;i++)
                {
                    if(frequency[(it->first) +i]<count)
                        {
                            // std::cout<<it->first<<"\n";
                            // int next = it->first+1;
                            // cout<<next<<"\n";
                            // std::cout<<frequency[next]<<" "<<it->second<<"\n";
                            return false;
                        }
                    frequency[it->first +i]-=count;
                }
            }
            // cout<<"updating\n";
            // for(auto it2 = frequency.begin();it2!=frequency.end();it2++)
            // std::cout<<it2->first<<" "<<it2->second<<"\n";
        }    
        return true;
    }
};
