#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

void ai(std::vector<int> &save, std::string& slot)
{
	if(save[1] == 20)
	{
		if(save[2] + save[3] == 2 || save[4] + save[7] == 2 || save[5] + save[9] == 2)
		{
			save[1] = 4;
			slot.replace(1, 1, "O");
			return;
		}
	}
	if(save[2] == 20)
	{
		if(save[1] + save[3] == 2 || save[5] + save[8] == 2)
		{
			save[2] = 4;
			slot.replace(2, 1, "O");
			return;
		}
	}
	if(save[3] == 20)
		{
		if(save[1] + save[2] == 2 || save[5] + save[7] == 2 || save[6] + save[9] == 2)
		{
			save[3] = 4;
			slot.replace(3, 1, "O");
			return;				
		}
	}
	if(save[4] == 20)
	{
		if(save[1] + save[7] == 2 || save[5] + save[6] == 2)
		{
			save[4] = 4;
			slot.replace(4, 1, "O");
			return;
		}
	}
	if(save[5] == 20)
	{
		if(save[2] + save[8] == 2 || save[4] + save[6] == 2 || save[1] + save[9] == 2 || save[3] + save[7] == 2)
		{
			save[5] = 4;
			slot.replace(5, 1, "O");
			return;
		}
	}
	if(save[6] == 20)
	{
		if(save[4] + save[5] == 2 || save[3] + save[9] == 2)
		{
			save[6] = 4;
			slot.replace(6, 1, "O");
			return;
		}
	}
	if(save[7] == 20)
	{
		if(save[1] + save[4] == 2 || save[8] + save[9] == 2 || save[5] + save[3] == 2)
		{
			save[7] = 4;
			slot.replace(7, 1, "O");
			return;
		}	
	}
	if(save[8] == 20)
	{
		if(save[2] + save[5] == 2 || save[7] + save[9] == 2)
		{
			save[8] = 4;
			slot.replace(8, 1, "O");
						return;
		}
	}
	if(save[9] == 20)
	{
		if(save[3] + save[6] == 2 || save[7] + save[8] == 2 || save[1] + save[5] == 2)	
		{
			save[9] = 4;
			slot.replace(9, 1, "O");
			return;
		}
	}
	std::string temp;
	while(temp != "-")
	{
		int random = rand() % 9 + 1;
		temp = slot[random];
		if(temp == "-")
		{
			save[random] = 4;
			slot.replace(random, 1, "O");
			return;
		}
	}
}

void print_graph(std::string& slot) 
{
	std::string temp;
	for(int i = 1; i <= 9; i++)
	{
		std::cout << slot[i] << " ";
		if(i == 3 || i == 6 || i == 9) std::cout << std::endl;
	}
	std::cout << std::endl;
	for(int i = 1; i <= 9; i++)	
	{
		temp = slot[i];
		if(temp == "-") std::cout << i << " ";
		else std::cout << "~ ";
		if(i == 3 || i == 6 || i == 9) std::cout << std::endl;
	}
	std::cout << "\n";
}

void end_result(std::string& slot) 
{
	std::string temp;
	for(int i = 1; i <= 9; i++)
	{
		std::cout << slot[i] << " ";
		if(i == 3 || i == 6 || i == 9) std::cout << "\n";
	}
}

void guide() 
{
	std::cout << "I'm your guide Alex and im going to show you how to play this game.\n Slots in the grid will be ordered by numbers as shown below.\n\n";
	for(int i = 1; i <= 9; i++)
	{
		std::cout << i << " ";
		if(i == 3 || i == 6 || i == 9) std::cout << std::endl;
	}
	std::cout << "\nAvailable slots will be marked as [-]\nYou and your opponent's marks will me shown as [X] or [O]\nYou win by placing 3 consecutive marks in across, vertically and horizontally\nMy job here is done. I wish you good luck in your games.\n\n";
}

void single_player()
{
	std::vector<int> save = {20,20,20,20,20,20,20,20,20,20};
	int input, count = 0;
	std::string slot = "----------", temp;
	do
	{
		std::cout << "Your turn\n";
		print_graph(slot);
		std::cin >> input;
		std::cout << std::endl;
		do
		{
			temp = slot[input];
			if(temp == "-")
			{
				slot.replace(input, 1, "X");
				save[input] = 1;
				count++;
				break;
			} else
			{
				print_graph(slot);
			std::cin >>input;
			std::cout << std::endl;
			}
		} while(temp != "X");
		if(save[1] + save[2] + save[3] == 3 || save[4] + save[5] + save[6] == 3 || save[7] + save[8] + save[9] == 3 || save[1] + save[4] + save[7] == 3 || save[2] + save[5] + save[8] == 3 || save[3] + save[6] + save[9] == 3 || save[1] + save[5] + save[9] == 3 ||save[3] + save[5] + save[7] == 3)
		{
			std::cout << "You Win\n";
			end_result(slot);
			return;
		} else if(save[1] + save[2] + save[3] == 12 || save[4] + save[5] + save[6] == 12 || save[7] + save[8] + save[9] == 12 || save[1] + save[4] + save[7] == 12 || save[2] + save[5] + save[8] == 12 || save[3] + save[6] + save[9] == 12 || save[1] + save[5] + save[9] == 12 ||save[3] + save[5] + save[7] == 12)
		{
			std::cout << "You Lose\n";
			end_result(slot);
			return;
		}
		if(count == 5)
		{
			std::cout << "Draw!\n";
			end_result(slot);
			return;
		}
		ai(save, slot);
		if(save[1] + save[2] + save[3] == 3 || save[4] + save[5] + save[6] == 3 || save[7] + save[8] + save[9] == 3 || save[1] + save[4] + save[7] == 3 || save[2] + save[5] + save[8] == 3 || save[3] + save[6] + save[9] == 3 || save[1] + save[5] + save[9] == 3 ||save[3] + save[5] + save[7] == 3)
		{
			std::cout << "You Win\n";
			end_result(slot);
			return;
		} else if(save[1] + save[2] + save[3] == 12 || save[4] + save[5] + save[6] == 12 || save[7] + save[8] + save[9] == 12 || save[1] + save[4] + save[7] == 12 || save[2] + save[5] + save[8] == 12 || save[3] + save[6] + save[9] == 12 || save[1] + save[5] + save[9] == 12 ||save[3] + save[5] + save[7] == 12)
		{
			std::cout << "You Lose\n";
			end_result(slot);
			return;
		}
		if(count == 5)
		{
			std::cout << "Draw!\n";
			end_result(slot);
			return;
		}
	} while(true);
}

void two_player() 
{
	std::vector<int> save = {20,20,20,20,20,20,20,20,20,20};
	int input, count = 0;
	std::string slot = "----------", temp, player, play;
	std::cout << "What is the name of P1?\n";
	std::cin >> player;
	std::cout << "What is the name of P2?\n";
	std::cin >> play;
	do
	{
		std::cout << "\n" << player <<"'s turn\n";
		print_graph(slot);
		std::cin >> input;
		do
		{
			temp = slot[input];
			if(temp == "-")
			{
				slot.replace(input, 1, "X");
				save[input] = 1;
				count++;
				break;
			} else
			{
				print_graph(slot);
			std::cout << std::endl;
			std::cin >>input;
			}
		} while(temp != "X");
		if(save[1] + save[2] + save[3] == 3 || save[4] + save[5] + save[6] == 3 || save[7] + save[8] + save[9] == 3 || save[1] + save[4] + save[7] == 3 || save[2] + save[5] + save[8] == 3 || save[3] + save[6] + save[9] == 3 || save[1] + save[5] + save[9] == 3 ||save[3] + save[5] + save[7] == 3) 
		{
			std::cout << player << " Won\n";
			end_result(slot);
			return;
		} else if(save[1] + save[2] + save[3] == 12 || save[4] + save[5] + save[6] == 12 || save[7] + save[8] + save[9] == 12 || save[1] + save[4] + save[7] == 12 || save[2] + save[5] + save[8] == 12 || save[3] + save[6] + save[9] == 12 || save[1] + save[5] + save[9] == 12 ||save[3] + save[5] + save[7] == 12) 
		{
			std::cout << play << " Won\n";
			end_result(slot);
			return;
		}
		std::cout << "\n" << play << "'s turn\n";
		print_graph(slot);
		std::cout << std::endl;
		std::cin >> input;
		do
		{
			temp = slot[input];
			if(temp == "-") 
			{
				slot.replace(input, 1, "O");
				save[input] = 4;
				count++;
				break;
			} else
			{
				print_graph(slot);
			std::cout << std::endl;
			std::cin >>input;
			}
		} while(temp != "O");
		if(save[1] + save[2] + save[3] == 3 || save[4] + save[5] + save[6] == 3 || save[7] + save[8] + save[9] == 3 || save[1] + save[4] + save[7] == 3 || save[2] + save[5] + save[8] == 3 || save[3] + save[6] + save[9] == 3 || save[1] + save[5] + save[9] == 3 ||save[3] + save[5] + save[7] == 3) 
		{
			std::cout << player << " Won\n";
			end_result(slot);
			return;
		} else if(save[1] + save[2] + save[3] == 12 || save[4] + save[5] + save[6] == 12 || save[7] + save[8] + save[9] == 12 || save[1] + save[4] + save[7] == 12 || save[2] + save[5] + save[8] == 12 || save[3] + save[6] + save[9] == 12 || save[1] + save[5] + save[9] == 12 ||save[3] + save[5] + save[7] == 12) 
		{
			std::cout << play << " Won\n";
			end_result(slot);
			return;
		}
	} while(true);
}

void play_game() 
{
	int selection;
	std::cout << "1 for single player\n2 for two player\n3 for guide\n";
	std::cin >> selection;
	std::cout << std::endl;
		switch(selection)
		{
			case 1:
				single_player();
				break;
			case 2:
				two_player();
				break;
			case 3:
				guide();
				break;
		}
}

int main() 
{
	srand(time(0));
	int start;
	do
	{
		std::cout << "Welcome to tic tac toe\nPlease enter:\n1 to play\n0 to exit\n";
		std::cin >> start;
		std::cout << std::endl;
		switch(start)
		{
			case 0:
				std::cout << "See you next time";
				return 0;
			case 1:
				play_game();
				break;
		}
	} while(true);
	return 0;
}
