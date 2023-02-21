void mainArt() {
	system("cls");

	std::cout << R"(

__________            .___                   __      _________.__                                             
\______   \ __ __   __| _/   ____    ____  _/  |_   /   _____/|  |__    ____  ______  ______    ____  _______ 
 |    |  _/|  |  \ / __ |   / ___\ _/ __ \ \   __\  \_____  \ |  |  \  /  _ \ \____ \ \____ \ _/ __ \ \_  __ \
 |    |   \|  |  // /_/ |  / /_/  >\  ___/  |  |    /        \|   Y  \(  <_> )|  |_> >|  |_> >\  ___/  |  | \/
 |______  /|____/ \____ |  \___  /  \___  > |__|   /_______  /|___|  / \____/ |   __/ |   __/  \___  > |__|   
        \/             \/ /_____/       \/                 \/      \/         |__|    |__|         \/    

        )" << '\n';
};


void Update(Shops* shops, Recipies* r)
{
	r->calculateBestOption(shops);
}

void ShowSingleShop(Shop* shop) {
	cout << "------------------------" << endl;
	cout << "Shop Name :" << shop->shopName << endl;
	cout << "------------------------" << endl;
	shop->shopIngr->printIngredients();
	cout << "------------------------" << endl;
}
void AddANewSHop(Shops* ShopList,Recipies* r) {
	cout << "------------------------" << endl;

	string shopName;
	int size = ShopList->size;
	cout << "Enter Shop Name" << endl;
	/*cin.clear();
	cin.sync();*/
	getline(cin>>ws>>ws, shopName);
	Ingredients* list = new Ingredients();

	bool running = true;
	//

	while (running)
	{
		
		string name;
		int price;
		cout << "Enter Ingridient Name" << endl;
		
		getline(cin>>ws>>ws, name);
		cout << "Enter Ingridient Price" << endl;
		cin >> price;

		list->insertNewIngredient(new Ingredient(name, price, shopName));
		
		int k;
		cout << "Do you need to add more ingredients ? Enter '-1' to exit and '1' to add more" << endl;
		cin >> k;
		if (k == -1)
		{
			running = false;
		}
		
	}
	ShopList->insertFirst(new Shop(size++, shopName, list));
	cout << "------------------------" << endl;

	cout << "Shop Added Successfully \n";
	cout << "------------------------" << endl;

	//ShopList->print();
	Update(ShopList,r);
}


int SelectableShopList(Shops* ShopList) 
{
	cout << "------------------------" << endl;

	cout << "Select A Shop" << endl;
	ShopList->printAllShops();

	int selectedIndex;
	cin >> selectedIndex;
	
	return selectedIndex - 1;
}

int SelectableIngredientList(Ingredients* shopIngr) {
	cout << "------------------------" << endl;

	cout << "Select an Ingredient" << endl;
	shopIngr->printIngredientsOnly();
	int selectedIndex;
	cin >> selectedIndex;
	
	return selectedIndex;
}



void DeleteAShop(Shops *ShopList, Recipies* r)
{
	//cout << "Select a " << endl;
	int selectedShop = SelectableShopList(ShopList);
	ShopList->deleteAt(selectedShop);
	cout << "------------------------" << endl;

	cout << "Shop Deleted Successfully" << endl;
	cout << "------------------------" << endl;

	//cout << "New Shop List" << endl;

	//ShopList->print();
	Update(ShopList,r);

}

void EditShopIngredients(Shops* ShopList,Recipies* r) {
	int selectedShop = SelectableShopList(ShopList);
	Shop* selectedShopObj = ShopList->getShopAt(selectedShop);
	int selectedIngredient = SelectableIngredientList(selectedShopObj->shopIngr);
	cout << selectedIngredient;
	string key = selectedShopObj->shopIngr->selectIngredientAsKey(selectedIngredient);
	int pp;
	cout << "\nEnter new price for the item" << endl;
	cin >> pp;
	selectedShopObj->shopIngr->hashTable.at(key) = new Ingredient(key, pp, selectedShopObj->shopName);
	//ShopList->print();
	cout << "Updated Shop" << endl;
	ShowSingleShop(ShopList->getShopAt(selectedShop));
	Update(ShopList,r);
}


void AddNewShopIngredient(Shops* ShopList,Recipies* r) 
{
	int selectedShop = SelectableShopList(ShopList);
	int price; string name;
	cout << "Enter new Item name" << endl;
	
	getline(cin>>ws, name);
	cout << "Enter the price" << endl;
	cin >> price;
	Shop* selectedShopObject = ShopList->getShopAt(selectedShop);
	selectedShopObject->shopIngr->insertNewIngredient(new Ingredient(name,price,selectedShopObject->shopName));
	//selectedShopObject->shopIngr->printIngredients();
	cout << "------------------------" << endl;

	cout << "Updated Shop" << endl;

	ShowSingleShop(selectedShopObject);

	Update(ShopList,r);

}


void DeleteShopIngredient(Shops* ShopList,Recipies* r) 
{
	int selectedShop = SelectableShopList(ShopList);
	Shop* selectedShopObj = ShopList->getShopAt(selectedShop);
	int selectedIngredient = SelectableIngredientList(selectedShopObj->shopIngr);
	cout << selectedIngredient;
	string key = selectedShopObj->shopIngr->selectIngredientAsKey(selectedIngredient);
	selectedShopObj->shopIngr->hashTable.erase(key);
	//ShopList->print();
	cout << "Updated Shop" << endl;
	ShowSingleShop(selectedShopObj);

	Update(ShopList,r);
}

void ShowShopItems(Shops* ShopList,Recipies* r) {
	int selectedShop = SelectableShopList(ShopList);
	Shop* selectedShopObj = ShopList->getShopAt(selectedShop);
	ShowSingleShop(selectedShopObj);
	Update(ShopList,r);
}



Ingredients* getUniqueIngredients(Shops* ShopList) 
{
	ShopList->getUniqueIngredientList();
	return ShopList->uniqueList;
}



void AddNewRecipie(Shops* ShopList, Recipies* myR)
{
	cout << "------------------------" << endl;

	Recipie* newR = new Recipie();
	Ingredients* currentUniqueIngs = getUniqueIngredients(ShopList);
	Ingredients* newList = new Ingredients();

	string rName;
	cout << "Enter a Recipie name " << endl;
	
	getline(cin>>ws, rName);
	newR->recipieName = rName;
	int selectedIng = 0;

	while (selectedIng != -1) {
		

		selectedIng = SelectableIngredientList(currentUniqueIngs);
		if (selectedIng != -1)
		{
			cout << "Enter '-1' to exit to stop adding" << endl;

			string selectedIngOb_key = currentUniqueIngs->selectIngredientAsKey(selectedIng);
			Ingredient* SelectedObject = currentUniqueIngs->hashTable.at(selectedIngOb_key);
			newList->insertNewIngredient(SelectedObject);
		}	
	}

	newR->currentList = newList;
	myR->insertFirst(newR);
	//cout << newR->recipieName;
	//newR->currentList->printIngredients();
	Update(ShopList, myR);
}

int SelectableRecipieList(Recipies* rList) 
{
	cout << "------------------------" << endl;
	cout << "Select A Recipie" << endl;
	rList->getRecipieNames();

	int selectedIndex;
	cin >> selectedIndex;

	return selectedIndex - 1;
}

void DisplayRecipie(Recipies* r,Shops* s)
{
	r->calculateBestOption(s);
	if (r->size > 0)
	{
		int selectedRecipieIndex = SelectableRecipieList(r);
		Recipie* selectedRecipie = r->getRecipieAt(selectedRecipieIndex);
		cout << "------------------------" << endl;
		cout << "Recipie Name :" << selectedRecipie->recipieName <<endl;
		cout << "------------------------" << endl;
		cout << "Recipie list" << endl;
		cout << "------------------------" << endl;

		selectedRecipie->currentList->printIngredientsOnly();
		cout << "------------------------" << endl;
		cout << "Buying Recommendation" << endl;
		cout << "------------------------" << endl;
		selectedRecipie->bestOption->printIngredientsFull();
		cout << "------------------------" << endl;

	}
	else {
		cout << "No Recipies Found" << endl;

	}
	

}


void DeleteARecipieIngredient(Recipies* r,Shops* sList) 
{
	cout << "Select the Recipie" << "\n";
	int selected = SelectableRecipieList(r);
	Recipie* selectedRecipie = r->getRecipieAt(selected);
	cout << "Select An Ingredient to Delete" << endl;
	int selectedIngredient = SelectableIngredientList(selectedRecipie->currentList);
	string key = selectedRecipie->currentList->selectIngredientAsKey(selectedIngredient);
	selectedRecipie->currentList->hashTable.erase(key);
	selectedRecipie->currentList->hashTable.erase(key);
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
			Ingredient* SelectedObject = currentUniqueIngs->hashTable.at(selectedIngOb_key);
			selectedRecipie->currentList->insertNewIngredient(SelectedObject);
			cout << "Ingredient successfully added to the Recipie" << endl;
		}
	}

	Update(ShopList,r);

}


