class Solution {
public:
 int countFreq(vector<int>& arr, int& i, int n) {
        int count = 1;
        while (i < n - 1 && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        return count;
    }

    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        
        // Sort the array to group the same elements together
        sort(arr.begin(), arr.end());

        // Loop through the sorted array to check if frequencies are unique
        for (int i = 0; i < n;) {
            // Get the frequency of the current element
            int count = countFreq(arr, i, n);
            i++;  // Move to the next unique element

            // Loop to check if the frequency matches with any other element's frequency
            for (int j = i; j < n;) {
                int nextCount = countFreq(arr, j, n);
                j++;  // Move to the next unique element
                
                // If any frequency matches, return false
                if (count == nextCount) {
                    return false;
                }
            }
        }

        // If no frequencies match, return true
        return true;
    }
};

/*
EXAMPLE :
ARR=[1,2,2,1,1,3]
STEPS:
step 1- sort()->[1,1,1,2,2,3]
step 2- count freq for ith element 
#iterations
i=0
-> value 1 -> count =3
# nested step 1 
- now we find if any other value has same freq
- j=i+1 -> j=2+1-> j=3 s0 value =2
- call the freq function 
- count1=2
- count!=count1 continue to the next iteration
*/