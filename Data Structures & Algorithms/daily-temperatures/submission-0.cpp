class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        stack<int>st;
        vector<int>res(n,0);

        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                int ind = st.top();
                st.pop();
                res[ind] = i-ind;
            }
            st.push(i);
        }
        return res;
    }
};
