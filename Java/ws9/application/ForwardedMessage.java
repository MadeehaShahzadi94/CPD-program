package application;



import java.io.Serializable;


public class ForwardedMessage implements Serializable {
    
    public final Object message; 
    public final int senderID;   


    public ForwardedMessage(int senderID, Object message) {
        this.senderID = senderID;
        this.message = message;
    }

}