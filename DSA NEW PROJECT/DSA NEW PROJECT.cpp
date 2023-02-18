
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
	

    int main_choice, sub_choice;

    while (true) {
        system("cls");
        std::cout << R"(

__________            .___                   __      _________.__                                             
\______   \ __ __   __| _/   ____    ____  _/  |_   /   _____/|  |__    ____  ______  ______    ____  _______ 
 |    |  _/|  |  \ / __ |   / ___\ _/ __ \ \   __\  \_____  \ |  |  \  /  _ \ \____ \ \____ \ _/ __ \ \_  __ \
 |    |   \|  |  // /_/ |  / /_/  >\  ___/  |  |    /        \|   Y  \(  <_> )|  |_> >|  |_> >\  ___/  |  | \/
 |______  /|____/ \____ |  \___  /  \___  > |__|   /_______  /|___|  / \____/ |   __/ |   __/  \___  > |__|   
        \/             \/ /_____/       \/                 \/      \/         |__|    |__|         \/    

        )" << '\n';
        std::cout << "------------------Main Menu---------------- \n";

        std::cout << "(1)Manage Shop\n(2)Manage Recipies\n(3)About \n\n ";
        cout << "Enter your choice: ";
        cin >> main_choice;
        switch (main_choice) {
        case 1:
            while (true) {
                std::cout << "------------------Manage Shop----------------\n\n(1)Add New Shop\n(2)Delete Shop\n(3)Edit Shop Ingrediant\n(4)Add New Shop Ingredient\n(5)Delete Shop Ingredint\n(6)Display Ingredient\n(7)Back\n";

                cout << "Enter your choice: ";
                cin >> sub_choice;

                switch (sub_choice) {
                case 1:
                    AddANewSHop(GalleShops, MyRecipies);
                    break;
                case 2:
                    DeleteAShop(GalleShops, MyRecipies);
                    break;
                case 3:
                    EditShopIngredients(GalleShops, MyRecipies);
                    break;
                case 4:
                    AddNewShopIngredient(GalleShops, MyRecipies);
                    break;
                case 5:
                    DeleteShopIngredient(GalleShops, MyRecipies);
                    break;
                case 6:
                    ShowShopItems(GalleShops, MyRecipies);
                    break;
                case 7:
                    goto main_menu;
                default:
                    cout << "Invalid choice." << endl;
                    break;
                }
            }
            break;
        case 2:
            while (true) {
                std::cout << "--------------------Manage Recipies--------------------\n\n(1)Add New Recipe\n(2)Delete Recipe\n(3)Delete a Recipie Ingredient\n(4)Add a New Ingredient to a Recipe\n(5)Display Recipe\n(6)Back\n";
                cout << "Enter your choice: ";
                cin >> sub_choice;

                switch (sub_choice) {
                case 1:
                    AddNewRecipie(GalleShops, MyRecipies);
                    break;
                case 2:
                    DeleteARecipie(MyRecipies);
                    break;
                case 3:
                    DeleteARecipieIngredient(MyRecipies,GalleShops);
                    break;
                case 4:
                    AddNewIngredientToARecipie(MyRecipies,GalleShops);
                    break;
                case 5:
                    DisplayRecipie(MyRecipies);
                    break;
                case 6:
                    // Go back to the main menu
                    goto main_menu;
                default:
                    cout << "Invalid choice." << endl;
                    break;
                }
            }
            break;
        case 3:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

    main_menu:
        // This label allows the user to go back to the main menu from the submenus
        continue;
    }

    return 0;


	


}