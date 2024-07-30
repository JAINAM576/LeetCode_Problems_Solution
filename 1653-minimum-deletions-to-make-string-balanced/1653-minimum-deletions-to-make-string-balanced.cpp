class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> rightA(n);

        vector<int> leftB(n);
        int miniMum = INT_MAX;
        // cout<<n<<endl;
       
      
    

        for (int i = 1; i < n; i++) {
            if (s[i-1] == 'a') {
             
                leftB[i] = leftB[i - 1];
            } else if (s[i-1] == 'b') {
                leftB[i] = leftB[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (s[i+1] == 'a') {
                rightA[i] = rightA[i + 1] + 1;
               
            } else if (s[i+1] == 'b') {
              
                rightA[i] = rightA[i + 1];
            }
        }

        for (int i = 0; i < n ; i++) {
            int ans = leftB[i]+rightA[i];
            
          
            miniMum = min(ans, miniMum);
        }
        return n==1?0:miniMum;
    }
};

// [a,a,b,a,b,b,a,b]
//  0 1 2 3 4 5 6 7
//    L R
//  a-1 3
//  b-0 4
//  ans =3

//  a-2 2
//  b-0 4
//  ans=2

//  a-2 2
//  b-1 3
//  ans=3

//  a-3 1
//  b-1 3
//  ans=2

//  a-3 1
//  b-2 2
//  ans=3

//  a-3 1
//  b-3 1
//  ans=4

//  a-4 0
//  b-3 1
//  ans=3

//  a-4 0
//  b-4 0
