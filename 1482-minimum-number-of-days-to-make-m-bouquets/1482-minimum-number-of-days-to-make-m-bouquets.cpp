class Solution {
public:
pair<int,int> maximumAndMinimum(vector<int>& bloomDay){
    int maximum=INT_MIN;
    int minimum=INT_MAX;

    for(int i:bloomDay){
        maximum=max(i,maximum);
        minimum=min(i,minimum);
    }
    return {minimum,maximum};
}
bool isPossible(vector<int>& bloomDay, int m, int k,int requiredDays){
    int count=0;
    int tempK=k;
    for(int i:bloomDay){
        if(tempK==0){
            count++;
            if(count>=m)return true;
            tempK=k;
        }
        if(i<=requiredDays){
            tempK--;
        }
        else{
            tempK=k;
        }
    }
    if(tempK==0){
            count++;
           
        }

    return count>=m;

}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        pair<int,int>  maximumElement=maximumAndMinimum(bloomDay);
        int s=maximumElement.first;
        int e=maximumElement.second;
        int minDays=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(bloomDay,m,k,mid)){
                minDays=min(mid,minDays);
                if(minDays==maximumElement.first)return minDays;
                e=mid-1;
            }
            else{
                s=mid+1;
            }

        }

       return  minDays==INT_MAX?-1:minDays;

    }
};