/*
By Zachary Nicholas
Project One Clock
September 15th 2022
*/

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <iomanip>
using namespace std;

int hr = 0; // Used for the 12 hour time
int minute = 0; //Minutes shared between 12 and 24 time
int sec = 0; //Seconds shared between 12 and 24 hour time
int hr24 = 0; //Used for the 24 hour time
int menuInput; //Variable for menu input
bool exitCheck = true; //Only updates if you choose to exit the program
int i = 0; //i used to track if am or pm by comparing hrs24 to 12, changes to 1 if hrs24 >= 12

//prints time, able to do in line adding of a zero and also changes between AM and PM using a conditional statement
void printTime() {
	system("cls");
	cout << "***************************  ***************************" << endl;
	cout << "*       12-Hour Clock     *  *        24-Hour Clock    *" << endl;
	cout << "*       "; std::cout << std::setfill('0') << std::setw(2) << hr << ":"
		<< std::setfill('0') << std::setw(2) << minute << ":"
		<< std::setfill('0') << std::setw(2) << sec <<
		((i == 0) ? "AM" : "PM") << "       *  *        ";
	std::cout << std::setfill('0') << std::setw(2) << hr24 << ":"
		<< std::setfill('0') << std::setw(2) << minute << ":"
		<< std::setfill('0') << std::setw(2) << sec << "         *" << endl;
	cout << "***************************  ***************************" << endl;
}
//Prints the menu
void printMenu() {

	cout << "***************************\n";
	cout << "* 1 - Add One Hour        *\n";
	cout << "* 2 - Add One Minute      *\n";
	cout << "* 3 - Add One Second      *\n";
	cout << "* 4 - Exit Program        *\n";
	cout << "***************************\n";
}
//tracks user input and takes appropriate course of action based on user input
void menuAction() {
	switch (menuInput) {
	case 1:
		hr24++;
		hr++;
		if (hr24 == 24) {
			hr24 = 0;
		}
		if (hr24 < 12) {
			i = 0;
		}
		if (hr == 13) {
			hr = 1;
		}
		if (hr24 >= 12) {
			i = 1;
		}
		break;
	case 2:
		minute++;
		if (minute == 60) {
			hr++;
			hr24++;
			minute = 0;
			if (hr24 < 12) {
				i = 0;
			}
			if (hr24 >= 12) {
				i = 1;
			}
			if (hr == 13) {
				hr = 1;
			}
			if (hr24 == 24) {
				hr24 = 0;
			}
		}
		break;
	case 3:
		sec++;
		if (sec == 60) {
			minute++;
			sec = 0;
			if (minute == 60) {
				hr++;
				hr24++;
				minute = 0;
				if (hr24 < 12) {
					i = 0;
				}
				if (hr == 13) {
					hr = 1;
				}
				if (hr24 >= 12) {
					i = 1;
				}
				if (hr24 == 24) {
					hr24 = 0;
				}
			}
		}
		break;
	case 4:
		cout << "Exiting Clock Program" << endl;
		exitCheck = false;
		break;
	default:
		cout << "Invalid input. Please Enter A Valid Menu Item." << endl;
	}

}
//Prints the time, menu, takes the menu input and then does the appropriate menu item in a loop
int main() {

	while (exitCheck) {
		printTime();
		printMenu();
		cin >> menuInput;
		menuAction();
	}
	return 0;
}