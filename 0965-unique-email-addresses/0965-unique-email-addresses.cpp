class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>set;
        int n = emails.size();

        for(int i=0; i<n; i++) {
            string local = "";
            string domain = "";

            string temp = emails[i];
            bool occur = false;
            for(int j=0; j<temp.size(); j++) {
                if(temp[j]=='@') {
                    domain = temp.substr(j+1);   
                    break;
                }
                else if(temp[j]=='.' || occur==true) {
                    continue;
                }
                else if(temp[j]=='+') {
                    occur = true;
                } 
                else {
                    local+=temp[j];
                }
            }
            set.insert(local+" "+domain);
        }

        return set.size();
    }
};