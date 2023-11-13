class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int x;
        int y;
        int z;

        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();
            z = y-x;
            if(z>0){
                pq.push(z);
            }    
        }
        if(pq.size()==1){
            return pq.top();
        }else{
            return 0;
        }
    }
};