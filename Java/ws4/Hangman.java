/**********************************************
Workshop # 4
Course:<JAC444> - Semester
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<October 18th 2020>
**********************************************/
package work_shop4;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
public class Hangman
{
	public static void main(String[] args) throws FileNotFoundException {
		
		// TODO Auto-generated method stub
		@SuppressWarnings("resource")
		Scanner input = new Scanner(System.in);

		String play; 
		do {
			
			char[] word = getWord();
			
			
			char[] toGuess = new char[word.length];
			filltoGuess(toGuess);

			int counter = 0;
			int i=0;
			char temp []= new char [10];
			do {
				
				char guess = getGuess(toGuess);		
				
				
				if (!isCorrectGuess(word, toGuess, guess))
				{
					boolean repeat=false;
					for (int k =0 ; k<10 ; k++) {
						if (temp[k]==guess) {
							repeat=true;
						}
					}
					temp[i]=guess;
					i++;
					
					if (!repeat) {
						counter++;
						}
				}
					
			} while (!isWordFinish(toGuess));
			
			
			print(word, counter);
			
			
			System.out.println("Do you want to guess another word? Enter y or n>");
			play = input.next();

		} while (play.charAt(0) == 'y'||play.charAt(0) =='Y' );
	}
	
	
	public static File openFile() throws FileNotFoundException {
		File file = new File("src/hangman");
		//Object //system;
		System.out.println(" pakistan");

		// Check if file exists
		if (!file.exists()) {
			System.out.print("File " + file.getName() + " does not exist");
			System.exit(1);
		}
		return file;
	}
	
	public static char[] getWord() throws FileNotFoundException {
		File file = openFile();

	 	// Create an ArrayList
		ArrayList<String> words = new ArrayList<>();
		try (
			// Create input file
			Scanner input = new Scanner(file);
		) {
			while (input.hasNext()) {
				words.add(input.next());
			}
		}

		// Pick a random string
		String pick = words.get((int)(Math.random() * words.size()));

		// Convert string to character array
		char[] word = pick.toCharArray();
	
		return word;
	}

	
	public static void filltoGuess(char[] list) {
		for (int i = 0; i < list.length; i++) {
			list[i] = '*';
		}
	}

	
	public static boolean isCorrectGuess(char[] word, char[] blanks, char guess) {
		boolean correct = false;
		int message = 2;
		for (int i = 0; i < word.length; i++) {
			if (word[i] == guess) {
				correct = true;
				if (blanks[i] == guess)
					message = 1;
				else { 
					blanks[i] = guess; 
					message = 0;
				}
			}
		}
		if (message > 0)
			print(message, guess);
		return correct;
	}

	
	public static boolean isWordFinish(char[] blanks) {
		for (char e: blanks) {
			if (e == '*')
				return false;
		}
		return true;
	}

	
	public static void print(char[] word, int counter) {
		System.out.print("The word is ");
		System.out.print(word);
		System.out.println(" You missed " + counter + " time");
	}

	
	public static void print(int m, char guess) {
		System.out.print("\t" + guess);
		switch (m) {
			case 1 : System.out.println(" is already in the word"); break;
			case 2 : System.out.println(" is not in the word");
		}
	}

	
	public static char getGuess(char[] toGuess){
		Scanner input = new Scanner(System.in);
		System.out.print("(Guess) Enter a letter in word ");
		System.out.print(toGuess);
		System.out.print(" > ");
		String g = input.next();
		return g.charAt(0);

	}
		
}