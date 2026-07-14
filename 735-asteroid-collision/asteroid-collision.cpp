class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int x : asteroids) {
            bool alive = true;

            while (alive && !st.empty() && st.top() > 0 && x < 0) {
                if (st.top() < -x) {
                    st.pop();              // stack asteroid destroyed
                }
                else if (st.top() == -x) {
                    st.pop();              // both destroyed
                    alive = false;
                }
                else {
                    alive = false;         // current asteroid destroyed
                }
            }

            if (alive)
                st.push(x);
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};