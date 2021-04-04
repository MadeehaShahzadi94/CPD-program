/**********************************************
Workshop # 10
Course:<JAV444> - Semester fall
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<submission date> December 4, 2020
**********************************************/

package work_shop10;

import java.util.Scanner;

public class Tester
{
	@SuppressWarnings("resource")
	public static void main(String[] args) {
			Scanner input = new Scanner(System.in);
			System.out.print("Enter time1 (hour minute second): ");
			int hour, minute, second;
			hour = input.nextInt();
			minute = input.nextInt();
			second = input.nextInt();
			Time time1 = new Time(hour, minute, second);
			System.out.println(time1);
			System.out.println("Elapsed seconds in time1: " + time1.getSeconds());
  
			System.out.print("\nEnter time2 (elapsed time): ");
			long seconds = input.nextLong();
			Time time2 = new Time(seconds);
			System.out.println(time2);
			System.out.println("Elapsed seconds in time2: " + time2.getSeconds());
  
			System.out.println("\ntime1.compareTo(time2)? " + time1.compareTo(time2));

			Time time3 = (Time)time1.clone();
			System.out.println("\ntime1.compareTo(time3)? " + time1.compareTo(time3));
	}
}
