class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int count=0;
        for(int mid=0;mid<n-1;mid++){
            int leftless=0;
            int leftGreater=0;
            for(int i=0;i<mid;i++){
                if(rating[i]>rating[mid])leftGreater++;
                if(rating[i]<rating[mid])leftless++;
            }
               int rightless=0;
            int rightgreater=0;
            for(int i=mid+1;i<n;i++){
                if(rating[i]>rating[mid])rightgreater++;
                if(rating[i]<rating[mid])rightless++;
            }
            count+=leftless*rightgreater+leftGreater*rightless;

        }
        return count;

    }
};