//============================================================================
// Created by: Christian Bass
// Version: 2.0
// Description: Opens files "animals.txt" and "habitats.txt". Displays menu
// options from top of files and allows user to select an animal or habitat
// when selected will display relevant information. Can have popups for alerts.
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <cstring>

using namespace std;

//============================================================================
// Definitions
//============================================================================ 
void animalFile();
void habitatFile();

//============================================================================
// Main Menu
//============================================================================ 
int main() {

	string chosenOption; // Variable for user menu selection

	cout << "Please select an option: Habitats, Animals, or Quit." << endl; // Displaying menu and getting user input
	cin >> chosenOption;
	transform(chosenOption.begin(), chosenOption.end(), chosenOption.begin(), ::tolower); // Making user input lowercase for easier file searching

	while (chosenOption != "quit") { // Loop to allow for multiple options to be chosen

		if (chosenOption.find("habitat") != string::npos) { // Checks user input for habitat and calls the function
			habitatFile();

			cout << "Please select an option: Habitats, Animals, or Quit." << endl; // Lets user choose another menu option after completing habitat function
			cin >> chosenOption;
			transform(chosenOption.begin(), chosenOption.end(), chosenOption.begin(), ::tolower);
		}

		if (chosenOption.find("animal") != string::npos) { // Checks user input for animal and calls the function
			animalFile();

			cout << "Please select an option: Habitats, Animals, or Quit." << endl; // Lets user choose another menu option after completing animal function
			cin >> chosenOption;
			transform(chosenOption.begin(), chosenOption.end(), chosenOption.begin(), ::tolower);
		}

		else if (chosenOption != "quit") { // Check if user inputted quit, if not it lets user know option does not exist.
			cout << "Option does not exist." << endl;

			cout << "Please select an option: Habitats, Animals, or Quit." << endl; // Lets user choose another menu option
			cin >> chosenOption;
			transform(chosenOption.begin(), chosenOption.end(), chosenOption.begin(), ::tolower);
		}
	}
}

//============================================================================
// Accesses animals.txt file and displays information to user
//============================================================================
void animalFile() {
	string lineOut; // holds data from current line of file being read
	string userInput; // Gets user input for menus
	string errorMsg; // holds line from file with animal problem to be displayed in message box popup
	bool found = false;

	fstream animalFile("animals.txt"); // Opening text file

	if (!animalFile) {  // Lets user know if file could not open
		cout << "Cannot open file";
	}

	getline(animalFile, lineOut); // Gets first line of file

	while (lineOut != "#") { // Reads file until a # is encountered to display menu
		cout << lineOut << endl;
		getline(animalFile, lineOut);
	}

	cout << endl << "Please choose an animal." << endl; // Prompts user for selection now that menu has been displayed
	cin >> userInput;

	transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower); // Lowercases user input for easier file searching

	if (userInput.back() == 's' && !userInput.empty()) { // Removes s from end of user input incase they type a plural such as "lions" instead of "lion"			
		userInput.pop_back();
	}

	while (animalFile.peek() != EOF) { // Checks for end of file to prevent further attempts to read it
		getline(animalFile, lineOut); // gets next line from file
		transform(lineOut.begin(), lineOut.end(), lineOut.begin(), ::tolower); // lowercases line to match lowercase user input

		if (lineOut.find(userInput) != string::npos) { // checks current line of file for inputted animal name
			cout << endl;
			getline(animalFile, lineOut);

			while (lineOut != "#") { // When correct animal is found displays all information for that animal

				if (animalFile.peek() == '*' && animalFile.peek() != EOF) { // Checks for problems with the animal to display the attention popup
					cout << lineOut << endl;
					getline(animalFile, lineOut);
					lineOut.erase(remove(lineOut.begin(), lineOut.end(), '*'), lineOut.end()); // Removes stars so they aren't outputted to popup

					errorMsg = "Animal Problem: " + lineOut; // Saves line with issue to errorMsg variable to be displayed

					char* cstr = new char[errorMsg.length() + 1]; 
					strcpy_s(cstr, errorMsg.size() + 1, errorMsg.c_str()); // Changing type

					MessageBoxA(nullptr, cstr, "Animal Problem", MB_OK); // Displaying attention popup
				}

				lineOut.erase(remove(lineOut.begin(), lineOut.end(), '*'), lineOut.end()); // Removes stars so they aren't outputted to user
				cout << lineOut << endl; //continues displaying animals info
				getline(animalFile, lineOut);

			}
			cout << endl;
			found = true; // sets found to true so that the "Option not found." message can't be triggered.
			break;
		}
	}

	if (!found) {
		cout << "Option not found." << endl << endl; // Lets user know animal wasn't found
	}
}

//============================================================================
// Accesses habitats.txt file and displays information to user
//============================================================================
void habitatFile() {
	string lineOut; // holds data from current line of file being read
	string userInput; // Gets user input for menus
	string errorMsg; // holds line from file with habitat problem to be displayed in message box popup
	bool found = false;

	fstream habFile("habitats.txt"); // Opening text file

	if (!habFile) {  // Lets user know if file could not open
		cout << "Cannot open file";
	}

	getline(habFile, lineOut); // Gets first line of file

	while (lineOut != "#") { // Reads file until a # is encountered to display menu
		cout << lineOut << endl;
		getline(habFile, lineOut);
	}

	cout << endl << "Please choose a habitat." << endl; // Prompts user for selection now that menu has been displayed
	cin >> userInput;

	transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower); // Lowercases user input for easier file searching

	while (habFile.peek() != EOF) { // Checks for end of file to prevent further attempts to read it
		getline(habFile, lineOut); // gets next line from file
		transform(lineOut.begin(), lineOut.end(), lineOut.begin(), ::tolower); // lowercases line to match lowercase user input

		if (lineOut.find(userInput) != string::npos) { // checks current line of file for inputted habitat name
			cout << endl;
			getline(habFile, lineOut);

			while (lineOut != "#" && habFile.peek() != EOF) { // When correct habitat is found displays all information for that habitat

				if (habFile.peek() == '*') { // Checks for problems with the habitat to display the attention popup
					cout << lineOut << endl;
					getline(habFile, lineOut);
					lineOut.erase(remove(lineOut.begin(), lineOut.end(), '*'), lineOut.end()); // Removes stars so they aren't outputted to popup

					errorMsg = "Habitat problem: " + lineOut; // Saves line with issue to errorMsg variable to be displayed

					char* cstr = new char[errorMsg.length() + 1]; 
					strcpy_s(cstr, errorMsg.size() + 1, errorMsg.c_str()); // Changing type

					MessageBoxA(nullptr, cstr, "Habitat Problem", MB_OK); // Displaying attention popup
				}

				lineOut.erase(remove(lineOut.begin(), lineOut.end(), '*'), lineOut.end()); // Removes stars so they aren't outputted to user
				cout << lineOut << endl; //continues displaying habitats info
				getline(habFile, lineOut);

			}
			cout << endl;
			found = true; // sets found to true so that the "Option not found." message can't be triggered.
			break;
		}
	}

	if (!found) {
		cout << "Option not found." << endl; // Lets user know habitat wasn't found
	}
}