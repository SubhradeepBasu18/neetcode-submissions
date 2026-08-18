class Solution {
private:
    vector<int>findPSE(vector<int>& heights, int n){
        stack<int>st;
        vector<int>pse(n,-1);

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(!st.empty()){
                pse[i] = st.top();
            }

            st.push(i);
        }
        return pse;
    }

    vector<int>findNSE(vector<int>& heights, int n){
        stack<int>st;
        vector<int>nse(n, n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(!st.empty()){
                nse[i] = st.top();
            }

            st.push(i);
        }
        return nse;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 1) return heights[0];

        vector<int>pse = findPSE(heights, n);
        vector<int>nse = findNSE(heights, n);
        int maxi = 0;

        for(int i=0;i<n;i++){
            int width = abs(nse[i] - pse[i]) - 1;
            maxi = max(maxi, heights[i]*width);    
        }
        return maxi;
    }
};
