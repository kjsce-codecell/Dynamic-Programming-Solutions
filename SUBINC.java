/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
     int i,j,k,l,t,e,n;long m;
     
     Scanner sc = new Scanner(System.in);
     t= sc.nextInt();
     
     while(t!=0){
       
        n= sc.nextInt();
        int a[] = new int[n];
        for(i=0;i<n;i++)
           a[i]= sc.nextInt();
         //DP involves reducing time complexity at the cost of memory space
        /*Therefore an array is declared, which stores the length of subarrays 
          including the ith element, i.e dp[i] is the length of the subarray 
          which has a[i] in it*/
        int dp[] = new int[n];//Create an array to store the lengths of increasing subarrays
        dp[0]=1;   //The first element is a singleton set, the length of which is always 1
        //Traverse through the entire array
        for(i=1;i<n;i++)
        {
            /*check if the current element is greater than or equal to the previous element. If it is,
              means there is another subarray formed, which includes this element as well as the elements before the ith element,
              satisfying this condition. So the length of the subarray having ith element is length of subarray having (i-1)th
              element + 1 i.e dp[i]=dp[i-1]+1*/
            /*If a[i] is not greater than or equal to a[i-1] then the length of the subarray which has this element is just 1
              i.e dp[i]=1*/
            if(a[i]>=a[i-1])
                dp[i]=dp[i-1]+1;
            else
                dp[i]=1;
        }
        /* for the first test case the array dp is:
        A:  1 4 2 3
        dp: 1 2 1 2 
        */
        m=0;
        /*By storing the length of the subarrays containing the ith element, you are keeping track of all the singleton sets as well as
        other sets containing ith element*/
        //Take the sum of all elements of array dp, to get the length of all the increasing subarrays in the given array
          for(i=0;i<n;i++) m+=dp[i]; 
          System.out.println(m);
          t--;
     }
  }
}
