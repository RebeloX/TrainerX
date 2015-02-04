#include "trainer.hpp"
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>


void Trainer::SetMoney(int money)
{
	int stat = WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_MONEY, &money, (DWORD)sizeof(money), NULL);

	if (stat > 0){
		std::clog << "Sucesso ao escrever na memoria com valor: " << money << std::endl;
	}
	else {
		std::cerr << "Ocorreu algo inesperado, tente novamente." << std::endl;
	}
}

void Trainer::SetArmor(float armor)
{
	unsigned long pointer = 0xB6F5F0; //CPed address

	DWORD pCPed; //the var which will hold the player PED struct value.

	//reading the value from 0xB6F5F0 into pCPed
	ReadProcessMemory(Trainer::memory.hProc, (LPVOID)pointer, &pCPed, sizeof(pointer), NULL);

	unsigned long offset = 0x548; //armor address
	LPVOID address = (LPVOID)(pCPed + offset); //the address's combined togther

	//same thing as the life, it writes a new value to the memory
	int stat = WriteProcessMemory(Trainer::memory.hProc, address, &armor, (DWORD)sizeof(armor), NULL);
	if (stat > 0){
		MessageBox(NULL, (LPCSTR)"Armour value has been replaced to the new one!", (LPCSTR)"Sucess", MB_ICONINFORMATION | MB_OK);
	
	}
	else {
		MessageBox(NULL, (LPCSTR)"We couldn't replace the value, his gta_sa.ex open?", (LPCSTR)"Sucess", MB_ICONINFORMATION | MB_OK );
		
	}
}

template< typename T >
std::string int_to_hex(T i)
{
	std::stringstream stream;
	stream << std::hex << i;
	return stream.str();
}
std::stringstream hex_to_int(std::string str)
{
	std::stringstream stream;
	stream << std::hex << str;
	return stream;
}

unsigned int abgr_to_dec(int a, int b, int g, int r)
{
	std::string _r = int_to_hex(r);
	std::string _g = int_to_hex(g);
	std::string _b = int_to_hex(b);
	std::string _a = int_to_hex(a);

	std::string _abgr = _a + _b + _g + _r;
	unsigned int abgr; hex_to_int(_abgr) >> abgr;
	return abgr;
}

void Trainer::SetHealthBarColor(int R, int G, int B, int A)
{
	//FF - FF - FF - FF
	unsigned int rgba = abgr_to_dec(A, B, G, R);

	if (!WriteProcessMemory(Trainer::memory.hProc, (LPVOID)Trainer::TRAINER_RGBA, &rgba, sizeof(R), NULL))
	{
		MessageBox(NULL, (LPCSTR)"We couldn't replace the value, his gta_sa.ex open?", (LPCSTR)"Sucess", MB_ICONINFORMATION | MB_OK);
	} else {
		MessageBox(NULL, (LPCSTR)"Health bar color has been replaced by a new one!", (LPCSTR)"Sucess", MB_ICONINFORMATION | MB_OK);
	}

	//it will write all the memories, if the previously won't return an error value.
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

void Trainer::SetLife(float life)
{
	unsigned long pointer = 0xB6F5F0; //CPed address

	DWORD pCPed; //the var which will hold the player PED struct value.

	ReadProcessMemory(Trainer::memory.hProc, (LPVOID)pointer, &pCPed, sizeof(pointer), NULL);

	unsigned long offset = 0x540; //health address
	LPVOID address = (LPVOID)(pCPed + offset); //the address's combined togher

	int stat = WriteProcessMemory(Trainer::memory.hProc, address, &life, (DWORD)sizeof(life), NULL);

	if (stat > 0){
		MessageBox(NULL, (LPCSTR)"Health value has been replaced to the new one!", (LPCSTR)"Sucess", MB_ICONINFORMATION | MB_OK);

	}
	else {
		MessageBox(NULL, (LPCSTR)"We couldn't replace the value, his gta_sa.ex open?", (LPCSTR)"Sucess", MB_ICONINFORMATION | MB_OK);

	}
}
/*
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
}
*/