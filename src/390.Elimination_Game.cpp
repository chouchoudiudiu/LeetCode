class Solution {
public:
    int lastRemaining(int n) {
        int left = 1, right = n, step = 1, last = n;
        int cnt = n; //the number left
        bool left2right = true;
        while (cnt > 1) {
            cnt = (right - left)/(2*step);
            if (left2right) {
                last = left + cnt*step*2;
                right = (last == right) ? right - step: right;
                left += step;
            }
            else {
                last = right - cnt*step*2;
                left = (last == left) ? left + step : left;
                right -= step;
            }
            step *= 2;
            left2right = !left2right;
        }
        return left2right ? right : left; //kill self first
    }
};
