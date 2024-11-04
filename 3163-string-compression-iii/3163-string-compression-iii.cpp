class Solution {
public:
    string compressedString(string word) {
        int n=word.length();
        int count=1;
        string comp="";
        char last=word[0];
        for(int i=1;i<n;i++)
        {
            char c=word[i];
            if(c==last && count<9)
            {
                 count++;
            }
            else{
                cout << count << endl;
                comp+=to_string(count);
                comp+=last;
                count=1;

            }
            last=word[i];      
        }
        comp+=to_string(count);
        comp+=last;

        return comp;
        
    }
};