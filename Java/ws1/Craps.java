/**********************************************
Workshop # 1
Course:<JAC444> - Semester 4
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<September 26,2020>
**********************************************/
// import the Defination
import java.util.Random;

public class Craps {
	
	
	     // method (Random function)
		// return the function a random value 1 to 6 integer
		public static int rollDice()
		{
			int randomInt = new Random().nextInt(6) + 1;
			return randomInt;
		}
		
		
	public static void main(String[] args)
	{
		// data members
		int diceOne,diceTwo,currentPoint;
		boolean flag = false;
		
		
		//i call the method that have giving me random value
		diceOne = rollDice();
		diceTwo = rollDice();
		// Sum of dice
		int sum = diceOne + diceTwo;
		int sumNum = sum;
		
		System.out.println("You rolled " + diceOne + " + " + diceTwo + " = " + sum);
		
		while(!flag) {
			
			//2 and 3 and 12 for lose
			// boolean gave us true and false
			boolean loser;
			loser = sum == 2 || sum == 3 || sum == 12;
			
			//7 and 11 for win
			// boolean gave us true and false
			boolean winner;
			winner= sum == 7 || sum == 11;
			
			if(loser)
			{
				System.out.println("Craps,Better Luck Next Time, You Lose");
				flag = true;
			}
			else if (winner)
			{
				System.out.println("Congratulations, You Win!!");
				flag = true;
			}
			else
			{
				currentPoint = sum;
				System.out.println("Point is set to " + currentPoint);
				
				do
				{
					//call the function
					diceOne = rollDice();
					diceTwo = rollDice();
					sum = diceOne + diceTwo;
					
					System.out.println("You rolled " + diceOne + " + " + diceTwo + " = " + sum);
					
					if(sum == currentPoint || sum == sumNum)
					{
						System.out.println("Congratulations, You Win!!");
						flag = true;
						break;
					}
					else if(sum == 7) 
					{
						System.out.println("Craps,Better Luck Next Time, You Lose");
						flag = true;
						break;
					}
					sumNum = sum;
					
				} while(sum != currentPoint || sum != 7);
			}	
		}
	}
	
 }
