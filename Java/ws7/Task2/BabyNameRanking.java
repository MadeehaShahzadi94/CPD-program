/**********************************************
Workshop # 7
Course:<JAV444> - Semester Fall
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<submission date> November 17th 2020
**********************************************/

package work_shop7;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class BabyNameRanking {

	   public static void main(String[] args)
	   {
	       String filename;
	       @SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
	         
	       ArrayList<String> boys = new ArrayList<String>();
	       ArrayList<String> girls = new ArrayList<String>();
	       ArrayList<String> commonName = new ArrayList<String>();

	       System.out.print("Enter a filename for baby name ranking: ");
	       filename = in.nextLine();
	      
	       loadFile(filename, boys, girls);
	       findCommonNames(boys, girls, commonName);
	       printCommonNames(commonName);
	   }
	  
	   private static void loadFile(String filename, ArrayList<String> boys, ArrayList<String> girls)
	   {
	       try 
	       {
	           Scanner File = new Scanner(new File("C:\\Users\\owner\\Desktop\\Babynames files\\Babynames files\\",filename));
	           while(File.hasNext())
	           {
	               String line = File.nextLine();
	               String[] values = line.split("\\s+");
	               boys.add(values[1]);
	               girls.add(values[3]);
	           }
	           File.close();
	       } catch (FileNotFoundException e) {
	           System.out.println(e.getMessage());
	           System.exit(1);
	       }
	      
	   }
	  
	   private static void findCommonNames(ArrayList<String> boys, ArrayList<String> girls, ArrayList<String> common)
	   {
	       for(String b: boys)
	       {
	           if(girls.contains(b))
	               common.add(b);
	       }
	   }
	  
	   private static void printCommonNames( ArrayList<String> common)
	   {
	       System.out.println(common.size() + " names are used for both genders They are");
	       for(String s:common)
	           System.out.print(" " + s);
	          
	       System.out.println();
	   }
	}
