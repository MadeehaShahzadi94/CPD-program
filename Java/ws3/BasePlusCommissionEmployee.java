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

public class BasePlusCommissionEmployee extends CommissionEmployee
{
	
	// instance variable
	private double baseSalary;

/***************************************A constructor *****************************************************************/

	public BasePlusCommissionEmployee(String first, String last, String ssn, double sales, double rate, double salary) 
	{
		// super class is called Employee's first and last Name, ssn 
		// rate is added to the commissionEmployee.	
		super(first,last,ssn, sales, rate);
		setBaseSalary(salary);
	
}
/*************************************************Setter*************************************************************************/	
	public void setBaseSalary( double salary )
	{
	if (baseSalary < 0.0)                   
        throw new IllegalArgumentException(
           "Base salary must be greater or equal to 0.0");  

     this.baseSalary = salary; 
	}
/************************************************Getter*************************************************************************/
	public double getBaseSalary()
	{
		return baseSalary;
	} 
/*************************************************Interface*********************************************************************/	
	public double getPaymentAmount() 
	{
		return getBaseSalary() + super.getPaymentAmount();
	}

/*************************************************Override************************************************************************/
	public String toString()
	{
		return String.format("%s %s%n%s: %.2f", "Base-Salaried",super.toString(), "Base Salary", getBaseSalary());   
	}
}
