/**********************************************
Workshop # 6
Course:<JAV444> - Semester Fall
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature: Madeeha Shahzadi
Date:<submission date> November, 10 2020
**********************************************/

package application;



import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Main extends Application
{

	public static String processInput(String year,String gender,String name)
	{
		String result = "";
		// array list that store all the data 
		ArrayList<String> list = new ArrayList<>();
		try {
			File file = new File("C:\\Users\\owner\\Desktop\\Babynames files\\Babynames files\\babynamesranking"+year+".txt");

			@SuppressWarnings("resource")
			Scanner sc = new Scanner(file);
			while(sc.hasNext()){
				for (int i = 0; i < 5; i++) {
					list.add(i, sc.next());
				}
				//Female and Male classification
				if(gender.equals("M")){
					if(list.get(1).equals(name)){
						result+=name + " is ranked #" + list.get(0) + " in year " + year;
						return result;
					}
				}

				if(gender.equals("F")){
					if(list.get(3).equals(name)){
						result+=name + " is ranked #" + list.get(0) + " in year " + year;
						return result;
					}
				}
				list.clear();
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
		result="The name " + name + " is not ranked in year " + year;
		return result;
	}
	/******************************************************************************************************************/
	
	@Override
	public void start(Stage primaryStage) throws Exception 
	{
		//1st Stage of the OutPut
		Label yearLabel = new Label("Enter the year: ");
		TextField yearFied = new TextField();
		Label genderLabel = new Label("Enter the gender: ");
		TextField genderFied = new TextField();
		Label nameLabel = new Label("Enter the name: ");
		TextField nameFied = new TextField();

		GridPane userInputArea = new GridPane();
		userInputArea.setHgap(20);
		userInputArea.setVgap(20);
		userInputArea.setAlignment(Pos.CENTER);

		userInputArea.add(yearLabel, 0, 0);
		userInputArea.add(yearFied, 1, 0);
		userInputArea.add(genderLabel, 0, 1);
		userInputArea.add(genderFied, 1, 1);
		userInputArea.add(nameLabel, 0, 2);
		userInputArea.add(nameFied, 1, 2);




		Button submitQueryButton = new Button("Submit Query");
		Button exitButton = new Button("Exit");
		HBox hbox = new HBox();
		hbox.getChildren().addAll(submitQueryButton,exitButton);
		
		
		GridPane buttonArea = new GridPane();
		buttonArea.setVgap(20);
		buttonArea.setHgap(40);
		buttonArea.setAlignment(Pos.CENTER);
		buttonArea.add(submitQueryButton, 0, 0);
		buttonArea.add(exitButton, 1, 0);

		VBox vbox = new VBox();
		vbox.getChildren().addAll(userInputArea,buttonArea);

		GridPane pane = new GridPane();
		pane.setAlignment(Pos.CENTER);
		pane.add(userInputArea,0,0);
		pane.add(buttonArea,0,1);
		pane.setVgap(30);

		Scene scene = new Scene(pane);

		Label result = new Label();
		Label prompt = new Label("Do you want to Search for another Name:");
		GridPane dataDisplay = new GridPane();
		dataDisplay.setHgap(30);
		dataDisplay.setVgap(30);
		dataDisplay.setAlignment(Pos.CENTER);

		dataDisplay.add(result, 0, 0);
		dataDisplay.add(prompt, 0, 1);


		Button yesButton = new Button("Yes");
		Button noButton = new Button("No");

		GridPane buttonArea1 = new GridPane();
		buttonArea1.setVgap(20);
		buttonArea1.setHgap(40);
		buttonArea1.setAlignment(Pos.CENTER);
		buttonArea1.add(yesButton, 0, 0);
		buttonArea1.add(noButton, 1, 0);



		primaryStage.setScene(scene);
		primaryStage.setTitle("Search Name Ranking Application");
		primaryStage.setHeight(250);
		primaryStage.setWidth(350);

		primaryStage.show();     
		/*===========================================================================================================*/
		//No Buttons
		
		noButton.setOnAction(new EventHandler<ActionEvent>() 
		{
			@Override public void handle(ActionEvent e) 
			{
				primaryStage.close();
				System.exit(0);
			}
		}); 
		/*===========================================================================================================*/
		// Exit Button
		exitButton.setOnAction(new EventHandler<ActionEvent>() 
		{
			@Override public void handle(ActionEvent e) 
			{
				primaryStage.close();
				System.exit(0);
			}
		}); 
		
		/*===========================================================================================================*/
		//Submit Query
		submitQueryButton.setOnAction(new EventHandler<ActionEvent>() 
		{
			@Override public void handle(ActionEvent e) 
			{
				GridPane pane1 = new GridPane();
				pane1.setAlignment(Pos.CENTER);
				pane1.add(dataDisplay,0,0);
				pane1.add(buttonArea1,0,1);
				pane1.setVgap(30);

				String result1 = processInput(yearFied.getText(),genderFied.getText(),nameFied.getText());
				result.setText(result1);
				Scene scene1 = new Scene(pane1);
				primaryStage.setScene(scene1);
				primaryStage.show();      
			}
		}); 
		/*===========================================================================================================*/
		//Yes Button
		yesButton.setOnAction(new EventHandler<ActionEvent>() 
		{
			@Override public void handle(ActionEvent e) 
			{

				GridPane pane2 = new GridPane();
				pane2.setAlignment(Pos.CENTER);
				pane2.add(userInputArea,0,0);
				pane2.add(buttonArea,0,1);
				yearFied.clear();
				genderFied.clear();
				nameFied.clear();
				pane2.setVgap(30);
				Scene scene2 = new Scene(pane2);
				primaryStage.setScene(scene2);
				primaryStage.show();         
			}
		}); 


	}
	public static void main(String[] args) 
	{
		launch(args);
	}
}
