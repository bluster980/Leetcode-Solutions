class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maximum = 0;
        sort(points.begin(), points.end());
        for (int i = 0; i < int(points.size()); ++i) {
            map<double, int> counter;
            int temp = 0;
            for (int j =  i + 1; j < int(points.size()); ++j) {
                double slope = (double(points[j][1] - points[i][1]) / double(points[j][0] - points[i][0]));
                temp = max(temp, ++counter[slope]);
            }
            maximum = max(maximum, temp + 1);
        }

        return maximum;
    }
};