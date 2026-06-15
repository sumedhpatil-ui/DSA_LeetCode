class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int temp = n;
        while(temp != 0){
            digitSum += temp % 10;
            temp = temp / 10;
        }
        int squareSum = 0;
        temp = n;
        while(temp != 0){
            int digit = temp % 10;
            temp = temp / 10;
            squareSum += digit*digit;
        }
        return squareSum - digitSum >= 50;
    }
};