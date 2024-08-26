
package com.mycompany.zoomonitor;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.FileReader;
import java.io.IOException;
import javax.swing.JOptionPane;
        


public class ZooMonitor {
    
    public static void animalFile() { //Method for animals file. Referenced in main.
    Scanner scnr = new Scanner(System.in); 
    //Setting variables and scanner
    String chosenOption = ""; 
    int i = 0;
    BufferedReader br = null;
    String currentLine = null;
    
        try { //try block to read from animals.txt, There were probably better ways to do this
            
            FileReader fr = new FileReader("animals.txt"); //Setting up file reader and buffered reader
            br = new BufferedReader(fr);
            
            while (i<4&&(currentLine = br.readLine()) != null){      //First loop to output list of animals
                i++;
                
                System.out.println(currentLine);               
            }
         
        System.out.println("Please choose an animal."); //getting input from user to pick an animal
        chosenOption = scnr.next();
        chosenOption = chosenOption.toLowerCase(); //lowercasing and removing plurals from user input
        chosenOption = chosenOption.replaceAll("s", ""); 
       
        
    Scanner in = new Scanner(new File("animals.txt"));  //new scanner for animals.txt
    boolean found = false;
    while (in.hasNextLine()) {

       String line = in.nextLine();
       if (line.toLowerCase().contains(" - " + chosenOption)) { //seeing if the line has the user input. the check for " - " 
                                                                 //is because the animals are also listed at the start of the file.
          for (int a = 0; a < 4; a++) { 
        String printLine = in.nextLine();
        if (printLine.contains("*")) {    //printing out the next 4 lines after the user input is found.
           printLine = printLine.replaceAll("[*]", ""); //removing * characters
           JOptionPane.showMessageDialog(null, ("Animal problem: " + printLine ), "Animal Problem!", JOptionPane.WARNING_MESSAGE); //creating dialog box if line had a *      
    }
        
    System.out.println(printLine); //printing line
    
    }
    found = true;
    
        break;         //break to get back to main menu

    }

    }

    if (!found) {

    System.out.println("Option not found."); //letting the user know the inputted animal wasnt found

    }
        
            
        } catch (FileNotFoundException FileNotFoundException) { //catching io and filenotfound exceptions
        System.out.println(FileNotFoundException);
        } catch (IOException IOException) {
        System.out.println(IOException);
        }
    }
    
    
    
    
        
    public static void habitatFile() { //Method for habitat file, referenced in main.
    Scanner scnr = new Scanner(System.in);
    //setting up scanner and variables
    String chosenOption = ""; 
    int i = 0;
    BufferedReader br = null;
    String currentLine = null;
    
        try { //try block to read from file
            FileReader fr = new FileReader("habitats.txt"); //setting up file reader and buffered reader
            br = new BufferedReader(fr);
            
            while (i<3&&(currentLine = br.readLine()) != null){   //loop to print the options to the user 
                i++;
                
                System.out.println(currentLine);               
            }
         
        System.out.println("Please choose a habitat."); //getting input from user for the habitat to monitor
        chosenOption = scnr.next();
        chosenOption = chosenOption.toLowerCase(); //lowercasing user input
        
       
        
    Scanner in = new Scanner(new File("habitats.txt"));  //creating new scanner for habitats.txt 
    boolean found = false;
    while (in.hasNextLine()) {
        
       String line = in.nextLine();
       if (line.toLowerCase().contains(" - " + chosenOption)) { //checking for user input in the current line

            for (int i2 = 0; i2 < 3; i2++) { //printing the next 3 lines after user input is found
        String printLine = in.nextLine();
        if (printLine.contains("*")) {
           printLine = printLine.replaceAll("[*]", ""); //removing * from output
           JOptionPane.showMessageDialog(null, ("Habitat problem: " + printLine ), "Habitat Problem!", JOptionPane.WARNING_MESSAGE); //creating dialog box
    }
        
    System.out.println(printLine); //printing the lines
    
    }
    found = true;
    
        break; //break to get back to main

    }

    }

    if (!found) {

    System.out.println("Option not found."); //letting the user know the option was not found

    }
        
            
        } catch (FileNotFoundException FileNotFoundException) {
        System.out.println(FileNotFoundException);
        } catch (IOException IOException) {
        System.out.println(IOException);
        }				    
    }
	
    
    
    
    
public static void main(String[] args) throws IOException {

    Scanner scnr = new Scanner(System.in);
                                //creating scanner and variable for chosen type
    String chosenType = "";
        
		
    System.out.println("Please choose \"Habitat\", \"Animal\", or \"Quit\"");
    chosenType = scnr.next(); //asking the user what they would like to monitor
		
while (!"Quit".equals(chosenType)) { //loop to check if the user inputted "Quit"
			
    if ("Habitat".equals(chosenType)) { //Calls the habitatFile method
                            
        habitatFile();
        
        System.out.println("Please choose \"Habitat\", \"Animal\", or \"Quit\""); //gives the user list of options agian after succesfully calling method
        chosenType = scnr.next();
    }                                    

    else if ("Animal".equals(chosenType)) {//Calls the animalFile method
                            
        animalFile();
        System.out.println("Please choose \"Habitat\", \"Animal\", or \"Quit\""); //gives the user list of options agian after succesfully calling method
        chosenType = scnr.next();
                           
    }
				
		
    else { //Tells user option did not exist then asks them to choose again.
        
        System.out.println("Option does not exist returning to main menu.");
        System.out.println("Please choose \"Habitat\", \"Animal\", or \"Quit\"");
        chosenType = scnr.next();
				}
			}
		}
	}