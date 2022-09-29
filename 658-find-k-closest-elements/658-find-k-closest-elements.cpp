class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        
        int start = 0, end = n-k;
        
        while (start < end) {
            int mid = (start + end)/2;
            
            if (x - arr[mid] > arr[mid+k] - x) {
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        
        // cout << start << " " << start+k-1 << endl;
        
        for (int i = start; i < start+k; i++) {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};