class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        priority_queue< pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
     
        for (auto& i : points){
            double x2 = (double)i[0]*(double)i[0];
            double y2 = (double)i[1]*(double)i[1];
            double dist = sqrt(x2+y2);
            pq.push({dist, {i[0], i[1]}});
        }
        for (int i = 0; i<k; i++){
            pair<double, vector<int>> tp = pq.top();
            pq.pop();
            result.push_back(tp.second);
        }
        return result;

    }
};