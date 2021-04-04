/**********************************************
Workshop # 4
Course:<JAC444> - Semester
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<October 18th 2020>
**********************************************/
package work_shop4;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

import java.util.Scanner;

public class Coronavirus {

	public static File openFile(String value) throws FileNotFoundException {
		File file = new File(value);
		//Object //system;
		//System.out.println(" pakistan");

		// Check if file exists
		if (!file.exists()) {
			System.out.print("File " + file.getName() + " does not exist");
			System.exit(1);
		}
		return file;
	}
   public static void main(String[] args) throws FileNotFoundException {

       // TODO Auto-generated method stub
//ASCII
       int count[] = new int[257];
       
       try {

           System.out.print("Enter a file name: ");

           @SuppressWarnings("resource")
		Scanner keyboard = new Scanner(System.in);

           String inputfileName = keyboard.nextLine();
           
           openFile(inputfileName);

           Scanner sc = new Scanner(new File(inputfileName));
                 

           while (sc.hasNextLine()) {

               String input = sc.nextLine();

               if (input.isEmpty())

                   continue;

              // input = input.toUpperCase() + input.toLowerCase();
               //input = input.toLowerCase();
               for(int i=0;i<input.length();++i)

                   count[input.charAt(i)]++;
               		
           }

       } catch (IOException e) {

           e.printStackTrace();

       }
       
       for(int i=65;i<=90;++i){

           System.out.printf("Number of %c's is: %d\n",i,count[i] );
          
           

       }
       System.out.println();
       for(int j =97; j<=122;++j) {
    	   System.out.printf("Number of %c's is: %d\n",j,count[j] );
       }
      
   }

}
