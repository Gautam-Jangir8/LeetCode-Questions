class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool>prime(n+1, true);
        prime[0] = prime[1] = false; // As 0 and 1 is not prime

        for(int i=2; i<n; i++) {
            if(prime[i]) { // If prime of i is true
                count++;
                // Now marking its multiple as notPrime
                for(int j=i*2; j<n; j=j+i) {
                    prime[j] = false;
                }
            }
        }
        
        return count;
    }
};