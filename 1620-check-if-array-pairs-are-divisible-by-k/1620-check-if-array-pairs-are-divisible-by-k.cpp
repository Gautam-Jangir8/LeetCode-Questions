class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()%2!=0) {
            return false;
        }

        unordered_map<int, int>mp;
        for(int i=0; i<arr.size(); i++) {
            arr[i] = (arr[i]%k)+k;
            if(arr[i]%k==0) {
                continue;
            }

            if(mp.empty()) {
                mp[arr[i]%k]++;
            }
            else if(mp.find(k-(arr[i]%k))!=mp.end()) {
                mp[k-(arr[i]%k)]--;

                if(mp[k-(arr[i]%k)]==0) {
                    mp.erase(k-(arr[i]%k));
                }
            } else {
                mp[arr[i]%k]++;
            }
        }

        if(mp.size()==0) {
            return true;
        }
        return false;
    }
};