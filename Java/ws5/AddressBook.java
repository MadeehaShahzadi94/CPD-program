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
package work_shop5;
/*******************************************************************************************************/
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.BorderPane;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
@SuppressWarnings("exports")
/*****************************************************************************************************/
public class AddressBook extends BorderPane 
{
	//taking First Name field
	public TextField fName = new TextField();
	//taking Last Name Field
	public TextField lName = new TextField();
	// taking city
	public TextField city = new TextField();
	// Options for the Province
	public ComboBox<String> province = new ComboBox<String>();
	//Postal Code
	public TextField zip = new TextField();
	/**************************************************************************************************/
  // Buttons 
	public Button add = new Button("Add");
   public Button first = new Button("First");
   public Button next = new Button("Next");
   public Button previous = new Button("Previous");
   public Button last = new Button("Last");
   public Button update = new Button("Update");
   private FlowPane flowpane = new FlowPane(5, 5);
   private HBox hBox = new HBox(5);
/********************************************************************************************************/
   //default constructor
   public AddressBook() 
   {
       drawAddressBook();
   }
/*******************************************************************************************************/
   private void drawAddressBook()
   {
	   //province choices
	   province.getItems().addAll("ON", "MB", "NB", "QC", "BC");
	   // Set the Columns for the first name, last name city and postal code
	   // Set width for Combo Box
	   fName.setPrefColumnCount(30);
	   lName.setPrefColumnCount(30);
	   city.setPrefColumnCount(5);
	   province.setMaxWidth(90);
       zip.setPrefColumnCount(4);
     /*=================================================================================================*/
       // Set width for the Buttons
       add.setMinWidth(70);
       first.setMinWidth(70);
       next.setMinWidth(70);
       previous.setMinWidth(70);
       last.setMinWidth(70);
       update.setMinWidth(70);
       /*=================================================================================================*/
       // rows spaces
       flowpane.setPadding(new Insets(11.5, 11.5, 11.5, 11.5));
       flowpane.setHgap(15);
       flowpane.setVgap(20);
       /*=================================================================================================*/
       // Labels
       flowpane.getChildren().addAll
       (
    		new Label("First Name:"), fName,
    		new Label("Last Name:"), lName,
    		new Label("City:"), city,
    		new Label("Province:"), province, 
    		new Label("Postal Code:"), zip
    	);
       /*=================================================================================================*/
       // Place nodes in the box
       hBox.getChildren().addAll
       (		add, 
    		   first,
    		   next, 
    		   previous, 
    		   last, 
    		   update
    );
       hBox.setAlignment(Pos.CENTER);
       setCenter(flowpane);
       setBottom(hBox);
   }
}