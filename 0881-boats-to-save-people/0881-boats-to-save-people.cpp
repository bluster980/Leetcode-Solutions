class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count=0;
        for(int i=0; i<people.size(); i++)
            if(i==people.size()) {break;}
            else if(people[i]+people.back() <= limit && (i!=people.size())){
                count++;
                people.pop_back();
            }
            else{
                while(people.size()>i && people[i]+people.back()>limit && (i!=people.size())){
                    count++;
                    people.pop_back();
                }
                if(people.size()>i) {count++; people.pop_back();}
            }           
            return count;   
        }
};