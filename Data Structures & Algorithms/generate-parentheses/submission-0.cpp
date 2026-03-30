class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        string cand = "";
        bt(open,close,cand);
        return res;
    }
private:
    void bt(int open, int close, string &cand)
    {
        if(open==0 && close==0)
        {
            res.push_back(cand);
            return;
        }
        if(open>0)
        {
            //cand.push_back("(");
            cand = cand+"(";
            bt(open-1,close,cand);
            cand.pop_back();
        }
        if(open<close){
            cand = cand+")";
            bt(open,close-1,cand);
            cand.pop_back();
        }    
    }
};
