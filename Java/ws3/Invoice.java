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

public class Invoice implements Payable {
	private String partNumber;
	private String partDescription;
	private int quantity;
	private double pricePerItem;
	
	//Construtor
	public Invoice(String part, String description, int count, double price) {
		setPartNumber(part);
		setPartDescription(description);
		setQuantity(count);
		setPricePerItem(price);
		
	}
	
	
	//setter
	public void setPartNumber(String part) {
		partNumber = part;
	}
	public void setPartDescription(String description) {
		partDescription= description;
	}
	public void setQuantity(int count)
	{
		if(count <0)
		{
			quantity =count;
		}
	}
	public void setPricePerItem(double price)
	{
		if(price <0.0) 
		{
			pricePerItem = price;
		}
	}
	
	//getter
	public String getPartNumber()
	{
		return partNumber;
	}
	public String getPartDescription() 
	{
		return partDescription;
		
	}
	public int getQuantity() 
	{
		return quantity;
	}
	public double getPricePerItem()
	{
		return pricePerItem;
	}
	public String toString() {
		  return String.format( "%s: \n%s: %s (%s) \n%s: %d \n%s: $%,.2f","invoice", "part number", getPartNumber(), getPartDescription(),"quantity",  getQuantity(), "price per item", getPricePerItem() );
	}
	public double getPaymentAmount() {
		return getQuantity() * getPricePerItem();
	}
	
}
