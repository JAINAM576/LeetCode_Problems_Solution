class Solution {
      public static int minOperations(String[] logs) {
        String path="Main";
        for(String s:logs){
            int root=s.indexOf("/");
            int dot=s.indexOf('.');
            int backdot=s.lastIndexOf('.');
          if(root!=-1 && dot==-1)
          {
     
            path+="/"+s.substring(0,root);
            
          }
          else if(root!=-1 && (dot!=backdot)){
          
int indexOf=path.lastIndexOf("/");
if(indexOf!=-1)
path=path.substring(0, indexOf);

          }
        }
       return (path.split("/").length-1);
    
    }
}