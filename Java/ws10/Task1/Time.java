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

public class Time  implements  Comparable<Time>, Cloneable {

	   private long time;
	 

	    /*A no-arg constructor that constructs a Time for the
	     *  current time*/
	   public Time() 
	   {
	      time= System.currentTimeMillis()/1000;
	   }
	
	   /*A constructor with the specified hour, minute, and second 
	    * to create a Time*/
	   public Time(long h, long m, long s)
	   {
		   time = (((h * 60) + m) * 60) + s;
	   }
	   /*A constructor with the specified elapsed time since midnight,
	    *  Jan 1, 1970.*/
	   public Time(long elapsedTime)
	   {
		    this.time = elapsedTime;
	   }
	   /*The getHour() method that returns the current hour
	    *  in the range 0-23*/
	   public long getHour() 
	   {
		   return (int)(time / (3600)) % 24;
	   }
	   /*The getMinute() method that returns the current minute 
	    * in the range 0-59.*/
	   public long getMinute() 
	   {
		   return  (int)(time / 60) % 60;
	   }
	   /*The getSecond() method that returns the current second 
	    * in the range 0-59*/
	   public long getSecond() 
	   {
		   return (int)(time % 60);
	   }
	  /*8. The getSeconds() method that returns the elapsed total
	   *  seconds*/
	   public long getSeconds()
	   {
	       return time;
	   }
	   /*The toString() method that returns a string such
	    *  as "1 hour 2 minutes 1 second" and "14 hours 21 minutes 
	    *  1 second".*/
	   public String toString()
	   {
	       return String.format("%d hours %d minutes %d seconds", getHour(),
	               getMinute(), getSecond());
	   }
	   /*. Implement the Comparable<Time> interface to compare this Time with another one based on their elapse seconds.
	 The compareTo method returns the difference between this object’s elapse seconds and the another’s.*/
	   @Override
	   public int compareTo(Time t) 
	   {
		   return (int)(this.time - t.time);
	   }
	  /*. Implement the Cloneable interface to clone a Time object.*/
	   public Time clone()
	   {
	       Time T2 = new Time();
	       T2.time = time;
	       return T2;
	   }
	  
//	   public boolean equals(Time T)
//	   {
//	       return T.time == time;
//	   }



	}