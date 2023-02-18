//void Update(Shops *shopList) {
//	shopList->budgetListGen();
//	cout << "Updated" << endl;
//}

void Update(Shops* shops, Recipies* r)
{
	r->calculateBestOption(shops);
}


void AddANewSHop(Shops* ShopList,Recipies* r) {
	string shopName;
	cout << "eneter shop name" << endl;
	cin >> shopName;
	Ingredients* list = new Ingredients();

	bool running = true;
	while (running)
	{
		string name;
		int price;
		cout << "Enter ingr name" << endl;
		cin >> name;
		cout << "Enter ingr price" << endl;
		cin >> price;

		list->insertNewIngredient(new Ingredient(name, price, shopName));
		running = false;
	}
	ShopList->insertFirst(new Shop(2, shopName, list));
	cout << "Added";

	ShopList->print();
	Update(ShopList,r);
}


int SelectableShopList(Shops* ShopList) {
	
	cout << "select a shop" << endl;
	ShopList->printAllShops();

	int selectedIndex;
	cin >> selectedIndex;
	
	return selectedIndex - 1;
}

int SelectableIngredientList(Ingredients* shopIngr) {

	cout << "select a shop" << endl;
	shopIngr->printIngredients();
	int selectedIndex;
	cin >> selectedIndex;
	
	return selectedIndex;
}



void DeleteAShop(Shops *ShopList, Recipies* r)
{
	int selectedShop = SelectableShopList(ShopList);
	ShopList->deleteAt(selectedShop);
	ShopList->print();
	Update(ShopList,r);

}

void EditShopIngredients(Shops* ShopList,Recipies* r) {
	int selectedShop = SelectableShopList(ShopList);
	Shop* selectedShopObj = ShopList->getShopAt(selectedShop);
	int selectedIngredient = SelectableIngredientList(selectedShopObj->shopIngr);
	cout << selectedIngredient;
	string key = selectedShopObj->shopIngr->selectIngredientAsKey(selectedIngredient);
	int pp;
	cout << "Enter new price for the item" << endl;
	cin >> pp;


	selectedShopObj->shopIngr->umap.at(key) = new Ingredient(key, pp, selectedShopObj->shopName);
	ShopList->print();
	Update(ShopList,r);
}


void AddNewShopIngredient(Shops* ShopList,Recipies* r) 
{
	int selectedShop = SelectableShopList(ShopList);
	int price; string name;
	cout << "Enter new Item name" << endl;
	cin >> name;
	cout << "Enter the price" << endl;
	cin >> price;
	Shop* selectedShopObject = ShopList->getShopAt(selectedShop);
	selectedShopObject->shopIngr->insertNewIngredient(new Ingredient(name,price,selectedShopObject->shopName));
	selectedShopObject->shopIngr->printIngredients();

	Update(ShopList,r);

}


void DeleteShopIngredient(Shops* ShopList,Recipies* r) 
{
	int selectedShop = SelectableShopList(ShopList);
	Shop* selectedShopObj = ShopList->getShopAt(selectedShop);
	int selectedIngredient = SelectableIngredientList(selectedShopObj->shopIngr);
	cout << selectedIngredient;
	string key = selectedShopObj->shopIngr->selectIngredientAsKey(selectedIngredient);
	selectedShopObj->shopIngr->umap.erase(key);
	ShopList->print();
	Update(ShopList,r);
}

void ShowShopItems(Shops* ShopList,Recipies* r) {
	int selectedShop = SelectableShopList(ShopList);
	Shop* selectedShopObj = ShopList->getShopAt(selectedShop);
	selectedShopObj->shopIngr->printIngredients();
	Update(ShopList,r);
}

Ingredients* getUniqueIngredients(Shops* ShopList) 
{
	ShopList->getUniqueIngredientList();
	return ShopList->uniqueList;
}



void AddNewRecipie(Shops* ShopList, Recipies* myR)
{
	Recipie* newR = new Recipie();
	Ingredients* currentUniqueIngs = getUniqueIngredients(ShopList);
	Ingredients* newList = new Ingredients();

	string rName;
	cout << "Enter a recipeie name " << endl;
	cin >> rName;
	newR->recipieName = rName;
	int selectedIng = 0;

	while (selectedIng != -1) {

		selectedIng = SelectableIngredientList(currentUniqueIngs);
		if (selectedIng != -1)
		{
			string selectedIngOb_key = currentUniqueIngs->selectIngredientAsKey(selectedIng);
			Ingredient* SelectedObject = currentUniqueIngs->umap.at(selectedIngOb_key);
			newList->insertNewIngredient(SelectedObject);
		}	
	}

	newR->currentList = newList;
	myR->insertFirst(newR);
	//cout << newR->recipieName;
	//newR->currentList->printIngredients();
	Update(ShopList, myR);
}

int SelectableRecipieList(Recipies* rList) {

	cout << "select a shop" << endl;
	rList->getRecipieNames();

	int selectedIndex;
	cin >> selectedIndex;

	return selectedIndex - 1;
}

void DisplayRecipie(Recipies* r)
{

	int selectedRecipieIndex = SelectableRecipieList(r);
	Recipie* selectedRecipie = r->getRecipieAt(selectedRecipieIndex);
	cout << "Input list" << endl;
	selectedRecipie->currentList->printIngredients();
	cout << "Buying Recommendation" << endl;
	selectedRecipie->currentList->printIngredientsFull();

}


void DeleteARecipieIngredient(Recipies* r) 
{
	cout << "Select the Recipie" << "\n";
	int selected = SelectableRecipieList(r);
	Recipie* selectedRecipie = r->getRecipieAt(selected);
	cout << "Select An Ingredient to Delete" << endl;
	int selectedIngredient = SelectableIngredientList(selectedRecipie->currentList);
	string key = selectedRecipie->currentList->selectIngredientAsKey(selectedIngredient);
	selectedRecipie->currentList->umap.erase(key);
	selectedRecipie->currentList->umap.erase(key);
	cout << "Successfully deleted." << endl;
}


void DeleteARecipie(Recipies* r)
{
	cout << "Select a Recipie to Delete." << "\n";
	int selected = SelectableRecipieList(r);
	//Recipie* selectedRecipie = r->getRecipieAt(selected);
	r->deleteAt(selected);
	cout << "Recipie Deleted Successfully" << endl;
}

void AddNewIngredientToARecipie(Recipies* r,Shops *ShopList) 
{
	cout << "Select the Recipie" << "\n";
	Ingredients* currentUniqueIngs = getUniqueIngredients(ShopList);
	int selected = SelectableRecipieList(r);
	Recipie* selectedRecipie = r->getRecipieAt(selected);
	int selectedIng = 0;

	while (selectedIng != -1) {

		selectedIng = SelectableIngredientList(currentUniqueIngs);
		if (selectedIng != -1)
		{
			string selectedIngOb_key = currentUniqueIngs->selectIngredientAsKey(selectedIng);
			Ingredient* SelectedObject = currentUniqueIngs->umap.at(selectedIngOb_key);
			selectedRecipie->currentList->insertNewIngredient(SelectedObject);
			cout << "Ingredient successfully added to the Recipie" << endl;
		}
	}

	Update(ShopList,r);

}


void MainMenu() {
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
}