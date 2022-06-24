class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0, n = target.size();
        
        priority_queue<int> q;
        
        for (long long i = 0; i < n; i++) {
            q.push(target[i]);
            sum += target[i];
        }
        
        while (sum > 1 and q.top() > sum/2) {
            long long temp = q.top();
            q.pop();
            sum -= temp;
            if (sum <= 1) {
                return sum;
            }
            long long rem = temp % sum;
            q.push(rem);
            sum += rem;
        }
        
        if (sum == n)
            return true;
        return false;
    }
};