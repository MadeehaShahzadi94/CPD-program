/**********************************************
Workshop # 10 task 2
Course:<JAV444> - Semester Fall
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature: Madeeha Shahzadi
Date:<December 06,2020>
**********************************************/
package task2;

import java.util.*;
public class Bank
{
	public static void main(String[] args) 
	{
		Scanner input=new Scanner(System.in);
		int n = 0;
		int limit = 0;
		int i,m,num,j;
		boolean unsafe=true;
		System.out.print("Enter number of banks and saftey limit: ");
		n=input.nextInt();
		limit=input.nextInt();
		
		double [][]bank=new double[n][n];
		
		double[]balance=new double[n];
		
		double[]starting=new double[n];
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
            bank[i][j]=0;
			starting[i]=0;
		}
		
		System.out.println("1. Balance:");
		System.out.println("2.Number of banks Loaned: ");
		System.out.println("3. Bank ID who gets the loan:");
		System.out.println("4.Loaned Amount");
			
		for(i=0;i<n;i++)
		{
			System.out.print("For bank "+(i+1)+": ");
			starting[i]=input.nextDouble();
			m=input.nextInt();
			for(j=0;j<m;j++)
			{
				num=input.nextInt();
				bank[i][num]=input.nextDouble();
			}
		}

		//check balance after borrowed
		while(unsafe)
		{
			unsafe=false;
				for(i=0;i<n;i++)
			{
				if(starting[i]>0)
				{
					balance[i]=starting[i];
					for(j=0;j<n;j++)
						balance[i]+=bank[i][j];
					if(balance[i]<limit)
					{
						unsafe=true;
						starting[i]=0;
						for(j=0;j<n;j++) 
						{
								bank[j][i]=0;
						}
					}
        
				}
   
			}
		}
		System.out.println("Unsafe banks are Bank ");
		for(i=0;i<n;i++) 
		{
				if(balance[i]<limit)
					System.out.print(i+" ");
		}	

	}

}
