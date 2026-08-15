class Solution {
private:
    int calc(char ch, int a, int b){
        switch(ch){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }

public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(string token : tokens){

            if(token != "+" && token != "-" && token != "*" && token != "/"){
                st.push(stoi(token));
            }
            else{
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                st.push(calc(token[0], a, b));
            }
        }

        return st.top();
    }
};