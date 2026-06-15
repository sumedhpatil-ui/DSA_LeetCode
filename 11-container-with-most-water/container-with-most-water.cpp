class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0;
        int right = n - 1;

        while(left <= right)
        {
            int length = abs(left - right);
            int breadth = min(height[left], height[right]);
            int area = length * breadth;
            ans = max(ans, area);
            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        return ans;
    }
};