class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int, int>> maxPq;
        pair<int,int> candidate;
        for(int i=0; i<capital.size(); i++){
            pq.push({capital[i],profits[i]});
        }
        while((!pq.empty() || !maxPq.empty()) && k > 0){
            if (!pq.empty() && pq.top().first <= w){
                candidate = pq.top();
                maxPq.push({candidate.second,candidate.first});
                pq.pop();
            }
            else
            {
                if(!maxPq.empty()){
                    candidate = maxPq.top();
                    w += candidate.first;
                    k--;
                    maxPq.pop();
                }
                else
                    break;
            }
        }
        return w;
    }
};
