//============================================================================
// Created by: Christian Bass
// Version: 3.0
// Description: SQLite3 CRUD functions for creating a stock system to
// track fruit.
//============================================================================
#include <cmath> // For password hashing function
#include <algorithm> // For password hashing function
#include <fstream> // For saving hashed password
#include <iostream>
#include <string>     // For converting strings
#include "sqlite3.h" // Database functionality for SQLite3

using namespace std;

//============================================================================
// Definitions
//============================================================================ 
int callback(void* NotUsed, int argc, char** argv, char** azColName);
int execute(int argc, char** argv);
void create();
void read();
void displayAll();
void update();
void del();
int hashFunction(string key);
void updatePass();

const int constP = 31;
char dbName[11] = "FRUITSTOCK";
char programName[] = "Fruit Stock Program";



//============================================================================
// Standard SQLite callback function
//============================================================================ 
int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    for (int i = 0; i < argc; ++i) {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << '\n';
        cout << endl;     
    }
    return 0;
}



//============================================================================
// Function to execute commands to SQLite database
//============================================================================ 
int execute(int argc, char** argv) { //Arguments for Program name (programName), database name (dbName), and command (dbCommand)
    sqlite3 * db;
    char* zErrMsg = 0;
    int rc;
   
    if (argc != 3) {
        cout << stderr << "Usage: %s DATABASE SQL-STATEMENT\n" << argv[0];
        return(1);     
    }

    rc = sqlite3_open(argv[1], &db); // Open database connection with database name(dbName) argument

    if (rc) {
        cout << stderr << "Can't open database: %s\n" << sqlite3_errmsg(db); // If statement to check if database could be opened
        sqlite3_close(db); // Close database connection on failure
        return(1);      
    }

    rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg); // Execute commands with third argument and display SQLite errors if they occur
    if (rc != SQLITE_OK) {
        cout <<stderr << "SQL error: %s\n" << zErrMsg;
        sqlite3_free(zErrMsg);     
    }

    sqlite3_close(db); // Close database connection after completing command
    return 0;
}



//============================================================================
// Algorithm for hashing password and function for updating password file
//============================================================================ 
int hashFunction(string key) { //Hashing function to hash passwords
    int hashCode = 0;

    for (int i = 0; i < key.length(); i++) { //Generates hash
        hashCode += key[i] * pow(constP, i);
    }

    return hashCode;
}

void updatePass() {
    string password;

    cout << "Please enter new password:" << endl; //gets new password from user
    cin >> password;

    int newPass = hashFunction(password); //hashes new password

    std::ofstream out("HashedPass.txt"); //opens password text file
    out << newPass; // overwrites text file with new password
    out.close(); //closes password text file
}



//============================================================================
// CRUD Functions
//============================================================================ 
void create() {
    string fruitName; //Variables for user input
    int currentStock;
    int desiredStock;
    int numberToBuy;

    cout << "Please enter fruit name" << endl; // Asking user for information and getting input to construct command with
    cin >> fruitName;
    cout << "Please enter current stock of " << fruitName << endl;
    cin >> currentStock;
    cout << "Please enter how many " << fruitName << " should be in stock" << endl;
    cin >> desiredStock;

    numberToBuy = desiredStock - currentStock; //Calculating how many fruits the user would need to buy to meet the desired stock

    string currentStockStr = to_string(currentStock); //converting ints to strings
    string desiredStockStr = to_string(desiredStock);
    string numberToBuyStr = to_string(numberToBuy);

    // Building SQLite command
    string commandStr = "INSERT INTO FRUITS (fruitName, currentStock, desiredStock, numberToBuy) VALUES ('" + fruitName + "'," + currentStockStr + "," + desiredStockStr + "," + numberToBuyStr + ")";

   
    const char* dbName = "FRUITSTOCK";  // Converting types
    const char* dbCommand = commandStr.c_str();
    const char* programName = "Fruit Stock Program";

    const char* commandArray[] = { programName, dbName, dbCommand }; // Combining variables into command array to be passed to execute
    char** arr = const_cast<char**>(commandArray);

    execute(3, arr); // Passing command to execute on the database
}


void read() {
    string fruitName; // Variable for what fruit to read entry for

    cout << "Please enter fruit name" << endl; // Asking user for information and getting input to construct command with
    cin >> fruitName;

    string commandStr = "SELECT * FROM FRUITS WHERE fruitName = '" + fruitName + "'"; // Building command

    const char* dbName = "FRUITSTOCK"; // Converting types
    const char* dbCommand = commandStr.c_str();
    const char* programName = "Fruit Stock Program";

    const char* commandArray[] = { programName, dbName, dbCommand }; // Combining variables into command array to be passed to execute
    char** arr = const_cast<char**>(commandArray);

    execute(3, arr); // Passing command to execute on the database
}

void displayAll() {
    char dbCommand[] = "SELECT * FROM FRUITS"; // Building command

    char* commandArray[] = { programName, dbName, dbCommand }; // Combining variables into command array to be passed to execute

    execute(3, commandArray); // Passing command to execute on the database
}


void update() {
    string fruitName; //Variables for user input
    int currentStock;
    int desiredStock;
    int numberToBuy;

    cout << "Please enter fruit name that you would like to update" << endl; // Asking user for information and getting input to construct command with
    cin >> fruitName;
    cout << "Please enter current stock of " << fruitName << endl;
    cin >> currentStock;
    cout << "Please enter how many " << fruitName << " should be in stock" << endl;
    cin >> desiredStock;

    numberToBuy = desiredStock - currentStock;

    string currentStockStr = to_string(currentStock); // Converting types
    string desiredStockStr = to_string(desiredStock);
    string numberToBuyStr = to_string(numberToBuy);

    // Building command
    string commandStr = "UPDATE FRUITS SET currentStock = " + currentStockStr + ", desiredStock = " + desiredStockStr + ", numberToBuy = " + numberToBuyStr + " WHERE fruitName = '" + fruitName + "'";


   
    const char* dbName = "FRUITSTOCK"; // Converting types
    const char* dbCommand = commandStr.c_str();
    const char* programName = "Fruit Stock Program";

    const char* commandArray[] = { programName, dbName, dbCommand }; // Combining variables into command array to be passed to execute
    char** arr = const_cast<char**>(commandArray);

    execute(3, arr); // Passing command to execute on the database
}


void del() {
    string fruitName; //Variable for user input


    cout << "Please enter fruit name" << endl; // Asking user for information and getting input to construct command with
    cin >> fruitName;


    string commandStr = "DELETE FROM FRUITS WHERE fruitName = '" + fruitName + "'"; // Building command

    const char* dbName = "FRUITSTOCK"; // Converting types
    const char* dbCommand = commandStr.c_str();
    const char* programName = "Fruit Stock Program";

    const char* commandArray[] = { programName, dbName, dbCommand }; // Combining variables into command array to be passed to execute
    char** arr = const_cast<char**>(commandArray);

    execute(3, arr); // Passing command to execute on the database

    cout << fruitName << " has been deleted." << endl; // Letting user know deletion is complete
}



//============================================================================
// Main 
//============================================================================ 
int main() {
    int choice = 0; // User choice for switch case
    string password;
    string filePassword;

    fstream passFile("HashedPass.txt"); // Opening text file for password

    if (!passFile) {  // Lets user know if file could not open
        cout << "Cannot open file";
    }

    cout << "Please enter password : " << endl; //gets password from user
    cin >> password;

    int testPass = hashFunction(password); //hashes password for comparison with saved password
    getline(passFile, filePassword); //gets saved password hash
    int intP = stoi(filePassword); //converts hashed password from file to an int
    
    if (testPass != intP) { //checks to see if passwords match
        cout << "Password is incorrect" << endl;
        exit(0);
    }
 

    while (choice != 7) { // While loop to allow user to do multiple commands
        cout << "Menu:" << endl;
        cout << "  1. Add new fruit to database" << endl; // Displaying menu to user
        cout << "  2. Display All fruit stock" << endl;
        cout << "  3. Display stock for specific fruit" << endl;
        cout << "  4. Delete fruit from database" << endl;
        cout << "  5. Update stock for a fruit" << endl;
        cout << "  6. Change password" << endl;
        cout << "  7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice; // Getting user choice for switch case

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7) { // Checking to make sure user choice is one of the possible options
            cout << "Invalid entry, Enter choice: ";
            cin >> choice;

        }


        switch (choice) { // Switch case for menu

        case 1:
            create(); // Calls create function to add an entry to database
            break;

        case 2:
            displayAll(); // Calls displayAll function to display entire database table
            break;

        case 3:
            read(); // Calls read function to see entry for a specific fruit
            break;

        case 4:
            del(); // Calls delete function to remove a fruit from the table
            break;

        case 5:
            update(); // Calls update function to update an entry for a specific fruit
            break;

        case 6:
            updatePass(); // Calls update function to update password
            break;
        }
    }

    cout << "Exiting program..." << endl;

    return 0;

}