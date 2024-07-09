class Solution {
public double averageWaitingTime(int[][] customers) {
long timestamp = 0, sum = 0;
for(int[] customer : customers){
if(timestamp<customer[0]) timestamp =timestamp+ (customer[0]-timestamp);
timestamp+=customer[1];
sum+= timestamp - customer[0];
}
return (double) sum/customers.length;
}
}