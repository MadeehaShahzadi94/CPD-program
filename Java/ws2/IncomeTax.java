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

class IncomeTax
{
	//1. filling Status: 4  0 to 3
	 int fillingStatus;
	
	//2. Use the constants
	public static final int SINGLE_FILER = 0;
	public static final int MARRIED_JOINTLY_OR_QUALIFYING_WIDOW = 1;
	public static final int MARRIED_SEPARATELY = 2;
	public static final int HEAD_OF_HOUSEHOLD = 3;
	
	/*3. A double-dimension array (You decide the type of it) named intervals: Stores the tax intervals/ brackets
	for each filing status.*/
	
	private int[][]intervals;
	/*. A single-dimension array (You decide the type) named rates: Stores the tax rates for each interval. */
	private double[] rates;
	/* */
	private double taxableIncome; // Income on which tax can be applied
	
	//default constructor
	public IncomeTax()
	{
		fillingStatus = SINGLE_FILER;
		taxableIncome = 0.0;
	}
	//Overloads constructors
	public IncomeTax(int status, int[][] bracks, double[] rate, double taxIncome) 
	{
		setFilingStatus(fillingStatus);
		setIntervals(intervals);
		setRates(rates);
		setTaxableIncome(taxableIncome);
		//taxableIncome = 0.0;
	}
	
	//Setter
	//1. Set the filling status and pas the parameter status
	public void setFilingStatus(int status){
		fillingStatus = (status >= SINGLE_FILER && status <= HEAD_OF_HOUSEHOLD) ? status : SINGLE_FILER;
		this.taxableIncome = status;
	}
	//2. Set the brackets with the value supplied through parameter
	public void setIntervals(int[][] bracket) {
		intervals = bracket.clone(); 	// Will initialize brackets with the exact same value applied through parameters.
	}
	//3. To set the Rates applied in parameters
	public void setRates(double[] rate) {
		rates = rate.clone(); 
	}
	//4. To set the taxable Income using applied parameter
	public void setTaxableIncome(double taxIncome) {
		taxableIncome = taxIncome; 
	}
	
	//getters
		//1. return the filling status
		
		public int getFillingStatus()
		{
			return fillingStatus;
		}
		
		//2. get the brackets
		// we have the two dimensional array
		public int[][] getIntervals()
		{
			return intervals;
		}
		//3. get the rate
		public double[] getRate() 
		{
			return rates;
		}
//		//4. get the tax wali Income
		public double getTaxableIncome() {
			return taxableIncome;
		}
		//5. return the tax
	public double getIncomeTax(){
double tax = 0.0;
		
		for(int i=0; i<intervals[fillingStatus].length; i++)
		{
			if(i == 0) // First
			{
				if(taxableIncome >= intervals[fillingStatus][i])
					tax += intervals[fillingStatus][i] * rates[i];
				else
				{
					tax += taxableIncome * rates[i];
					break;
				}
			}
			else if(i == (intervals[fillingStatus].length - 1)) // Last
			{
				if(taxableIncome >= intervals[fillingStatus][i])
					tax += (taxableIncome - intervals[fillingStatus][i - 1]) * rates[i];
			}
			else
			{
				if(taxableIncome >= intervals[fillingStatus][i])
					tax += (intervals[fillingStatus][i] - intervals[fillingStatus][i - 1]) * rates[i];
				else
				{
					tax += (taxableIncome - intervals[fillingStatus][i - 1]) * rates[i];
					break;
				}
			}			
		}
		
		return tax;
	}
}
