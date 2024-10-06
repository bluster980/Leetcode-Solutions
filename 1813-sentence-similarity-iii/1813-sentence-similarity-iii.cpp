class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() < sentence2.size()) {
            swap(sentence1, sentence2);
        }
        
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        int n1 = words1.size(), n2 = words2.size();
        int left = 0, right = 0;
        
        while (left < n2 && words1[left] == words2[left]) {
            left++;
        }
        
        while (right < n2 && words1[n1 - right - 1] == words2[n2 - right - 1]) {
            right++;
        }
        
        return left + right >= n2;
    }
    
private:
    vector<string> split(const string &sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};
