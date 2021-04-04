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

public class Testing {
	public static void main( String args[] )
	   {
		// First creates for objects, one for each subclass of Employee
		  SalariedEmployee salariedEmployee =  new SalariedEmployee( "John", "Smith", "111-11-1111", 800.00 );
		  HourlyEmployee hourlyEmployee =  new HourlyEmployee( "James", "Bond", "222-22-2222", 16.75, 40 );
		  CommissionEmployee commissionEmployee = new CommissionEmployee(  "Rafiq", "Ahmad", "333-33-3333", 10000, .06 );
		  BasePlusCommissionEmployee basePlusCommissionEmployee = new BasePlusCommissionEmployee( "Waseem", "Ahmad", "444-44-4444", 5000, .04, 300 );
		 
	      System.out.println( "Display all employee by in row:\n" );
		      
		  System.out.printf( "%s\n%s: $%,.2f\n\n", salariedEmployee, "earned", salariedEmployee.getPaymentAmount() );
		  System.out.printf( "%s\n%s: $%,.2f\n\n",hourlyEmployee, "earned", hourlyEmployee.getPaymentAmount() );
		  System.out.printf( "%s\n%s: $%,.2f\n\n",commissionEmployee, "earned", commissionEmployee.getPaymentAmount() );
		  System.out.printf( "%s\n%s: $%,.2f\n\n",  basePlusCommissionEmployee,  "earned", basePlusCommissionEmployee.getPaymentAmount() );
		 
		       // create four-element Employee array
		  Employee employees[] = new Employee[ 4 ]; 
		  
		        // initialize array with Employees
		  employees[ 0 ] = salariedEmployee;
		  employees[ 1 ] = hourlyEmployee;
	      employees[ 2 ] = commissionEmployee; 
		  employees[ 3 ] = basePlusCommissionEmployee;
		 
		  System.out.println( "Employees processed polymorphically:\n" );
		      
		        // generically process each element in array employees
		  for ( Employee currentEmployee : employees ) 
		  {
		  System.out.println( currentEmployee ); // invokes toString
		 
		          // determine whether element is a BasePlusCommissionEmployee
		  if ( currentEmployee instanceof BasePlusCommissionEmployee ) 
		          {
		             // downcast Employee reference to 
		             // BasePlusCommissionEmployee reference
		    BasePlusCommissionEmployee employee = ( BasePlusCommissionEmployee ) currentEmployee;
		 
		             double oldBaseSalary = employee.getBaseSalary();
		            employee.setBaseSalary( 1.10 * oldBaseSalary );
		             System.out.printf( "new base salary with 10%% increase is: $%,.2f\n", employee.getBaseSalary() );
		         } 
		 
		           System.out.printf( 
		             "earned $%,.2f\n\n", currentEmployee.getPaymentAmount() );
		      } 
		  
		      // get type name of each object in employees array
		       for ( int j = 0; j < employees.length; j++ )
		           System.out.printf( "Employee %d is a %s\n", j, 
		              employees[ j ].getClass().getName() ); 
	   } 
}
