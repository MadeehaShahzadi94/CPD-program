/**********************************************
Workshop # 3
Course:<JAC444> - Semester
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date:<Oct 09,2020>
**********************************************/
package work_shop3;

public class CommissionEmployee extends Employee {
	//instance variables
	private double grossSale;
	private double commissionRate;
	
	/*******************************************************************************************/
	//A Constructor
	public CommissionEmployee(String first, String last, String ssn, double sales, double rate) {
	
		// taking value from the Employee
		super(first, last, ssn);
		setGrossSale(sales);
		setCommissionRate(rate);
	}
	/*****************************************************************************************************/
	//Setter
	//throw an exception when sales less than 0.0
	public void setGrossSale(double sales)
	{
		if(sales<= 0.0) 
			throw new IllegalArgumentException("Incorrect Gross Sales");
		this.grossSale = sales;
		
	}
	//commission rate of employee
	public void setCommissionRate(double rate) {
		if (rate > 0.0 && rate < 1.0)
			commissionRate = rate;
		else
			throw new IllegalArgumentException( 
					"Commission rate must be between 0.0 and < 1.0");
	}
	/********************************************************************************************/
	//getter
	public double getCommissionRate() {
		return commissionRate;
	}
	public double getGrossSales() {
		return grossSale;
	}
	/****************************************************************************************/
	//Overrides toString method in class Employee 
	//returns String representation of CommissionEmployee Object.
	 public String toString()
	   {
	      return String.format( "%s: %s\n%s: $%,.2f; %s: %.2f", "Commission Employee", super.toString(), "Gross Sales", getGrossSales(), "Commission Rate", getCommissionRate() );
	   }
	@Override
	public double getPaymentAmount() {
		// TODO Auto-generated method stub
		return getCommissionRate() * getGrossSales();
	}
	
}
