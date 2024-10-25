class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>res;
        sort(folder.begin(),folder.end());
        string curr="";
        for(int i=0;i<folder.size();i++)
        {
            string str=folder[i];
            int k=0;
            string temp="";
            bool subfolder=0;
            while(k<str.length())
            {   
                temp=temp+str[k++];
                while(k<str.length() && str[k]!='/')
                {
                    temp=temp+str[k];
                    k++;
                }
                if(temp==curr)
                {
                    subfolder=1;
                    break;
                }
            }
            if(subfolder==0)
            {   
                curr=str;
                res.push_back(str);
            }
        }
        return res;
    }
};
