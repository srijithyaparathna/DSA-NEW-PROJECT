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
    ShopAIngredients->insertNewIngredient(new Ingredient("Jam", 200, "ShopA"));
    ShopAIngredients->insertNewIngredient(new Ingredient("Coconut", 100, "ShopA"));
    ShopAIngredients->insertNewIngredient(new Ingredient("Vanilla", 250, "ShopA"));
    ShopAIngredients->insertNewIngredient(new Ingredient("BakingPowder", 250, "ShopA"));
    ShopAIngredients->insertNewIngredient(new Ingredient("Fish", 250, "ShopA"));
    ShopAIngredients->insertNewIngredient(new Ingredient("Chillie", 100, "ShopA"));
    ShopAIngredients->insertNewIngredient(new Ingredient("Coconut Oil", 500, "ShopA"));





	//ShopB
	Ingredients* ShopBIngredients = new Ingredients();
	Ingredient* rice2 = new Ingredient("RICE", 400, "ShopB");
	Ingredient* eggs2 = new Ingredient("SUGAR", 200, "ShopB");
	//Ingredient* eggs = new Ingredient("EGGS", 100, "ShopA");
	ShopBIngredients->insertNewIngredient(rice2);
	ShopBIngredients->insertNewIngredient(eggs2);
    ShopBIngredients->insertNewIngredient(new Ingredient("Jam", 400, "ShopB"));
    ShopBIngredients->insertNewIngredient(new Ingredient("Coconut", 50, "ShopB"));
    ShopBIngredients->insertNewIngredient(new Ingredient("Vanilla", 300, "ShopB"));
    ShopBIngredients->insertNewIngredient(new Ingredient("BakingPowder", 200, "ShopB"));
    ShopBIngredients->insertNewIngredient(new Ingredient("Chicken", 200, "ShopB"));
    ShopBIngredients->insertNewIngredient(new Ingredient("Fish", 500, "ShopB"));
    ShopBIngredients->insertNewIngredient(new Ingredient("Coconut Oil", 100, "ShopB"));




	Shop* ShopB = new Shop(2, "ShopB", ShopBIngredients);
	Shop* ShopA = new Shop(1, "ShopA", ShopAIngredients);
	GalleShops->insertFirst(ShopA);
	GalleShops->insertFirst(ShopB);



 
    /*   Recipie* Cake = new Recipie();
    Cake->recipieName = "CAKE";
    Cake->currentList->insertNewIngredient(new Ingredient("Vanilla", 250, "ShopA"));
    Cake->currentList->insertNewIngredient(new Ingredient("BakingPowder", 250, "ShopA"));
    Cake->currentList->insertNewIngredient(new Ingredient("Sugar", 250, "ShopA"));
    MyRecipies->insertFirst(Cake);

    Recipie* Rice = new Recipie();
    Rice->recipieName = "FRIED RICE";
    Rice->currentList->insertNewIngredient(new Ingredient("RICE", 250, "ShopA"));
    Rice->currentList->insertNewIngredient(new Ingredient("EGGS", 250, "ShopA"));
    Rice->currentList->insertNewIngredient(new Ingredient("Fish", 250, "ShopA"));
    MyRecipies->insertFirst(Rice);*/

	//-------------------------------------------//



    int main_choice, sub_choice;

    while (true) {
        mainArt();
        std::cout << "------------------Main Menu---------------- \n";

        std::cout << "(1)Manage Shop\n(2)Manage Recipies\n\n ";
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
                    system("pause");
                    mainArt();
                    break;
                case 2:
                    DeleteAShop(GalleShops, MyRecipies);
                    system("pause");
                    mainArt();
                    break;
                case 3:
                    EditShopIngredients(GalleShops, MyRecipies);
                    system("pause");
                    mainArt();
                    break;
                case 4:
                    AddNewShopIngredient(GalleShops, MyRecipies);
                    system("pause");
                    mainArt();
                    break;
                case 5:
                    DeleteShopIngredient(GalleShops, MyRecipies);
                    system("pause");
                    mainArt();
                    break;
                case 6:
                    ShowShopItems(GalleShops, MyRecipies);
                    system("pause");
                    mainArt();

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
                    system("pause");
                    mainArt();
                    break;
                case 2:
                    DeleteARecipie(MyRecipies);
                    system("pause");
                    mainArt();
                    break;
                case 3:
                    DeleteARecipieIngredient(MyRecipies,GalleShops);
                    system("pause");
                    mainArt();
                    break;
                case 4:
                    AddNewIngredientToARecipie(MyRecipies,GalleShops);
                    system("pause");
                    mainArt();
                    break;
                case 5:
                    DisplayRecipie(MyRecipies,GalleShops);
                    system("pause");
                    mainArt();
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