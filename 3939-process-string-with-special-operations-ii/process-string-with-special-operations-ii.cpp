class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        // Compute final length
        for (char c : s) {
            if (c == '*') {
                if (len > 0) len--;
            }
            else if (c == '#') {
                len *= 2;
            }
            else if (c == '%') {
                continue;
            }
            else {
                len++;
            }
        }

        if (k >= len) return '.';

        // Reverse process
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c == '*') {
                len++;
            }
            else if (c == '#') {
                len /= 2;
                if (k >= len) k -= len;
            }
            else if (c == '%') {
                k = len - 1 - k;
            }
            else {
                len--;
                if (k == len) return c;
            }
        }

        return '.';
    }
};