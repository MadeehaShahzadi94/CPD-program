/**********************************************
Workshop # 8 task 1
Course:<JAV444> - Semester Fall
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<23 November 2020>
**********************************************/
package work_shop8;

public class Tester
{
	 	private final static int size = 2000;
	 	
	    private static double[][] matrix = new double[size][size];
	    
	    private static double[][] matrix2 = new double[size][size];
/************************************************************************************************************/
	    public static void main(String[] args) 
	    {
	        
	    	for (int i = 0; i < matrix.length; i++)
	    	{
	 		   for (int j = 0; j < matrix2[i].length; j++) 
	 		   {
	 			  matrix[i][j] = Math.random();
	 			 matrix2[i][j] = Math.random();
	 		   }
	 		 }
	 		  long currentTime = System.currentTimeMillis();
	 		  
	 		//For Parallel Adding Matrix Timing
	 		  Parallel.parallelAddMatrix(matrix, matrix2);
	 		  long neededTime=System.currentTimeMillis()-currentTime;
	 		  System.out.println("****************************** Results ****************************************");
	 		 System.out.println("**                                                                           **");
	 		  System.out.println("===============================================================================");
	 		  System.out.println( "==   Parallel adding Matrix timing is : "+neededTime + " Millisecond                       ==");
	 		  System.out.println("===============================================================================");
	 		//For Sequential Adding Matrix Timing
	 		
	 		  Parallel.sequentialAddMatrix(matrix, matrix2);
	 		  neededTime=System.currentTimeMillis()-currentTime;
	 		 System.out.println("===============================================================================");
	 		  System.out.println("==     Sequential adding Matrix timming is: "+neededTime + " Millisecond                   ==");
	 		 System.out.println("===============================================================================");
	 		 }
	   
}
