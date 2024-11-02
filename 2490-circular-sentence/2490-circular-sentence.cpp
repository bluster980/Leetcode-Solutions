class Solution {
public:
    bool isCircularSentence(string sentence) {
      stringstream ss(sentence);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string current = words[i];
            string next = words[(i + 1) % n];  
            if (current.back() != next.front()) {
                return false;
            }
        }
        return true;
    }
};