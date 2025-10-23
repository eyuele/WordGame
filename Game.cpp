/*
* Nest the file handling logic have to be implemented to save and load user data (usernames, passwords, scores) from a file.
* This will ensure that user data persists between program executions.
* Additionally, implement error handling for file operations to manage scenarios where the file may not exist or is inaccessible.
* Furthermore, add a login function that allows existing users to log in using their credentials.
* inaddition, impliment a class that validate the answers for the game puzzle questions and user choices.
* Finally, enhance the user interface to provide a more engaging experience, such as adding menus and prompts for better navigation.
* With this the gaem will be more complete and user-friendly.
* After evry modification make sure to test the code to ensure that all functionalities work as expected.
* Aswell as to make sure that the file is pushed to the repository correctly.
* Happy coding!
*/

#include <iostream>
#include <string>-
#include <vector>
#include <fstream>

bool RegisterUser(std::vector <std::string> Usernames,
             std::vector <std::string> Passwords,
            std::vector <int> Scores,
            int &counts)
{
    bool ValidPassword, IsNewUser, IsRunning = true;

    std::cout << "Register a new user:" << std::endl;
    while (IsRunning){
        bool ValidPassword = false, IsNewUser = true;
        std::string NewUsername, NewPassword;
        std::cout << "Enter a username: ";
        std::cin >> NewUsername;
        /**This loop checks if the username already exists in the Usernames vector. 
         * If it does, it sets IsNewUser to false and prompts the user to choose a different username
         * otherwise it will continue to the next loop to set the password.**/ 
        for (int i = 0; i < counts; i++){

            if (NewUsername == Usernames[i]){
                std::cout << "Username already exists. Please choose a different username." << std::endl;
                IsNewUser = false;
                break;
            }
            
            else {
                continue;
            }
        }
    
        while (IsNewUser == true){
        /* 
        *this loop prompts the user to enter a password and checks if it meets the minimum length requirement of 6 characters. 
        *If the password is too short, it prompts the user to try again.
        * If the password is valid, it breaks out of the loop.
        */
            std::cout << "Enter a password: ";
            std::cin >> NewPassword;
            if (NewPassword.length() < 6){
                std::cout << "Password must be at least 6 characters long. Please try again." << std::endl;
                continue;
            }
            else {
                ValidPassword = true;
                break;
            }
        }
        if (ValidPassword == true && IsNewUser == true){
            Usernames.push_back(NewUsername);
            Passwords.push_back(NewPassword);
            Scores.push_back(0);
            counts = counts + 1;
            std::cout << "Registration successful! You can now log in with your new credentials."<<std::endl;
            IsRunning = false;
        }
        else {
            continue;
        }
        
    }


}



int main() {
	std::vector <std::string> Usernames;
	std::vector <std::string> Passwords;
	std::vector <int> Scores;
	int counts;

	std::cout << "Welcome to the Game!" << std::endl;
	
	
	/*
    *The ID_NUM logic needs to be fixed to properly handle logged-in and logged-out states.
    * Currently, it is hardcoded to 0, which means the user is always treated as logged out.
    * A better approach would be to initialize ID_NUM to -1 (indicating no user is logged in)
    * and update it upon successful login. and set it back to -1 upon logout.
    */
	int ID_NUM = 0;

    if (ID_NUM >= 1 ){
        
	    std::cout << "Hello," << Usernames[ID_NUM] << std::endl;

    }
    else if (ID_NUM < 1 ){
        std::cout << "Choose an option: " << std::endl;;
        std::cout << "1. Register" << std::endl;
        std::cout << "2. Login" << std::endl;
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (choice == 1){
            RegisterUser(Usernames, Passwords, Scores, counts);
        }
    }

	return 0;
}