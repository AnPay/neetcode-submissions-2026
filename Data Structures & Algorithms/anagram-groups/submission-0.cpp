class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        //Brute force, compare each string with another if its an anagram

        //sort each string and sort the vector

        unordered_map<string,vector<string>>res;
        for(auto &s : strs)
        {
            vector<int>count(26,0);
            for(char c : s)
                count[c-'a']++;
            string key = to_string(count[0]);
            for(int i =1;i<26;i++){
                key+=','+to_string(count[i]);
            }
            res[key].push_back(s);
        }
        for(auto& pair:res)
            ans.push_back(pair.second);

        return ans;
    }
};
