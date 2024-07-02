class Solution {
public:
int findMaxi(vector<int>& nums1){
    int maxi=INT_MIN;
    for(int i:nums1)
    {
        maxi=max(maxi,i);
    }
    return maxi;
}
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int maxi=findMaxi(nums1);
        vector<int> countinSort(maxi+1,0);
        for(int i:nums1){
            countinSort[i]++;
        }
        for(int i:nums2){
            if(i<=maxi && countinSort[i]>0){
ans.push_back(i);
countinSort[i]--;
            }
        }
        return ans;
    }
};