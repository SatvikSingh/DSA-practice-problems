class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size(), sum = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < 2; j++) {
        //         cout << boxTypes[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        for (int i = 0; i < n; i++) {
            int temp = boxTypes[i][0];
            while (temp != 0) {
                if (truckSize == 0) 
                    break;
                sum += boxTypes[i][1];
                truckSize--;
                temp--;
            }
        }
        
        return sum;
    }
};