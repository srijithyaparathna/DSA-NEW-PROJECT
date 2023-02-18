
void Update(Shops* shops, Recipies* r)
{
	r->calculateBestOption(shops);
}


void AddANewSHop(Shops* ShopList,Recipies* r) {
	cout << "------------------------" << endl;

	string shopName;
	int size = ShopList->size;
	cout << "Enter Shop Name" << endl;
	cin >> shopName;
	Ingredients* list = new Ingredients();

	bool running = true;
	while (running)
	{
		
		string name;
		int price;
		cout << "Enter Ingridient Name" << endl;
		cin >> name;
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

	cout << "Shop Added Successfully \n";

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
	cout << "------------------------" << endl;

	Recipie* newR = new Recipie();
	Ingredients* currentUniqueIngs = getUniqueIngredients(ShopList);
	Ingredients* newList = new Ingredients();

	string rName;
	cout << "Enter a Recipie name " << endl;
	cin >> rName;
	newR->recipieName = rName;
	int selectedIng = 0;
	cout << "Enter '-1' to exit to stop adding" << endl;

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

int SelectableRecipieList(Recipies* rList) 
{
	cout << "------------------------" << endl;
	cout << "Select A Recipie" << endl;
	rList->getRecipieNames();

	int selectedIndex;
	cin >> selectedIndex;

	return selectedIndex - 1;
}

void DisplayRecipie(Recipies* r)
{
	if (r->size > 0)
	{
		int selectedRecipieIndex = SelectableRecipieList(r);
		Recipie* selectedRecipie = r->getRecipieAt(selectedRecipieIndex);
		cout << "Recipie list" << endl;
		selectedRecipie->currentList->printIngredientsOnly();
		cout << "Buying Recommendation" << endl;
		selectedRecipie->currentList->printIngredientsFull();
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


