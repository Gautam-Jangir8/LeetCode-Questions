class Solution {
public:
    static bool comp(string &a, string &b) {
        return a.size()>b.size();
    }

    vector<int> findLPS(string word) {
        int n = word.size();
        vector<int>lps(n, 0);

        int pre = 0, suf = 1;
        while(suf<n) {
            if(word[pre]==word[suf]) {
                lps[suf] = pre+1;
                pre++;
                suf++;
            } else { // There will be two case this time
                if(pre==0) {
                    suf++;
                } else {
                    pre = lps[pre-1];
                }
            }
        }

        return lps;
    }

    vector<string> findMatchingString(vector<string>& words) {
        vector<string>ans;
        int n = words.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                vector<int>lps = findLPS(words[j]);

                int p=0, q=0;
                while(p<words[i].size()) {
                    if(words[i][p]==words[j][q]) {
                        p++;
                        q++;
                    }
                    if(q==words[j].size()) {
                        ans.push_back(words[j]);
                        break;
                    } else if(p<words[i].size() && words[i][p]!=words[j][q]) {
                        if(q==0) {
                            p++;
                        } else {
                            q = lps[q-1];
                        }
                    }
                }
            }
        }

         // Remove duplicates using a set
        set<string> uniqueWords(ans.begin(), ans.end());
        return vector<string>(uniqueWords.begin(), uniqueWords.end());
    }

    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), comp);

        return findMatchingString(words);
    }
};