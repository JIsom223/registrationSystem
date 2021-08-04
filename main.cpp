#include <iostream>
#include <fstream>

using namespace std;


void CreateAccount(){ //function to create the users account and store in a file
string createUsername; //string that be used to capture the users username
string createPassword; //string that be used to capture the users password
string usernameCheck;
ofstream g("registration.txt", ios::app); //opens registration txt file to store username and passwords

cout << "Enter username: "; //ask the user to enter the username for their account 
cin >> createUsername; //capture users username for their account

ifstream f("registration.txt"); //reads file to check for existing usernames

while (getline(f,usernameCheck)) { //This while loop will check for an existing username, so 2 accounts can't have the same username (case sensitive)
    if (usernameCheck.find(createUsername) != string::npos) {
        cout << "Username already exists! Enter username: "; //If a username already exists (case sensitive) then it will have the user choose a new username
        cin >> createUsername;
    }
}
f.close(); //closes read file
cout << "Enter password: "; //ask the user to enter the password for their account
cin >> createPassword; //capture the users password for their account

g<< createUsername; //stores username in registration txt file
g<< "\n"; //creates a new line
g<< createPassword; //stores password in registration txt file
g<< "\n"; //creates a new line
g.close(); //closes write file

cout << "Your account has been successfully created! register/login/exit: "; //The message given to the user after their account has been created

}




void Login(){ // function that will read the file the user created their account on

cout << "You have successfully logged in! register/login/exit: "; //the message the user will receive when they successfully create their account
}







int main(){
string command; //the variable that will allow the user to create, login, or exit depending on what they enter


cout << "Please type one of these options to proceed: register/login/exit: "; //The menu for the user to decide what they want to do
cin >> command; //grabs the input from the user

while(command != "exit"){ //we want to loop until the user wants to logout just in case they want to login immediately after they create their account

if (command == "register")//this if statement will take the user to the function to create their own account
 CreateAccount(); //goes to CreateAccount() function to allow user to make their account


else if (command == "login") //if statement that will allow the user to login to their account
Login(); //goes to the Login() function so the user can login to their account


else //if the user enters a command other than the three given, it will give them an error message
cout << "Invalid Input. Please try again: register/login/exit: "; //message given to the user for not entering a valid command


cin >> command; //takes another command from the user

    }

}
