class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double ans = 30*hour-1.0*11/2*minutes;
        return min(abs(ans),360-abs(ans));
    }
};