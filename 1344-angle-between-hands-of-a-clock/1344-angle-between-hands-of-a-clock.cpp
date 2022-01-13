class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs(30*hour-1.0*11/2*minutes);
        if (ans > 180) return (360 - ans);
        return ans;
    }
};