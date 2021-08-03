#include <iostream>
#include <fstream>

using namespace std;


void CreateAccount(){ //function to create the users account and store in a file
string createUsername; //string that be used to capture the users username
string createPassword; //string that be used to capture the users password

cout << "Please enter your desired username: "; //ask the user to enter the username for their account 
 cin >> createUsername; //capture users username for their account
cout << "\n" << "Please enter your desired password: "; //ask the user to enter the password for their account
cin >> createPassword; //capture the users password for their account





cout << "Your account has been successfully created! create/login/exit: "; //The message given to the user after their account has been created

}


void Login(){ // function that will read the file the user created their account on

cout << "You have successfully logged in! create/login/exit: "; //the message the user will receive when they successfully create their account
}

int main(){
string command; //the variable that will allow the user to create, login, or exit depending on what they enter
cout << "Please type one of these options to proceed: create/login/exit: "; //The menu for the user to decide what they want to do
cin >> command; //grabs the input from the user
while(command != "exit"){ //we want to loop until the user wants to logout just in case they want to login immediately after they create their account

if (command == "create"){ //this if statement will take the user to the function to create their own account
 
CreateAccount(); //goes to CreateAccount() function to allow user to make their account
cin >> command; //grabs another input from the user
}

else if (command == "login"){ //if statement that will allow the user to login to their account
Login(); //goes to the Login() function so the user can login to their account
cin >> command; //takes anoter input from the user
}

else{ //if the user enters a command other than the three given, it will give them an error message
cout << "Invalid Input. Please try again: create/login/exit: "; //message given to the user for not entering a valid command
cin >> command; //takes another command from the user so they can enter the correct command
}

}


return 1;
}
