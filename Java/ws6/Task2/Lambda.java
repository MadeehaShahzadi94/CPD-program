/**********************************************
Workshop # 6
Course:<JAV444> - Semester Fall
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature: Madeeha Shahzadi
Date:<submission date> November, 10 2020
**********************************************/

package ws6_task2;


import java.util.Scanner;

public class Lambda {
	
	//counter
	static ArrayProcessor counter( double value ) {
        return array -> {
            int count = 0;
            for (int i = 0; i < array.length; i++) {
                if ( array[i] == value )
                    count++;
            }
            return count;
        };
    }
    /************************************************************************************************************/
    //min
    public static final ArrayProcessor min = array -> {
        double min = array[0];
        for (int i = 0; i < array.length; i++) {
            if ( array[i] < min)
                min = array[i];
        }
        return min;
    };
    
    /************************************************************************************************************/
    //max
    public static final ArrayProcessor max = array -> {
        double max = array[0];
        for (int i = 0; i < array.length; i++) {
            if ( array[i] > max)
                max = array[i];
        }
        return max;
    };
    
    /************************************************************************************************************/
    //sum
    public static final ArrayProcessor sum = array -> {
        double total = 0;
        for (int i = 0; i < array.length; i++) {
            total += array[i];
        }
        return total;
    };
    
    /************************************************************************************************************/
    //avg
    public static final ArrayProcessor averager = 
            array -> sum.apply(array) / array.length;
   /************************************************************************************************************/  
            
            
    @SuppressWarnings("resource")
	public static void main(String[] args) {
                
    	 System.out.print("How many numbers you want to Proccess ? ");
         Scanner input = new Scanner(System.in);
         int size = input.nextInt();

         double[] userArray = new double[size];

         for (int i = 0; i < userArray.length; i++) {
             System.out.print("Enter Number " + (i + 1) + ": ");
             userArray[i] = input.nextDouble();
         }

         System.out.println("Maximum of the numbers you entered is  " + max.apply(userArray));
         
         System.out.println("Minimum of the numbers you entered is  " + min.apply(userArray));
         
         System.out.println("Sum of the numbers you entered is  " + sum.apply(userArray));
         
         System.out.println("Average of the numbers you entered is  " + averager.apply(userArray));
    }
    
} 
