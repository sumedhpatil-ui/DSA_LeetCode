class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int product = 1;
            int dup = n;

            while (dup > 0) {
                product *= (dup % 10);
                dup /= 10;
            }

            if (product % t == 0)
                return n;

            n++;
        }
    }
};