import java.util.Scanner; //importing needed modules
import java.lang.Math;

public class FruitStock {
	
	public static void main(String[] args) {

	   Scanner scnr = new Scanner(System.in); //Setting scanner up for future use
	   
		int apples = 0;         //Establishing variables
		int applesStock = 0;
		int applesNeeded = 0;
		int oranges = 0;
		int orangesStock = 0;
		int orangesNeeded = 0;
		
		//Getting inputs from user
		System.out.println("Enter current number of apples:");
		apples = scnr.nextInt();
		
		System.out.println("Enter how many apples should be in stock:");
		applesStock = scnr.nextInt();
		
		System.out.println("Enter current number of oranges:");
		oranges = scnr.nextInt();
		
		System.out.println("Enter how many oranges should be in stock:");
		orangesStock = scnr.nextInt();
		
		//calculating number of apples and oranges needed
		applesNeeded = (applesStock - apples);
		orangesNeeded = (orangesStock - oranges);
		
		//outputting calculated numbers to the user
		System.out.println("You need to order " + applesNeeded + " apples and " + orangesNeeded + " oranges.");
		
      return;
   }
}