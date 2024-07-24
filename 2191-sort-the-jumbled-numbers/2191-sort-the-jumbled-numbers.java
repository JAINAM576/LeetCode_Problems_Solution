class Solution {
    public int[] shuffledDecimal(int[] mapping, int[] nums){
        int n=nums.length;
        int [] shuffledSystem=new int[n];
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                shuffledSystem[i]=mapping[nums[i]];
                continue;
            }
            int j=0;
            int res=0;
            int digit=nums[i];
            while(digit>0){
                int last=digit%10;
                int newdigit=mapping[last];
                res=newdigit*(int)Math.pow(10,j)+res;
                digit=digit/10;
                j++;
            }
             shuffledSystem[i]=res;

        }
        return  shuffledSystem;
    }
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n=nums.length;
        int [] shuffledSystem=shuffledDecimal(mapping,nums);
        Integer index[]=new Integer[n];
        for(Integer i=0;i<n;i++){
            index[i]=i;
        }
        Arrays.sort(index,new Comparator<Integer>(){
            public int compare(Integer a,Integer b){
                return shuffledSystem[a]-shuffledSystem[b];
            }

        });
        int res[]=new int[n];
        for(int i=0;i<n;i++){
            res[i]=nums[index[i]];
        }


return res;
    }
}