class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double ans = abs(30*hour-1.0*11/2*minutes);
        return min(ans,360-ans);
    }
};