
// DSA Mini Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>
int main()
{


	int MSMR;
	do {
		std::cout << "(1)Manage Shop \n(2)Manage Recipies\n(3)About \n\n ";
		if (!(std::cin >> MSMR)) {
			// clear the input stream and ignore any remaining characters
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInvalid input. Please enter a number.\n";
		}
		else if (MSMR < 1 || MSMR > 3) {
			std::cout << "\nInvalid Number. Please enter a number between 1 and 3.\n";
		}
	} while (MSMR < 1 || MSMR > 3);



		int new1;
		do {
			std::cout << "------------------Manage Shop---------------- - \n\n(1)Add New Shop\n(2)Delete Shop\n(3)Edit Shop Ingrediant\n(4)Add New Shop Ingredient\n(5)Delete Shop Ingredint\n(6)Display Ingredient \n(7)Back\n";
			if (!(std::cin >> new1)) {
				// clear the input stream and ignore any remaining characters
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\nInvalid input. Please enter a number.\n";
			}
			else if (new1 < 1 || new1 > 7) {
				std::cout << "\nInvalid Number. Please enter a number between 1 and 7.\n";
			}
		} while (new1 < 1 || new1 > 7);




		switch (new1)
		{

		case 1:


			break;


		case 2:

			break;


		case 3:
			cout << "select Shop\n";
			break;

		case 4:
			cout << "select Shop\n";

			break;




		case 5:
			cout << "select Shop\n";
			break;



		case 6:

			break;




		case 7:

			break;


		default:
			break;
		}











		int new2;
		do {
			std::cout << "--------------------Manage Recipies--------------------\n\n(1)Add New Recipe\n(2)Delete Recipe\n(3)Display Recipe\n(4)Back\n";
			if (!(std::cin >> new2)) {
				// clear the input stream and ignore any remaining characters
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\nInvalid input. Please enter a number.\n";
			}
			else if (new2 < 1 || new2 > 4) {
				std::cout << "\nInvalid Number. Please enter a number between 1 and 4.\n";
			}
		} while (new2 < 1 || new2 > 4);





		}





















		cout << "You Selected About";
		break;
	}








	std::cout << "Hello World!\n";
}
