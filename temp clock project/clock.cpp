
//Ashley Povlik, Project 1

#include "AshleyPovlik.h"
#include <iostream>
#include <iomanip> // For setfill(), setw()
 
using namespace std;

//24 hour time variables 
int hours = 22; // hours variable allowed range 0 - 23
int minutes = 58; // minutes variable range allowed 0 - 59
int seconds = 56; // seconds variable range allowed 0 - 59

// Function checking for correct range of time
void DisplayTime(bool hour24) {
	if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 ||
		seconds > 59) {
		cout << "Invalid, please enter a valid time.";
		return;
	}
	// check if hour is am or pm
	bool afterNoon = hours > 12;
	
	//12 hour time calculation
	int displayHours = afterNoon && !hour24 ? hours - 12 : hours;
	
	// Displays 12 
	if (hours == 0 && !hour24) {
		displayHours = 12;
	}

	string ampm = "";
	// sets am or pm for 12 hour clock 
	if (!hour24) {
		ampm = afterNoon ? " P M" : " A M";
	}
	
	// Displays clock and adds 0 before hours between 0-9
	cout << setfill('0');
	cout << setw(2) << displayHours << ":";
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds << ampm;
	cout << setfill(' ');
}
void DisplayClocks() {
	cout << flush;
	cout << "*************************** ***************************" << endl;
	cout << "*       12 - Hour Clock   * *     24 - Hour Clock     *" << endl;
	cout << "*       "; DisplayTime(false); //DisplayTime(false)
	cout << "       * *        "; DisplayTime(true); //DisplayTime(true)
	cout << "         *" << endl;
	cout << "*************************** ***************************" << endl; 
	cout << endl;
	cout << endl;
}


//corrects clock/increments
void TimeAdjustment() {
	if (seconds >= 60) {
		minutes++;
		seconds = seconds - 60;
	}
	if (minutes >= 60) {
		hours++;
		minutes = minutes - 60;
	}
	if (hours >= 24) {
		hours = hours - 24;
	}
}
bool MenuInput(char option) {
	// Adds 1 hour
	if (option == '1') {
		hours++;
	}
	// Adds 1 minute 
	else if (option == '2') {
		minutes++;
	}
	// Adds 1 second 
	else if (option == '3') {
		seconds++;
	}
	// Program Exit and output message
	else if (option == '4') {
		cout << "Program End";
		cout << "Have a good day!";
		return false;

	}
	// Increments seconds by 1 
	else {
		seconds++;

	}
	//loop through menu until input 4
	seconds++;
	return true;
	
}
bool DisplayMenu() {
	cout << "Please choose an available option below." << endl;
	cout << "Any other input will reset the menu!" << endl;

	cout << "***************************" << endl;
	cout << "* 1 - Add One Hour        *" << endl;
	cout << "* 2 - Add One Minute      *" << endl;
	cout << "* 3 - Add One Second      *" << endl;
	cout << "* 4 - Exit Program        *" << endl;
	cout << "***************************" << endl;

	char option;
	cin >> option;
	return MenuInput(option);
}
	
int main() {
	
	bool clocksOn = true;
	//while Loop calls functions - displays clocks & menu/asks for new menu input and adjusts time based input
	while (clocksOn) {
			DisplayClocks();
			clocksOn = DisplayMenu();
			TimeAdjustment();
			std::cout << "\x1B[2J\x1B[H";
		
	}
	return 0;

}
