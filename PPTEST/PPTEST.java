/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    
    public static int max(int n, int w, int p[], int c[], int t[])
    {
         /*Main aim of this problem is to score maximum points by 		solving as many good questions 
        as possible in the given time*/
        int ans = 0;
	/*A 2d array knapsack is declared to keep track of points  		scored by solving questions in
        w minutes*/
        int a[][] = new int[n+1][w+1];
	 /*The 2d array knapsack, keeps track of points scored by 		solving first i qstns in every 
         j minutes less than or equal to w.*/
         /*if i=0 or j=0 i.e if there are 0 questions to solve or 		there is 0 no of minutes, 
                 the points scored is 0. Hence knapsack[i][j]=0*/ 
        for(int i=0; i<=n; i++) {
            a[i][0] = 0;
        }
        for(int i=0; i<=w; i++) {
            a[0][i] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
	/*There are two possibities of selecting ith qstn. Either you solve it or you dont.
                  You take maximum between, the score obtained by solving the first i questions and the score obtained
                  by not solving the ith qstn. The maximum between theses two is stored in knapsack[i][j].*/
                /*If i>1 you will take the maximum between, the scores you get by solving first i questions 
                  and the scores you get by solving the first (i-1) qstns in j minutes*/
                /*For i>1 if t[i-1] i.e if the time taken for solving ith question is less than or equal to j, means you can solve 
                  this current question under or in j minutes. Hence score obtained by solving this question is
                  c[i]*p[i]. We will subract t[i-1] from j and check how many points can be scored in 
                  (j-t[i-1]) minutes. This is obtained from knapsack[i-1][j-t[i-1]].This way we are checking if the first (i-1)
                  questions can be solved in remaining time (j-t[i-1]) minutes or not.  We add this values to c[i]*p[i].
                  Hence the score obtained by solving the first i questions in j minutes is ((c[i]*p[i])+knapsack[i-1][j-t[i-1]]. 
                  Next we will take maximum between the this score we just calculated and the score obtained by solving first (i-1) questions 			  in j minutes.
                  Which is knapsack[i-1][j]
                  The maximum between these two scores is the maximum scores that can be obtained by solving first i qstns in j minutes.*/
                if(j>=t[i-1])
                {
                int temp =  p[i-1]*c[i-1];   
                a[i][j] = Math.max(a[i-1][j],temp+a[i-1][j-t[i-1]]); 
                }
                else
                {
                    a[i][j] = a[i-1][j];
                }
            }
        }
        
        //The final answer, i.e the maximum score obtained by solving questions in w minutes is stored in knapsack[n][w].     
        return a[n][w];
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		
		Scanner sc = new Scanner(System.in);
		int te = sc.nextInt();
		while(te!=0)
		{
		    te--;
                    //Take the no of questions the time limit 
		    int n = sc.nextInt();
		    int w = sc.nextInt();
		    
		    int p[] = new int[n];
		    int c[] = new int[n];
		    int t[] = new int[n];
		    /*Take the no of test having ith question c[i], no 			    of points for ith qstn p[i] and the time taken 
                    ith question t[i]*/
		    for(int i=0;i<n;i++) {
		        c[i] = sc.nextInt();
		        p[i] = sc.nextInt();
		        t[i] = sc.nextInt();
		    }   
		    
		    System.out.println(max(n,w,p,c,t));
		}
	}
}

