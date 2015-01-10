#include "Interface.hpp" //Interface Class defenition

void Interface::Start() //Start function
{
		printf("A inicializar o programa.."); //Starting the program
		if (!trainer.memory.InitializeMemoryHandler())  //Initialize the Memory Handler and verifys if it failed
		{
			printf("não foi possível iniciar!"); //It wasn't possible to start, probably the program is closed
			Interface::Close(); //Close the program
		}
}

void Interface::ShowMenu() //Show function
{
	system("cls"); //clear the screen
	printf("O que deseja alterar? "); //What you want to change?
	std::cin >> Interface::input; //Gets the user input
	Interface::ProcessInput(); //Process the user Input
}


int Interface::ProcessInput()
{
	if (Interface::input == "vida") //health cheat
	{
	  //this is a test version, it was created to get the actual player health.
		float value = 0;
		ReadProcessMemory(Interface::trainer.memory.hProc, (LPCVOID)Interface::trainer.TRAINER_LIFE, &value, sizeof(value), 0);
    //end
    
		system("cls"); //clears the screen
		std::cout << "Valor atual: " << value << std::endl; //actual player health, referd on top /\
		printf("Novo valor: "); //New value
		std::cin >> value; //gets the new value
		trainer.SetLife(value); //Sets the new value using the trainer class

	} else if (Interface::input == "dinheiro") { //money cheat
		int value; //value
		system("cls"); //clears the screen
		
		printf("Novo valor: "); //New value
		std::cin >> value; //gets the new value
		trainer.SetMoney(value); //sets the new value using the trainer class
	}else if (Interface::input == "armadura") { //armor
		float  value; //value
		system("cls"); //clears the screen

		printf("Novo valor: "); //New value
		std::cin >> value; //gets the new value
		trainer.SetArmor(value); //sets the new value using the trainer class
	}else if (Interface::input == "sair") { //exit
		Interface::Close(); //Close the program
	}
	return 1;
}

void Interface::Close() //Close function
{
	this->opened = false; //sets the opened variable to false
}

bool Interface::IsOpen(){ return opened; } //gets the opened variable value
