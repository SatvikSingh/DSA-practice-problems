class Solution {
public:
    typedef long long ll;
    
    static bool compare(vector<ll>& a, vector<ll>& b) {
        if (a[1] == b[1])
            return a[0] > b[0];
        
        return a[1] < b[1];
    }
    
    static bool compare_desc(vector<ll>& a, vector<ll>& b) {
        return a[0] > b[0];
    }
    
    long long minimumMoney(vector<vector<int>>& transactions) {
        ll ans = 0, n = transactions.size();
        vector<vector<ll>> arr1, arr2;
        
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
        
        // cout << arr2.size() << endl;
        
        for (auto i : arr1) {
            arr2.push_back({i[0], i[1]});
        }
        
        ans = arr2[0][0];
        
        for (int i = 0; i < arr2.size()-1; i++) {
            ll temp = arr2[i+1][0] - arr2[i][1];
            
            if (temp > 0)
                ans += temp;
        }
        
        return ans;
    }
};