class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);

        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            graph[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            result.push_back(node);

            for (int n : graph[node]) {
                inDegree[n]--;
                if (inDegree[n] == 0) {
                    q.push(n);
                }
            }
        }

        if(result.size() != numCourses){
            result.clear();
        }

        return result;
    }
};