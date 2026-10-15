class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> days(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                int prev = st.top();
                st.pop();

                days[prev] = i - prev;
            }

            st.push(i);
        }

        return days;
    }
};