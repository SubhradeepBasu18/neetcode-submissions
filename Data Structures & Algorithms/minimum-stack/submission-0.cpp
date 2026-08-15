class MinStack {
private:
    stack<int>st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> temp;
        int mini = st.top();

        while(!st.empty()){
            int val = st.top();
            st.pop();

            mini = min(mini, val);
            temp.push(val);
        }

        while(!temp.empty()){
            int val = temp.top();
            temp.pop();
            st.push(val);
        }
        return mini;
    }
};
