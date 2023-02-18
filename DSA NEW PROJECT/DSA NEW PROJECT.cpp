
// DSA Mini Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Recipies.h"

#include <string>
#include "Shops.h"
#include "Ingredients.h"
#include "DSA NEW PROJECT.h"
using namespace std;
int main()
{
	//Creating Shops Object where the list of shops are stored.
	Shops* GalleShops = new Shops();
	//Creating Recipies Object where the list of recipies are stored.
	Recipies* MyRecipies = new Recipies();

	//Creating dummy shops 
	//Shop A
	Ingredients* ShopAIngredients = new Ingredients();
	Ingredient* rice = new Ingredient("rice", 1000, "ShopA");
	Ingredient* eggs = new Ingredient("EGGS", 100, "ShopA");
	ShopAIngredients->insertNewIngredient(rice);
	ShopAIngredients->insertNewIngredient(eggs);


	//ShopB
	Ingredients* ShopBIngredients = new Ingredients();
	Ingredient* rice2 = new Ingredient("RICE", 400, "ShopB");
	Ingredient* eggs2 = new Ingredient("SUGAR", 200, "ShopB");
	//Ingredient* eggs = new Ingredient("EGGS", 100, "ShopA");
	ShopBIngredients->insertNewIngredient(rice2);
	ShopBIngredients->insertNewIngredient(eggs2);

	Shop* ShopB = new Shop(2, "ShopB", ShopBIngredients);
	Shop* ShopA = new Shop(1, "ShopA", ShopAIngredients);
	GalleShops->insertFirst(ShopA);
	GalleShops->insertFirst(ShopB);


	//-------------------------------------------//



	//AddANewSHop(GalleShops);

	//GalleShops->budgetListGen();
	//GalleShops->print();

	/*AddNewRecipie(GalleShops, MyRecipies);
	MyRecipies->calculateBestOption(GalleShops);*/
	/*AddANewSHop(GalleShops);
	DeleteAShop(GalleShops);
	EditShopIngredients(GalleShops);
	AddNewShopIngredient(GalleShops);
	DeleteShopIngredient(GalleShops);
	ShowShopItems(GalleShops);*/
	


	std::cout << "(1)Manage Shop \n(2)Manage Recipies\n(3)About \n\n ";

	
	while (true)
	{
		int selection;
		std::cout << "Enter your selection: ";
		std::cin >> selection;

		switch (selection)
		{
		case 1:
			// Handle option 1
			std::cout << "You selected option 1.\n";
			break;

		case 2:
			// Handle option 2
			std::cout << "You selected option 2.\n";
			break;

		case 3:
			// Handle option 3
			std::cout << "You selected option 3.\n";
			break;

		case 4:
			// Quit the program
			std::cout << "Quitting...\n";
			return 0;

		default:
			std::cout << "Invalid selection.\n";
			break;
		}
	}

	



	


}