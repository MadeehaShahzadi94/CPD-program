/**********************************************
Workshop # 9
Course:<JAV444> - Semester FALL
Last Name:<Shahzadi>
First Name:<Madeeha>
ID:<130638182>
Section:<NDD>
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature Madeeha Shahzadi
Date:<submission date> December 1st 2020
**********************************************/
package application;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.geometry.Insets;

import java.io.IOException;
import java.util.Optional;




public class Main extends Application {
    
   
    private final static int PORT = 37829; 

    private TextField messageInput;  
    private Button sendButton;        
    private Button quitButton;        
    private TextArea transcript;     
    private ChatClient connection;
    private volatile boolean connected; 
    
    
   
    public void start( Stage stage ) {
        
        TextInputDialog question = new TextInputDialog();
        question.setHeaderText("Enter the host name of the\ncomputer that hosts the chat room.");
        question.setContentText("Host Name:");
        Optional<String> response = question.showAndWait();
        if ( ! response.isPresent() )
            System.exit(0);
        String host = response.get().trim();
        if (host == null || host.trim().length() == 0)
            System.exit(0);

        transcript = new TextArea();
        transcript.setPrefRowCount(30);
        transcript.setPrefColumnCount(60);
        transcript.setWrapText(true);
        transcript.setEditable(false);

        sendButton = new Button("send");
        quitButton = new Button("quit");
        messageInput = new TextField();
        messageInput.setPrefColumnCount(40);
        sendButton.setOnAction( e -> Send() );
        quitButton.setOnAction( e -> Quit() );
        sendButton.setDefaultButton(true);
        sendButton.setDisable(true);
        messageInput.setEditable(false);
        messageInput.setDisable(true);
        
        HBox bottom = new HBox(8, new Label("YOU SAY:"), messageInput, sendButton, quitButton);
        HBox.setHgrow(messageInput, Priority.ALWAYS);
        HBox.setMargin(quitButton, new Insets(0,0,0,50));
        bottom.setPadding(new Insets(8));
        bottom.setStyle("-fx-border-color: black; -fx-border-width:2px");
        BorderPane root = new BorderPane(transcript);
        root.setBottom(bottom);
        
        stage.setScene( new Scene(root) );
        stage.setTitle("Networked Chat");
        stage.setResizable(false);
        stage.setOnHidden( e -> Quit() );
        stage.show();
        
        new Thread() {
            
            public void run() {
                try {
                    addToTranscript("Connecting to " + host + " ...");
                    connection = new ChatClient(host);
                    connected = true;
                    Platform.runLater( () -> {
                        messageInput.setEditable(true);
                        messageInput.setDisable(false);
                        sendButton.setDisable(false);
                        messageInput.requestFocus();
                    });
                }
                catch (IOException e) {
                    addToTranscript("Connection attempt failed.");
                    addToTranscript("Error: " + e);
                }
            }
        }.start();

    }
    
    
  //*******************************Nested Class*****************************************************************
    private class ChatClient extends Client {

        ChatClient(String host) throws IOException {
            super(host, PORT);
        }

      //-------------------------------------------------------------------------------------------------------//
        protected void messageReceived(Object message) {
            if (message instanceof ForwardedMessage) {  // (no other message types are expected)
                ForwardedMessage bm = (ForwardedMessage)message;
                addToTranscript("#" + bm.senderID + " SAYS:  " + bm.message);
            }
        }

       //--------------------------------------------------------------------------------------------------------//
        protected void connectionClosedByError(String message)
        {
            addToTranscript("Sorry, communication has shut down due to an error:\n     " + message);
            Platform.runLater( () -> {
                sendButton.setDisable(true);
                messageInput.setEditable(false);
                messageInput.setDisable(true);
                messageInput.setText("");
            });
            connected = false;
            connection = null;
        }
        //----------------------------------------------------------------------------------------------------------//
        protected void playerConnected(int newPlayerID) {
            addToTranscript("Someone new has joined the chat room, with ID number " + newPlayerID);
        }
        //----------------------------------------------------------------------------------------------------------//
        protected void playerDisconnected(int departingPlayerID) 
        {
            addToTranscript("The person with ID number " + departingPlayerID + " has left the chat room");
        }

    } 
/***********************************************End of the nested class******************************************************************/
    private void addToTranscript(String message) 
    {
        Platform.runLater( () ->    transcript.appendText(message + "\n\n") );
    }
    
    
    //-------------------------------------------------------------------------------------------//
    private void Quit()
    {
        if (connected)
            connection.disconnect();  
        try 
        {
            Thread.sleep(500); 
        }
        catch (InterruptedException e)
        {
        }
        System.exit(0);
    }
    //-----------------------------------------------------------------------------------------------//
    private void Send() {
        String message = messageInput.getText();
        if (message.trim().length() == 0)
            return;
        connection.send(message);
        messageInput.selectAll();
        messageInput.requestFocus();
    }
    //------------------------------------------------------------------------------------------------//
    public static void main(String[] args) 
    {
        launch(args);
    }

} 