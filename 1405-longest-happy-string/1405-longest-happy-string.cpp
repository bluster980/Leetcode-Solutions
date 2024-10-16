class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int , char>> pq; 
    if(a>0){

        pq.push({a , 'a'});
    }

    if(b>0){

        pq.push({b , 'b'});
    }

    if(c>0){
        pq.push({c, 'c'});

    }

        string st="";

         char last='z';

        while(!pq.empty()){

            auto it =pq.top();
            int freq=it.first; 
            char ch=it.second ; 
            pq.pop();

            if(last!=ch){

                int mini=min( freq , 2);

                st.append(mini, ch);
               freq-=mini ; 
          
                last=ch;

                if(freq!=0){
                    pq.push({freq , ch});

                }

              
              continue; 

            }
                  if(pq.empty()){
                    break ; 
                  }else{
                    auto sec=pq.top();
                    pq.pop();
                    pq.push({freq , ch});

                    int secfreq=sec.first; 
                    char secch=sec.second; 

                    int secmini=min( 1 , secfreq);
                     st.append(secmini , secch);
                     secfreq-=secmini ; 

                     if(secfreq!=0){
                        pq.push({secfreq , secch});
                     }
                    last=secch; 

                   }
           
       }

   
return st; 
   }
};