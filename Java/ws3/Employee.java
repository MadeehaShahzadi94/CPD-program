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

public abstract class Employee implements Payable 
{
	//instance variables
	private String firstName;//- first name of employee
	private String lastName;//- last name of employee
	private String socialSecurityNumber;//SSN of employee

	/*********************************************************************************/
	//A Constructor
	public Employee(String first, String last, String ssn)
	{
		setFirstName(first);
		setLastName(last);
		setSocialSecurityNumber(ssn);
	}
	/*******************************************************************************/
	//Setter
	//Set the First Name of Employee
	public void setFirstName(String first)
	{
		firstName = first;
	}

	//Set the last Name of Employee
	public void setLastName(String last)
	{
		lastName = last;
	}
	//Set the Social Security Number from the Employee
	public void setSocialSecurityNumber(String ssn)
	{
		socialSecurityNumber = ssn;
	}
	/*********************************************************************************/
	//Getter
	public String getFirstName()
	{
		return firstName;
	}
	public String getLastName() 
	{
		return lastName;
	}
	public String getSocialSecurityNumber() 
	{
		return socialSecurityNumber;
	}
	/******************************************************************************/
	//String method return the Employee object
	public String toString()
	{
        return String.format( "%s %s\nSocial Security Number: %s", getFirstName(), getLastName(), getSocialSecurityNumber() );
    }
}
