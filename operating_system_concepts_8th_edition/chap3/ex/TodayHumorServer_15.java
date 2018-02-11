
/**
 * Time-of-day server listening to port 6013.
 *
 * Figure 3.19
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Eighth Edition
 * Copyright John Wiley & Sons - 2008.
 */
 
import java.net.*;
import java.io.*;

public class TodayHumorServer_15
{
	public static void main(String[] args)  {
		try {
			ServerSocket sock = new ServerSocket(6013);

			// now listen for connections
			while (true) {
				Socket client = sock.accept();
				// we have a connection
				
				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				// write the Date to the socket
				// pout.println(new java.util.Date().toString());//오늘의 유머라는데 그럼 유머를 365개를 가지고 있어야하는건가?
				pout.println("Upon dying, Bill Gates went to purgatory.\nSt. Peter said to him, \"Bill, you have done some good things, and you have done some bad things. Now I am going to let you decide where you want to go.\"\n\"That was just the screen saver.\"");
				// close the socket and resume listening for more connections
				client.close();
			}
		}
		catch (IOException ioe) {
				System.err.println(ioe);
		}
	}
}
