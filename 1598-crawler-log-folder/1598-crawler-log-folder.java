class Solution {
   public static int minOperations(String[] logs) {
        int ans=0;
        for(String s:logs){
            int root=s.indexOf("/");
            int dot=s.indexOf('.');
            int backdot=s.lastIndexOf('.');
          if(root!=-1 && dot==-1)
          {
            ans++;
            
          }
          else if(root!=-1 && (dot!=backdot)){
      if(ans>0)    
            ans--;

          }
        }
       return ans;
    
    }
}