class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long sum=(long long)cost1*need1+(long long)cost2*need2;

        long long mn=min(need1,need2);
        long long mx=max(need1,need2);

        long long ans=mn*costBoth;
        ans+=(long long)(need1-mn)*cost1;
        ans+=(long long)(need2-mn)*cost2;

        long long extra=(long long)mx*costBoth;
        return min({sum,ans,extra});
        
    }
};