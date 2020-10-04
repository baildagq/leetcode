#include "./utils.h"
#define PI 3.14159265

class Solution {
public:
    double val = 180 / PI;
    vector<float> angles; // the angle of start-point and start-x positive line
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int res = 0;
        int size = points.size();
        int zeronum = 0;
        // 计算角度
        for (int i = 0;i < size; i++) {
            vector<int>& p = points[i];
            int diffx = p[0] - location[0];
            int diffy = p[1] - location[1];
            if (diffx == 0) {
                if (diffy == 0) {
                    zeronum += 1;
                    continue;
                } else {
                    if (diffy > 0) angles.push_back(90);
                    else angles.push_back(270);
                    continue;
                }
            }
            double ret = atan2(diffy, diffx) * val;
            if (ret < 0) ret += 360;
            angles.push_back(ret);
        }
        sort(angles.begin(), angles.end());

        size = angles.size();
        for (int i = 0; i < size; i++) {
            int num = 0;
            int minangle = angles[i];
            int maxangle = angles[i] + angle;

            for (int j = 0; j < size; j++) {
                if (minangle <= angles[j]) {
                    if (angles[j] <= maxangle) {
                        num += 1;
                    }
                } else {
                    if (angles[j] + 360 <= maxangle) {
                        num += 1;
                    }
                }
            } 
            res = max(res, num);
        }
        return res + zeronum;
    }
};



int main(int argc, const char** argv)
{
    // vector<int> list = {2,3,-2,4};
    // printf("res: %d\n", Solution().xxx(list));
    // double val = 180 / PI;
    // printf("%lf\n", atan2(double(1), double(-1)) * val);
    // printf("%lf\n", atan2(double(-1), double(-1)) * val);
    // printf("%lf\n", atan2(double(-1), double(1)) * val);
    // printf("%lf\n", atan2(double(-1), double(-1)) * val);

    vector<vector<int>> lists = {{2, 2}};
    int angle = 0;
    vector<int> start = {1, 1};
    printf("%d\n", Solution().visiblePoints(lists, angle, start));
    return 0;
}
