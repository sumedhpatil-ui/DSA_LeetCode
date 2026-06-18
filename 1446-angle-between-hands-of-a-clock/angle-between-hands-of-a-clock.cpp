class Solution {
public:
    double angleClock(int hour, int minutes) {
        double tetha = abs((30 * hour) - (11 * minutes / 2.0));
        if(tetha > 180)
            tetha = 360 - tetha;
        return tetha;
    }
};