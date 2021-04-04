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



public class Parallel implements Runnable
{
	//(matrix1)+(matrix2) = (Result)
    private double[][] matrix1;
    		//+
    private double[][] matrix2;
    		//=
    private static double[][] combined;
    private int s, e,s1,e1;
    public Parallel(double[][] m1, double[][] m2, int start, int end) {
        matrix1 = m1;
        matrix2 = m2;
        s = start;
        e = end;
    }
/*********************************************************************************************************************************/
    // parallelAddMatrix
    public static  double[][] parallelAddMatrix(double[][] a, double[][] b)
    {
    	 int size = a.length;
         combined = new double[size][size];

         Parallel p1 = new Parallel(a,b,0, size/4);
         Parallel p2 = new Parallel(a,b,size/4+1, size/2);
         Parallel p3 = new Parallel(a,b,size/2+1,size/4*3);
         Parallel p4 = new Parallel(a,b,size/4*3+1, size);

         Thread t1 = new Thread(p1);
         Thread t2 = new Thread(p2);
         Thread t3 = new Thread(p3);
         Thread t4 = new Thread(p4);

       
         t1.start();
         t2.start();
         t3.start();
         t4.start();
        

         return combined;
    }
  /*****************************************************************************************************************************/
    
    
/*******************************************************************************************************************************/ 
    //sequentialAddMatrix function
    public static double[][] sequentialAddMatrix(double[][] a, double[][] b) 
    {
    	int i, j=0;
    	double[][] result = new double[a.length][a[0].length];
		  for ( i = 0; i < a.length; i++) 
		  {
		   for ( j = 0; j < a[i].length; j++) 
		   {
		    result[i][j] = a[i][j] + b[i][j];   
		   }
		  }
		  return result;
    }
   /****************************************************************************************************************************/

    @Override
    public void run() {
    	int i;
    	int j;
        for( i = s; i < e; i++) 
        {
        	  for(j = this.s1; j < this.e1; j++) 
        	  {
                combined[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
}
