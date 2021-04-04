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

public class HourlyEmployee extends Employee {
	//instance variabes
	private double wage;
	private double hours;
	
	/*****************************************************************************************/
	//Overload Constructor
	public HourlyEmployee(String first, String last, String ssn, double hourlyWage, double hoursWorked) {
		super(first,last,ssn);
		setWage(hourlyWage);
		setHours(hoursWorked);
		
	}
	/*************************************************************************/
	// Setter
	public void setWage(double hourlyWage) {
		if (hourlyWage >= 0.0)
			wage = hourlyWage;
		else
			throw new IllegalArgumentException( 
					"Hourly wage must be greater 0.0" );
	}
	public void setHours(double hoursWorked)
	{
		if ( ( hoursWorked >= 0.0 ) && ( hoursWorked <= 168.0 ) )
			hours = hoursWorked;
		else
			throw new IllegalArgumentException( 
					"Hours worked must be between 0.0 anf 168.0" );
	}
	 /**************************************************************************/
	 //getter
	 public double getWage() {
			return wage;
		}
	  public double getHours()
	   {
	      return hours;
	   }
	  /******************************************************************************/
	  /*A toString method – Overrides toString method in class Employee and returns String
		representation of HourlyEmployee Object.*/
	  public String toString()
	   {
	      return String.format( "Hourly Employee: %s\n%s: $%,.2f; %s: %,.2f",  super.toString(), "Hourly Wage", getWage(), "Hours Worked", getHours() );
	   }
	@Override
	public double getPaymentAmount() {
		// TODO Auto-generated method stub
		if(getHours()<=40) 
		{
			return getWage()*getHours();
		}else
		{
			return 40*getWage()+(getHours()-40)*getWage()*1.5;
		}
	}
}
