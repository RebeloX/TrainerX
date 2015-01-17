#include "Interface.hpp" //Interface class
#include <locale.h> //Used to set language characters

int main(int argc, char **argv) { // Even if we don't use it, we should declare them, just for a better look.(Performance will be the same)
	
	Interface inter;

	setlocale(LC_ALL, "Portuguese"); //Set the language to Portuguese, you can modify if you want to
	inter.Start(); //Starts the UI (User Interface) its just a console...
	while (inter.IsOpen()) //Verifies if the console is open by using a variable.
	{
		Sleep(5000); //Sleeps a while because it has too.
		inter.ShowMenu(); //Show the menu (there isn't any menu yet)
	}
	return 0; //returns 0(SUCCESS).
}
