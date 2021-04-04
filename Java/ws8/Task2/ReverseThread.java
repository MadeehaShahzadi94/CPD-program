/**********************************************
Workshop # 8 task 2
Course:<JAV444> - Semester Fall
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<23 November 2020>
**********************************************/

package task2_ws8;

public class ReverseThread implements Runnable {
	
	    private static int counter;
	    public static void main(String[] args) {

	        Thread[] t = new Thread[50];
	        for(int i = 49; i >=0; i--) {
	            t[i] = new Thread(new ReverseThread());
	            counter = i+1;
	            t[i].start();

	            try {
	                t[i].join();
	            } catch (InterruptedException e) {
	                e.printStackTrace();
	            }
	        }
	    }

	    public void run() {
	        System.out.println("Hello from the Thread " + "< " +counter+ " >");
	    }

	}
