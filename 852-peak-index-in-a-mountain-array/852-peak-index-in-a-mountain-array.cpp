class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        int start = 0, end = n-1;
        
        while (start < end) {
            int mid = (start + end)/2;
            
            if (arr[mid] > arr[mid+1])
                end = mid;
            else
                start = mid+1;
        }
        
        return start;
    }
};