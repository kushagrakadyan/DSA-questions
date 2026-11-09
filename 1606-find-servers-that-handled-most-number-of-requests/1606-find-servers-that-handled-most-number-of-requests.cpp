class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> s;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> cnt(k,0);
        for(int i=0;i<k;i++) s.insert(i);
            for(int i=0;i<arrival.size();i++){
                while(!pq.empty() && pq.top().first<=arrival[i]){
                    s.insert(pq.top().second);
                    pq.pop();
                }
                if(s.empty()) continue;
                auto it=s.lower_bound(i%k);
                if(it==s.end()) it=s.begin();
                int id=*it;
                s.erase(it);
                cnt[id]++;
                pq.push({arrival[i]+load[i],id});
            }
            int mx=*max_element(cnt.begin(),cnt.end());
            vector<int> ans;
            for(int i=0;i<k;i++){
                if(cnt[i]==mx) ans.push_back(i);
            }
            return ans;
    }
};