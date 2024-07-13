class Solution {
public:


    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[positions[i]]=i;
        }
sort(positions.begin(),positions.end());
        stack<int> Right;
        for(int i=0;i<n;i++){




            if(directions[mp[positions[i]]]=='R'){
                Right.push(mp[positions[i]]);
            }
            else{
                if(Right.empty())continue;
                while(!Right.empty()){
                    if(healths[Right.top()]<healths[mp[positions[i]]]){
healths[mp[positions[i]]]--;
healths[Right.top()]=-1;
Right.pop();
                    }
                    else if(healths[Right.top()]>healths[mp[positions[i]]]){
                        healths[Right.top()]--;
                        healths[mp[positions[i]]]=-1;
                        break;


                    }
                    else{
healths[Right.top()]=-1;
                        healths[mp[positions[i]]]=-1;
Right.pop();
break;


                    }
                }
            }

        }


        for(int i=0;i<n;i++){
            if(healths[i]!=-1){
                ans.push_back(healths[i]);
            }
        }




        
        
        
      


return ans;
    }
};


// [2,3] -> R
// [5,6] -> L

// [15,10]   
// [10,12]



// [1,5]-> R
// [2,6] -> L

// [10,11]
// [11,10]


// [{1,10},{5,11}] -> R

// [{2,10},{6,11}] -> L



// [{1,11},{5,11}] -> R

// [{2,10},{6,12}] -> L





// 1->0 
// 5->2
// 2->1
// 6->3


// [10,10,11,11]

// [10,-1,11,-1]
// [-1,-1,-1,-1]
