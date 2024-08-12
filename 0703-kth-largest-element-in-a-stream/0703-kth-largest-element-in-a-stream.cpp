class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>>pq;
int kth;
    int s=0;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(s==k){
int top=pq.top();
if(top<nums[i]){
pq.pop();
pq.push(nums[i]);
}
            }
            else{

            pq.push(nums[i]);
                  s++;
            }
          
        }
        kth=k;

    }
    
    int add(int val) {
        if(s<kth){
            pq.push(val);
            s++;
        }
        else{
                    int top=pq.top();

        if(top<val){
            pq.pop();
pq.push(val);
        }
                    }

        
        return pq.top();
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
//  2 4 5 8
//  2 3 4 5 8
//  2 3 4 5 5 8
 