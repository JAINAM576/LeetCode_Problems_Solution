class Solution {
    public static String reverseParentheses(String s) {
    StringBuffer updatedString=new StringBuffer(s);
    int n=s.length();
    for (int i=0;i<n;i++) {
        if(s.charAt(i)==')'){
            int lastIndexOf=updatedString.substring(0, i).lastIndexOf("(");
           
            StringBuffer s1=new StringBuffer(updatedString.substring(lastIndexOf+1,i));
          
            s1.reverse();
        updatedString.replace(lastIndexOf+1, i, s1.toString());
        updatedString.setCharAt(lastIndexOf, 'A');
        updatedString.setCharAt(i, 'A');
       



        }
    }
    
    s=updatedString.toString();
   return s.replaceAll("A", "");
     
    }
}