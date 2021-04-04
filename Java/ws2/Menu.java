/**********************************************
Workshop # 2
Course:<JAC444> - Semester 4
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<October 2nd,2020>
**********************************************/
package work_shop2;
import java.util.Scanner;
import java.text.DecimalFormat;
public class Menu {
	public static void main(String[] args) {
		
		/*Using two dimensional we have to define the 2001 and 2009 data range*/
		// 2001 Income range
		int[][] brackets2001 = {
				{ 27050, 65550,  136750, 297350, 297351,297351 },//0
				{ 45200, 109250, 166500, 297350, 297351, 297351},//1
				{ 22600, 54625,  83250,  148675, 148676,148676 },//2
				{ 36250, 93650,  151650, 297350, 297351,297351 } //3
		};
				
		// 2009 Income range
		int[][] brackets2009 = {
				{ 8350,  33950, 82250,  171550, 372950, 372951 },
				{ 16700, 67900, 137050, 208850, 372950, 372951 },
				{ 8350,  33950, 68525,  104425, 186475, 186476 },
				{ 11950, 45500, 117450, 190200, 372950, 372951 }
		};
				
				// Rates for year 2009
		double[] rates2009 = { 0.1, 0.15, 0.25, 0.28, 0.33, 0.35 };
		
				// Rates for year 2001
		double[] rates2001 = { 0.15, 0.275, 0.305, 0.355, 0.391 };
		
				// Use the scanner functionality.
		@SuppressWarnings("resource")
		Scanner input = new Scanner (System.in);
		System.out.println("1. Compute personal Income Tax");
		System.out.println("2. Print the tax tables for taxable income(with range)");
		System.out.println("3. Exit\n");
		
		System.out.println("===================================================");
		System.out.println("Welcome! Please choose an option:");
		int option =input.nextInt();
		switch(option) {
		//Choose:1
		case (1):
			System.out.println("===================================================");
			System.out.println("===========Compute Personal Income Tax=============");
			System.out.println("===================================================");
			System.out.println("0 - Single Filer");
			System.out.println("1 - Married Jointly Or Qualifying Widow(er)");
			System.out.println("2 - Married Separately");
			System.out.println("3 - Head of Household");
			System.out.println("===================================================");
			System.out.println("Please Enter the filing Status: ");
			int status;
			status= input.nextInt();
			
			System.out.println("Please Enter the Taxable Income: ");
			int taxableIn;
			taxableIn = input.nextInt();
			
			
	// Create the object that have to set and get the data
			IncomeTax tax = new IncomeTax();
			tax.setFilingStatus(status);
			tax.setIntervals(brackets2009);
			tax.setRates(rates2009);
			tax.setTaxableIncome(taxableIn);
			double t = tax.getIncomeTax();
			
			System.out.println("Tax is: $" + new DecimalFormat("0.00").format(t));
			break;
			
			
			
		case(2): 
			System.out.print("Enter the amount From: $");
		int from = input.nextInt();
		
		System.out.print("Enter the amount To: $");
		int to = input.nextInt();
		
		System.out.println();
		
		String nf = "%1$-13s"; // format control
		String nfl = "%1$-9s %2$-9s %3$-10s %4$-10s %5$-10s";// format control
		
		System.out.println("2001 tax tables for taxable income from $" + new DecimalFormat(",###").format(from) + " to $" + new DecimalFormat(",###").format(to));
		System.out.println("----------------------------------------------------------------------------------");
		System.out.format(nfl, "Taxable", "Single", "Married Joint", "  Married", "    Head of");
		System.out.println("");
		System.out.format(nfl, "Income", "", "or Qualifying", "  Separate", "    a House");
		System.out.println("");
		System.out.format(nfl, "", "", "   Widow(er)", "", "");
		System.out.println("");
		System.out.println("----------------------------------------------------------------------------------");
		
		//2001
		IncomeTax tax2001 = new IncomeTax();
		tax2001.setIntervals(brackets2001);
		tax2001.setRates(rates2001);
		
		double start = from;
		while(start <= to)
		{
			System.out.print(start + "   ");
			for(int i=IncomeTax.SINGLE_FILER; i<=IncomeTax.HEAD_OF_HOUSEHOLD; i++)
			{
				tax2001.setFilingStatus(i);
				tax2001.setTaxableIncome(start);
				System.out.format(nf,  tax2001.getIncomeTax());
			}
			System.out.println();
			start += 1000;				
		}
		System.out.println();
		System.out.println();
			
			System.out.println("2009 tax tables for taxable income from $" + new DecimalFormat(",###").format(from) + " to $" + new DecimalFormat(",###").format(to));
			System.out.println("----------------------------------------------------------------------------------");
			System.out.format(nfl, "Taxable", "Single", "Married Joint", "  Married", "    Head of");
			System.out.println("");
			System.out.format(nfl, "Income", "", "or Qualifying", "  Separate", "    a House");
			System.out.println("");
			System.out.format(nfl, "", "", "   Widow(er)", "", "");
			System.out.println("");
			System.out.println("----------------------------------------------------------------------------------");
			
			IncomeTax tax2009 = new IncomeTax();
			tax2009.setIntervals(brackets2009);
			tax2009.setRates(rates2009);
			
			start = from;
			while(start <= to)
			{
				System.out.print(start + "   ");
				for(int i=IncomeTax.SINGLE_FILER; i<=IncomeTax.HEAD_OF_HOUSEHOLD; i++)
				{
					tax2009.setFilingStatus(i);
					tax2009.setTaxableIncome(start);
					System.out.format(nf,  tax2009.getIncomeTax());
				}
				System.out.println();
				start += 1000;	
		}
	break;
		case(3):
		System.out.println("Exit, See you Next Year");
		break;
		default:
			System.out.println("Have a Nice day");
		
		}
}
}
