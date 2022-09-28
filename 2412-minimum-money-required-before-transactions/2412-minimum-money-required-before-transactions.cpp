class Solution {
public:
    typedef long long ll;
    
    static bool compare(pair<ll, ll>& a, pair<ll, ll>& b) {
        if (a.second == b.second)
            return a.first > b.first;
        
        return a.second < b.second;
    }
    
    static bool compare_desc(pair<ll, ll>& a, pair<ll, ll>& b) {
        return a.first > b.first;
    }
    
    long long minimumMoney(vector<vector<int>>& transactions) {
        ll ans = 0, n = transactions.size();
        vector<pair<ll, ll>> arr1, arr2;
        
        if (n == 1) {
            return transactions[0][0];
        }
        
        for (int i = 0; i < n; i++) {
            ll cash = transactions[i][0];
            ll cashback = transactions[i][1];
            
            if (cashback >= cash) {
                arr1.push_back({cash, cashback});
            } 
            else {
                arr2.push_back({cash, cashback});
            }
        }
        
        sort(arr1.begin(), arr1.end(), compare_desc);
        sort(arr2.begin(), arr2.end(), compare);
        
        for (auto i : arr1) {
            arr2.push_back({i.first, i.second});
        }
        
        ans = arr2[0].first;
        
        for (int i = 0; i < arr2.size()-1; i++) {
            ll temp = arr2[i+1].first - arr2[i].second;
            
            if (temp > 0)
                ans += temp;
        }
        
        return ans;
    }
};