#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// ------------------ Linked List Node ------------------
struct IngredientNode {
    string name;
    double price;
    IngredientNode* next;

    IngredientNode(string n, double p) {
        name = n;
        price = p;
        next = NULL;
    }
};

// ------------------ Shop Class ------------------
class Shop {
public:
    string shopName;
    IngredientNode* head;

    Shop(string name) {
        shopName = name;
        head = NULL;
    }

    // Add ingredient (Linked List insertion at end)
    void addIngredient(string name, double price) {
        IngredientNode* newNode = new IngredientNode(name, price);

        if (head == NULL) {
            head = newNode;
        } else {
            IngredientNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display ingredients
    void displayIngredients() {
        IngredientNode* temp = head;
        cout << "Ingredients in " << shopName << ":\n";
        while (temp != NULL) {
            cout << temp->name << " - Rs." << temp->price << endl;
            temp = temp->next;
        }
    }
};

// ------------------ Main Program ------------------
int main() {

    vector<Shop> shops;

    int shopCount;
    cout << "Enter number of shops: ";
    cin >> shopCount;

    for (int i = 0; i < shopCount; i++) {
        string shopName;
        cout << "\nEnter shop name: ";
        cin >> shopName;

        Shop shop(shopName);

        int ingredientCount;
        cout << "Enter number of ingredients in " << shopName << ": ";
        cin >> ingredientCount;

        for (int j = 0; j < ingredientCount; j++) {
            string ingName;
            double price;

            cout << "Ingredient name: ";
            cin >> ingName;
            cout << "Price: ";
            cin >> price;

            shop.addIngredient(ingName, price);
        }

        shops.push_back(shop);
    }

    // ------------------ Build Minimum Price Map ------------------
    unordered_map<string, double> minPrice;

    for (int i = 0; i < shops.size(); i++) {
        IngredientNode* temp = shops[i].head;

        while (temp != NULL) {
            if (minPrice.find(temp->name) == minPrice.end()) {
                minPrice[temp->name] = temp->price;
            } else {
                minPrice[temp->name] = min(minPrice[temp->name], temp->price);
            }
            temp = temp->next;
        }
    }

    // ------------------ Recipe Section ------------------
    int recipeCount;
    cout << "\nEnter number of ingredients in recipe: ";
    cin >> recipeCount;

    double totalCost = 0;

    for (int i = 0; i < recipeCount; i++) {
        string recipeIngredient;
        cout << "Enter recipe ingredient: ";
        cin >> recipeIngredient;

        if (minPrice.find(recipeIngredient) != minPrice.end()) {
            totalCost += minPrice[recipeIngredient];
        } else {
            cout << recipeIngredient << " not available in any shop.\n";
        }
    }

    cout << "\nMinimum cost to prepare recipe: Rs." << totalCost << endl;

    return 0;
}
