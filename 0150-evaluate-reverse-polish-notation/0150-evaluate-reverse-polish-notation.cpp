class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string ch : tokens){
           if(ch == "+" || ch == "-" || ch == "*" || ch == "/"){
              int first = st.top();
              st.pop();
              int sec = st.top();
              st.pop();

              if(ch == "+") st.push(sec+first);
              else if(ch == "-") st.push(sec-first);
              else if(ch == "*") st.push(sec*first);
              else st.push(sec/first);
           }
           else{
            int num = stoi(ch);
            st.push(num);
           }
        }
        return st.top();
    }
};