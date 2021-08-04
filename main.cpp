#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


class User {
//Created class, so we can keep variables in one place that can be accessed by both CreateAccount() and Login() functions
public:
    string inputUsername;
    string inputPassword;
    string createUsername;
    string createPassword;
    string usernameCheck;
    fstream f;
    ofstream g;
    

void CreateAccount(){ //function to create the users account and store in a file
ofstream g("registration.txt", ios::app); //opens registration txt file to store username and passwords

cout << "Enter username: "; 
cin >> createUsername; //capture users username for their account

ifstream f("registration.txt"); //reads file to check for existing usernames

while (getline(f,usernameCheck)) { //This while loop will check for an existing username, so 2 accounts can't have the same username (case sensitive)
    if (usernameCheck.find(createUsername) != string::npos) {
        cout << "Username already exists! Enter username: "; //If a username already exists (case sensitive) then it will have the user choose a new username
        cin >> createUsername;
    }
}
f.close(); //closes read file
cout << "Enter password: ";
cin >> createPassword; //capture the users password for their account

g<< createUsername; //stores username in registration txt file
g<< " "; //creates a space so the password can be stored next to it
g<< createPassword; //stores password in registration txt file
g<< "\n"; //creates a new line in the registration txt file
g.close(); //closes write file

cout << "Your account has been successfully created! register/login/exit: "; //The message given to the user after their account has been created

}



void Login(){ // function that will read the file the user created their account on
cout << "Please enter your username: ";
        cin >> inputUsername;
 
        cout << "Please enter your password: ";
        cin >> inputPassword;
 
        string userAndPass = inputUsername + " " + inputPassword; // Search pattern
        string line;
        ifstream f("registration.txt");
 
        bool found = false;
        if(f.is_open()) { //checks to see if the file is open
            while(getline(f,line) && !found) { //Will loop until the username and passwords match
                if (line.compare(userAndPass) == 0) { //match strings exactly
                    found = true; // found is true => break loop
        }
    }
    f.close(); //close the file before recursivly opening it again later
    if(found) { //if it finds the username and password, will log user in
        cout << "Welcome "<< inputUsername << '\n';
    }
    else {
        cout << "\nUsername and/or password incorrect!\n\n\n\n";
        Login(); //Since the username or password is incorrect, allow the user to reenter their info
    }
}
}



};


int main(){
User m;
string command; //the variable that will allow the user to create, login, or exit depending on what they enter


cout << "Please type one of these options to proceed: register/login/exit: "; //The menu for the user to decide what they want to do
cin >> command; //grabs the input from the user

while(command != "exit"){ //we want to loop until the user wants to logout just in case they want to login immediately after they create their account

if (command == "register")//this if statement will take the user to the function to create their own account
 m.CreateAccount(); //goes to CreateAccount() function to allow user to make their account


else if (command == "login"){ //if statement that will allow the user to login to their account

m.Login(); //goes to the Login() function so the user can login to their account
cout << "Thank you for signing in. Since this is a test, you will automatically be signed out\n";
sleep_until(system_clock::now() + seconds(3)); // Small delay to imitate a system logging someone out automatically
cout << m.inputUsername << " you have been signed out\n"; //give the user the chance to enter the options again
cout << "Please type one of these options to proceed: register/login/exit: ";
}


else //if the user enters a command other than the three given, it will give them an error message
cout << "Invalid Input. Please try again: register/login/exit: ";


cin >> command; //takes another command from the user

    }

    cout << "Thank you for using this registration system! All data will be cleared";
    m.g.open("registration.txt", std::ofstream::out | std::ofstream::trunc); //clear everything in txt file
    m.g.close(); //close the txt file

}

