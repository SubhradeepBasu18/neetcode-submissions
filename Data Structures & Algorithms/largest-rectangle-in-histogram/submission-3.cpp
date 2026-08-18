class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxi = 0;

        for(int i=0;i<n;i++){
            // for element at i found pse = st.top
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element = st.top();
                st.pop();

                int pse = st.empty() ? -1 : st.top();
                int nse = i;

                int width = nse - pse - 1;
                maxi = max(maxi, heights[element] * width);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();

            int width = nse - pse - 1;
            maxi = max(maxi, heights[element] * width);
        }
        return maxi;
    }
};
