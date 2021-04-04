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
import java.io.IOException;


public class ChatRoomServer {

    private final static int PORT = 37829;
    
    public static void main(String[] args) {
        try {
            new Hub(PORT);
        }
        catch (IOException e) {
            System.out.println("Can't create listening socket.  Shutting down.");
        }
    }
    
}
