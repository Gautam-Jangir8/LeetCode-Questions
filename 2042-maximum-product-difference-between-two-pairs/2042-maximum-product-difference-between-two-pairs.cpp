class Solution {
public:
    int maxProductDifference(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;
        maxpq.push(nums[0]);
        maxpq.push(nums[1]);
        minpq.push(nums[0]);
        minpq.push(nums[1]);

        for (int i = 2; i < n; i++)
        {
            int curr = nums[i];
            if (curr > minpq.top())
            {
                minpq.pop();
                minpq.push(curr);
            }
            if (curr < maxpq.top())
            {
                maxpq.pop();
                maxpq.push(curr);
            }
        }

        int x = maxpq.top(), a = minpq.top();
        maxpq.pop();
        minpq.pop();
        int y = maxpq.top(), b = minpq.top();
        return (a * b) - (x * y);
    }
};