class Solution {
public:
    vector<string> ans;

    void solve(int index, string path, long long value, long long prev, string &num, int target) {

        if (index == num.size()) {
            if (value == target)
                ans.push_back(path);
            return;
        }

        long long curr = 0;

        for (int i = index; i < num.size(); i++) {

            // Skip numbers with leading zeros
            if (i > index && num[index] == '0')
                break;

            curr = curr * 10 + (num[i] - '0');
            string currStr = num.substr(index, i - index + 1);

            // First number
            if (index == 0) {
                solve(i + 1, currStr, curr, curr, num, target);
            }
            else {
                // +
                solve(i + 1, path + "+" + currStr, value + curr, curr, num, target);

                // -
                solve(i + 1, path + "-" + currStr, value - curr, -curr, num, target);

                // *
                solve(i + 1, path + "*" + currStr, value - prev + prev * curr, prev * curr, num, target);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(0, "", 0, 0, num, target);
        return ans;
    }
};