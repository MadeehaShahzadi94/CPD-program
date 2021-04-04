/**********************************************
Workshop # 5
Course:<JAC444> - Semester
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<30 OCT 2020>
**********************************************/
package application;
/******************************************************************************************************************/
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import work_shop5.AddressBook;
import java.io.*;
import java.io.RandomAccessFile;
/*****************************************************************************************************************/
public class Main extends Application
{
	protected AddressBook address_book = new AddressBook();
// give the first Name, last Name, City, State, postal Code and Count
	final int fNAME = 31; 
	final int lNAME = 32;
	final int CITY = 20; 
	final int PROVINCE = 2; 
	final int ZIP = 6; // Postal Code
	protected int count = 0;
/****************************************************************************************************************/
	@SuppressWarnings("exports")
	@Override 
	public void start(Stage primaryStage) 
	{
		//lambda Functions for buttons
		address_book.add.setOnAction(e -> add());
		address_book.first.setOnAction(e -> first());
		address_book.next.setOnAction(e -> next());
		address_book.previous.setOnAction(e -> previous());
		address_book.last.setOnAction(e -> last());
		address_book.update.setOnAction(e -> update());
/**************************************************************************************************************************/
		// Create a box
		Scene scene = new Scene(address_book, 460, 200);
		primaryStage.setTitle("Address Book"); 
		primaryStage.setScene(scene); 
		primaryStage.show(); 
	}
/************************************************************************************************************************/
	//Add the data in the file
	private void add() {
		try
		( 
				RandomAccessFile file = new RandomAccessFile("src/application/AddressBook.txt", "rw");
		) 
		{
			file.seek(file.length());
			 	write(file);
		}
			catch (FileNotFoundException ex)
		{
				System.out.println("file is not exist");
		}
			catch (IOException ex) 
		{
				System.out.println("error");
		}
			catch (IndexOutOfBoundsException ex)
		{
				System.out.println("error");
		}
	}
/*******************************************************************************************************************/
	// Go the first row of the data
	private void first() 
	{
		try
		( 
			RandomAccessFile file = new RandomAccessFile("src/application/AddressBook.txt", "rw");
		)
		{
			if (file.length() > 0)
			{
				file.seek(0);
				read(file);
				System.out.println("Go to the First Adress");
				count = 1;
			}
			else
			{
				System.out.println("Address is empty!");
			}
		}
		catch (IOException ex)
		{
			System.out.println("error");
		}
	}
/**************************************************************************************************************/
	// Next Button 
	private void next()
	{
		try 
		( 
			RandomAccessFile file = new RandomAccessFile("src/application/AddressBook.txt", "rw");
		)
		{
			if (count * 91 < file.length())
			{
				file.seek(count * 91);
				read(file);
				count++;
				System.out.println("Next is " + count);
			}
			else
			{
				System.out.println("End of file!");
			}
		}
		catch (IOException ex)
		{
			System.out.println("error");
		}
	}

/*************************************************************************************************************************/
	// previous person row enter in the data
	private void previous()
	{
		try 
		( 
			RandomAccessFile file = new RandomAccessFile("src/application/AddressBook.txt", "rw");
		) 
		{
			if (count > 1) 
				count--;
			else
				count = 1;
			file.seek((count * 91) - 91);
			read(file);
			System.out.println("Previous Person data is" + count);
		}
		catch (IOException ex) 
		{
			System.out.println("error");
		}
	}

/****************************************************************************************************************/
//Last Person data
	private void last() 
	{
		try 
		( 
			RandomAccessFile file = new RandomAccessFile("src/application/AddressBook.txt", "rw");
		) 
		{
			count = ((int)file.length()) / 91;
			file.seek((count * 91) - 91);
			read(file);
			System.out.println("Last person Data is" + count);
		}
		catch (IOException ex) 
		{
			System.out.println("error");
		}
	}

/**********************************************************************************************************************/
// Update the data through random file function
	private void update() 
	{
		try 
		( 
			RandomAccessFile file = new RandomAccessFile("src/application/AddressBook.txt", "rw");
		) 
		{
		 	file.seek((count * 91) - 91);
		 	write(file);
		 	 System.out.println("Updating information of person no." + count);  
		}
		catch (FileNotFoundException ex)
		{
			System.out.println("ierror");
		}
		catch (IOException ex)
		{
			System.out.println("error");
		}
	}
	/************************************************************************************************************/
//Fix length string for storing each attribute in the address
	private byte[] fixedLength(byte[] x, int n) {
		byte[] b = new byte[n];
		for (int i = 0; i < x.length; i++) {
			b[i] = x[i];
		}
		return b;
	}
/*****************************************************************************************************************/
// Write Function
private void write(RandomAccessFile file) throws IOException 
{
		file.write(fixedLength(address_book.fName.getText().getBytes(), fNAME)); 
		file.write(fixedLength(address_book.lName.getText().getBytes(), lNAME)); 
		file.write(fixedLength(address_book.city.getText().getBytes(), CITY));
		file.write(fixedLength(address_book.province.getValue().getBytes(), PROVINCE));
		file.write(fixedLength(address_book.zip.getText().getBytes(), ZIP));
		System.out.println("Address saved!");
	}


/*****************************************************************************************************************/
//Read Functions
	private void read(RandomAccessFile in) throws IOException 
	{
		//Read First Name
		byte[] fname = new byte[fNAME];	
		@SuppressWarnings("unused")
		int pos = in.read(fname);
		address_book.fName.setText(new String(fname));
		/*===========================================================================================================*/
		//Read Last Name
		byte[] lname = new byte[lNAME];	
		pos = in.read(lname);
		address_book.lName.setText(new String(lname));
		/*===========================================================================================================*/
		// Read city
		byte[] city = new byte[CITY];	
		pos += in.read(city);
		address_book.city.setText(new String(city));
 	   /*===========================================================================================================*/
		//Read province
		byte[] prov = new byte[PROVINCE];	
		pos += in.read(prov);
		address_book.province.setPromptText(new String(prov));

		/*===========================================================================================================*/
		// Read postal code
		byte[] zip = new byte[ZIP];	
		pos += in.read(zip);
		address_book.zip.setText(new String(zip));

	}
	public static void main(String[] args) {
		launch(args);
	}
	
}
