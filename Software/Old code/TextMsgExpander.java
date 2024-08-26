import java.util.Scanner;


public class TextMsgExpander {
	public static void main(String[] args) {
	Scanner scnr = new Scanner(System.in);
	
	String textMsg = "";
	
	
	System.out.println("Enter text: ");
      textMsg = scnr.nextLine();
	  
	 System.out.println("You entered: " + textMsg);
	 System.out.println("");
	 
	if (textMsg.contains("BFF")) {
		textMsg = textMsg.replace("BFF", "best friend forever");
		System.out.println("Replaced \"BFF\" with \"best friend forever\".");
	}
	
	if (textMsg.contains("IDK")) {
		textMsg = textMsg.replace("IDK", "I don't know");
		System.out.println("Replaced \"IDK\" with \"I don't know\".");
	}
		
	if (textMsg.contains("JK")) {
		textMsg = textMsg.replace("JK", "just kidding");
		System.out.println("Replaced \"JK\" with \"just kidding\".");
	}
	
	if (textMsg.contains("TMI")) {
		textMsg = textMsg.replace("TMI", "too much information");
		System.out.println("Replaced \"TMI\" with \"too much information\".");
	}
	
	if (textMsg.contains("TTYL")) {
		textMsg = textMsg.replace("TTYL", "talk to you later");
		System.out.println("Replaced \"TTYL\" with \"talk to you later\".");
	}
	
	System.out.println("");
	System.out.println("Expanded: " + textMsg);
	
	  return;
   }
}
	