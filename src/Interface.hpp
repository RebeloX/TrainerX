#include "trainer.hpp"
#include <stdio.h>
#include <string>

class Interface
{
private:
	bool opened;
	std::string input;

public:
	Trainer trainer;

	void Start();
	void ShowMenu();
	int	 ProcessInput();
	void Close();
	bool IsOpen();
};