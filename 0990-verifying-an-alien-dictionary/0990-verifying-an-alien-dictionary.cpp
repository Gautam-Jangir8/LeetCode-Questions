class Solution {
public:

    bool isAlienSorted(vector<string>& words, string order) {
        // If there is only one word to check then, its not valid, minimum two words are required to finnd the order
        if (words.size() == 1)
        {
            return true;
        }

        // character and their rank is stored in the map
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = i;
        }

        // Traversing the array
        for (int i = 0; i < words.size() - 1; i++)
        {
            // Traverse each character in a word
            for (int j = 0; j < words[i].size(); j++)
            {
                // If all the words has matched so far and current word length is longer then the next word, then return false
                if (j >= words[i + 1].size())
                {
                    return false;
                }

                // Checking if letters in the same position in two words are different
                if (words[i][j] != words[i + 1][j])
                {
                    // Checkif the rank of the word in teh curren t word is greater then the same same charcter in the other word
                    if (mp[words[i][j]] > mp[words[i + 1][j]])
                    {
                        return false;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        return true;
    }
};