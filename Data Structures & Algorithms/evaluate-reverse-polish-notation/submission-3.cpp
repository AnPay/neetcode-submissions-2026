class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string &s : tokens) {
            if (isdigit(s.back())) {
                st.push(stoi(s));
            } 
            else {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if (s == "+") st.push(b + a);
                else if (s == "-") st.push(b - a);
                else if (s == "*") st.push(b * a);
                else st.push(b / a);
            }
        }

        return st.top();
    }
};