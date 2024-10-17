class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        
        unordered_map<char, int>mp;
        for(int i=0; i<chars.size(); i++) {
            mp[chars[i]]++;
        }

        for(int i=0; i<words.size(); i++) {
            unordered_map<char, int>tempMp = mp;

            string str = words[i];
            bool found = true;
            for(int j=0; j<str.size(); j++) {
                if(tempMp.find(str[j])==tempMp.end()) {
                    found = false;
                    break;
                } else {
                    tempMp[str[j]]--;
                    if(tempMp[str[j]]==0) {
                        tempMp.erase(str[j]);
                    }
                }
            }

            if(found==true) {
                ans+=str.size();
            }
        }

        return ans;
    }
};