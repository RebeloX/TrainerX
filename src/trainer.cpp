#include "trainer.hpp" //trainer class

void Trainer::SetLife(float life) //setlife function
{
  	//write process memory with the new value
	int stat = WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_LIFE, &life, (DWORD)sizeof(life), NULL);

	if (stat <= 0){ //if it success it says this
		std::cerr << "Ocorreu algo inesperado, tente novamente." << std::endl;
		return;
	}
	std::clog << "Sucesso ao escrever na memoria com valor: " << life << std::endl;
}

//same thing as life
void Trainer::SetMoney(int money)
{
	int stat = WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_MONEY, &money, (DWORD)sizeof(money), NULL);

	if (stat <= 0){
		std::cerr << "Ocorreu algo inesperado, tente novamente." << std::endl;
		return;
	}
	std::clog << "Sucesso ao escrever na memoria com valor: " << money << std::endl;
}

//Entries: Red, Green, Blue, Alpha.
//Changes the color of health bar
void Trainer::SetHealthBarColor(int R, int G, int B, int A)
{
	if (WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_RED, &R, sizeof(R), NULL))
	if (WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_GREEN, &G, sizeof(G), NULL))
	if (WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_BLUE, &B, sizeof(B), NULL))
	if (WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_ALPHA, &A, sizeof(A), NULL))
	
	//it will write all the memories, if the previously won't return an error value.
}

//this one is diferent it has dynamic address, i did this way but i will probably use another way so i don't have to create
//multiple variables to declare each dynamic addres
void Trainer::SetArmor(float armor)
{
	unsigned long pointer = 0xB6F5F0; //CPed address
	unsigned long offset = 0x548; //armor address
	unsigned long address = pointer + offset; //the address's combined togther
	
	//same thing as the life, it writes a new value to the memory
	int stat = WriteProcessMemory(Trainer::memory.hProc, (LPVOID)address, &armor, (DWORD)sizeof(armor), NULL);

	if (stat <= 0){
		std::cerr << "Ocorreu algo inesperado, tente novamente." << std::endl;
		return;
	}

	std::clog << "Sucesso ao escrever na memoria com valor: " << armor << std::endl;
}
void Trainer::SetWantedLevel(int level)
{
	int stat = WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_WANTED, &level, (DWORD)sizeof(level), NULL);
	
	if (stat <= 0){
		std::cerr << "Ocorreu algo inesperado, tente novamente." << std::endl;
		return;
	}

	std::clog << "Sucesso ao escrever na memoria com valor: " << level << std::endl;
}

/* Future functions
void Trainer::SetX(double pos)
{
	int stat = WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_X, &pos, (DWORD)sizeof(pos), NULL);

	if (stat > 0){
		std::clog << "Sucesso ao escrever na memoria com valor: " << pos << std::endl;
	}
	else {
		std::cerr << "Ocorreu algo inesperado, tente novamente." << std::endl;
	}
}

void Trainer::SetY(double pos)
{
	int stat = WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_Y, &pos, (DWORD)sizeof(pos), NULL);

	if (stat > 0){
		std::clog << "Sucesso ao escrever na memoria com valor: " << pos << std::endl;
	}
	else {
		std::cerr << "Ocorreu algo inesperado, tente novamente." << std::endl;
	}
}

void Trainer::SetZ(double pos)
{
	int stat = WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_Z, &pos, (DWORD)sizeof(pos), NULL);

	if (stat > 0){
		std::clog << "Sucesso ao escrever na memoria com valor: " << pos << std::endl;
	}
	else {
		std::cerr << "Ocorreu algo inesperado, tente novamente." << std::endl;
	}
}

void Trainer::SetPos(double x,double y, double z)
{
	Trainer::SetX(x); Trainer::SetY(y); Trainer::SetZ(z);
}*/
