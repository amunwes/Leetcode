class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        unordered_map<char,int> counts;

        for(auto& i: tasks){
            counts[i] += 1;
        }
        for (auto i = counts.begin(); i != counts.end(); i++){
            pq.push(i->second);
        } 

        int time = 0;

        while(!pq.empty() || !q.empty()){
            ++time;
            if(!pq.empty()){
                if(pq.top()-1){
                    q.push({pq.top()-1, time + n});
                }
                pq.pop();
            }
            if (!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;

    }
};
