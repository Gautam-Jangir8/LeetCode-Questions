class Solution {
public:
    bool checkorder(char a, char b, string& order) {
        int indexA = -1, indexB = -1;

        for(int i=0; i<order.length(); i++) {
            if(order[i]==a) {
                indexA = i;
            }
            if(order[i]==b) {
                indexB = i;
            }
        }

        return indexA<indexB;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<words.size()-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];

            int len = max(s1.size(), s2.size());
            bool foundDifference = false;
            for(int ptr=0; ptr<len; ptr++) {
                if(s1[ptr]!=s2[ptr]) {
                    if(!checkorder(s1[ptr], s2[ptr], order)) {
                        return false;
                    }
                    foundDifference = true;
                    break;
                }
            }
            if(!foundDifference && s1.size() > s2.size()) { // case of apple comes before app
                return false;
            }
        }

        return true;
    }
};