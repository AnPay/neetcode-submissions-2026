class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>positionSpeed(position.size());
        for(int i =0;i<position.size();i++)
        {
            positionSpeed[i].first = position[i];
            positionSpeed[i].second = speed[i];
        }    
        sort(positionSpeed.begin(),positionSpeed.end());
        stack<pair<int,int>>fleetStack;
        for(int i=positionSpeed.size()-1;i>=0;i--)
        { 
            double ttc = (double)(target - positionSpeed[i].first) / positionSpeed[i].second;
            if(fleetStack.empty())
                fleetStack.push(positionSpeed[i]);
            else
            {
                int pos = fleetStack.top().first;
                int spd = fleetStack.top().second;
                double tt = (double)(target-pos)/spd;
                double ttc = (double)(target - positionSpeed[i].first)/positionSpeed[i].second;
               // double ttc = (double)(target - positionSpeed[i].first) / positionSpeed[i].second;
                cout<<tt<<" "<<ttc;
                if(ttc > tt)
                    fleetStack.push(positionSpeed[i]);    
            }
        }
        return fleetStack.size();
    }
};
/*
1 ->3
4->2
1
3,6,9,10
2,4,6,8,10

2,4,6,8,10
2,4,6,8,10
1,2,3,4,5,6
7,10


1,3      4,2

0,1 | 1,2 |4,2 | 7,1
*/