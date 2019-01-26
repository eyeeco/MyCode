class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> job;
        for(int i=0; i<profit.size(); i++) {
            job.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(job.begin(), job.end()); sort(worker.begin(), worker.end());
        int i = 0, maxp = 0, res = 0;
        for(int ch:worker){
            while(i<difficulty.size()&&ch>=job[i].first) maxp = max(maxp, job[i++].second);
            res += maxp;
        }
        return res;
    }
};
