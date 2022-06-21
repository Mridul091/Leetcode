class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          int n = heights.size();
            stack < int > st;
         vector<long long> leftsmall(n,-1);
        vector<long long> rightsmall(n,n);
          for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
              st.pop();
            }
            if(!st.empty())
              leftsmall[i] = st.top();
            st.push(i);
          }
          // clear the stack to be re-used
          while (!st.empty())
            st.pop();

          for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
              st.pop();

            // if (st.empty())
            //   rightsmall[i] = n - 1;
            if(!st.empty())
              rightsmall[i] = st.top();

            st.push(i);
          }
          long long  maxA = 0;
          for (int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i]-1));
          }
          return maxA;
    }
    };