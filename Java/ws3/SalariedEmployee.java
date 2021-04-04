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

public class SalariedEmployee extends Employee 
{
	private double weeklySalary;
	
	//Overloaded Four-arguments constructor
	 public SalariedEmployee( String first, String last, String ssn, double salary )
	 {
		 super( first, last, ssn ); 
		 setWeeklySalary( salary ); 
	 }
	 /*****************************************************************************************/
	 //setter
	 public void setWeeklySalary( double salary )
	 {
		 if (salary >= 0.0)
				weeklySalary = salary;
			else
				throw new IllegalArgumentException("Weekly salary must be >= 0.0");
	  }
	 /***************************************************************************************/
	 
	 //getter
	 public double getWeeklySalary() {
		 return weeklySalary;
	 }
	 
	 /***************************************************************************************/
	 @Override
	 public double getPaymentAmount()
	  {
	         return getWeeklySalary();
	  } 
	 /*****************************************************************************************/
	 
	  // return String representation of SalariedEmployee object
	   public String toString()
	   {
	        return String.format( "salaried employee: %s\n%s: $%,.2f",
	           super.toString(), "weekly salary", getWeeklySalary() );
	   } 
	 
}
