#include "trainer.hpp" //includes the Trainer Class
#include <stdio.h> //Includes stidio functions
#include <string> //Includes std::string functions

class Interface //Used to connect the user to the program itself.
{
private:
	bool opened; //used for the while loop
	std::string input; //user input when chosing a cheat type

public:
	Trainer trainer; //The trainer class

	void Start(); //Starts the program
	void ShowMenu(); //Shows the menu, next release it will be something like ShowUI();
	int	 ProcessInput(); //Process the user input
	void Close(); //Close the program
	bool IsOpen(); //Returns the value of the opened variable
};
