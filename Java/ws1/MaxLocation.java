/**********************************************
Workshop # 1
Course:<JAC444> - Semester 4
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<September 26,2020>
**********************************************/
import java.util.Scanner;

public class MaxLocation{
	//data member
	int row;
	int column;
	double maxValue;
	
	//default constructor
	MaxLocation(){
		row=0;
		column =0;
		maxValue=0;
		
	}
	//method that calculate the largest element in the array
	// Notes have this kind of loop
	// we are making array(matrix) rows and columns
	public static MaxLocation max(double[][] array) {
		
		//temp.maxValue= array[0][0];
		
		int i =0,j=0; 
		double maxNum = 0;
		
		//Creating object for Max Location Class
		MaxLocation location = new MaxLocation();
		//Matrix rule rows and column and get the exact position of max value
		for(i=0; i<array.length; i++) {
			for(j=0; j<array[i].length; j++) {
				if(array[i][j]>maxNum) {
					maxNum =array[i][j];
					
					location.maxValue= maxNum;
					location.row=i;
					location.column=j;
				}
				
			}
		}
		return location;
	}
	
	public static void main(String[] args) {
		//Actual output
		// get the value from user as input
		Scanner input = new Scanner(System.in);
		
        int row = 0,col = 0;
        boolean temp = true;
        
        do
        {
        	temp = true;
	        System.out.println("Enter the number:");

	        if(input.hasNextInt())
	        {
	        	row = input.nextInt();
	        	col = input.nextInt();
	        }
	        else
	        {
	        	System.out.println("Enter the Positive Numbers");
	        	temp = false;
	        }
	        if(input.hasNextLine())
	        {
	        	input.nextLine();
	        }
        }while(!temp);

        //defining 2D array to hold matrix data
        double array[][] = new double[row][col];
        
        System.out.println("Enter the array: ");
		
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                array[i][j] = input.nextFloat();
            }
        }
        
        MaxLocation location = new MaxLocation();
        location = MaxLocation.max(array);
                
        System.out.println("The location of the largest element is " + location.maxValue 
        		+ " at ("+ location.row + ","+ location.column + ")");
	
	}
}