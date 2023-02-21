#pragma once
#include <iostream>
#include <string>
#include "Ingredients.h"
class Shop {
public :
	int shopId;
	string shopName;
    Ingredients* shopIngr;

    Shop() {
        shopId = 0;
        shopName = "";
    }

	Shop(int shId, string shName,Ingredients* shopIng) {
		shopId = shId;
		shopName = shName;
        shopIngr = shopIng;
	}

};


class ShopeNode {
public:
    Shop* shop;
    ShopeNode* next;

    ShopeNode() {
        shop = NULL;
        next = NULL;
    }

    ShopeNode(Shop* val) {
        shop = val;
        next = NULL;
    }
};

class Shops {
protected:
    ShopeNode* head;
    ShopeNode* tail;
    

public:
    Ingredients* uniqueList = new Ingredients();
    int size;
    Ingredients* budgetList = new Ingredients();

    Shops() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertFirst(Shop* val) {
        // Create a ShopeNode
        ShopeNode* temp = new ShopeNode(val);

        if (head == NULL) {
            head = temp;
            tail = temp;
            size++;
        }
        else {
            temp->next = head;
            head = temp;
            size++;
        }
    }

    void insertLast(Shop* val) {
        // Create a ShopeNode
        ShopeNode* temp = new ShopeNode(val);

        if (tail == NULL) {
            head = temp;
            tail = temp;
            size++;
        }
        else {
            tail->next = temp;
            tail = temp;
            size++;
        }
    }

    void insertAt(int pos, Shop* shop) {
        if (pos < 0 || pos > size)
            std::cout << "Invalid Index" << std::endl;
        else if (pos == 0)
            insertFirst(shop);
        else if (pos == size)
            insertLast(shop);
        else {
            ShopeNode* temp = new ShopeNode(shop);
            ShopeNode* current = head;

            for (int i = 0; i < pos - 1; i++)
                current = current->next;

            temp->next = current->next;
            current->next = temp;
            size++;
        }
    }

    void deleteFirst() {
        if (head == NULL)
            std::cout << "Empty List" << std::endl;
        else {
            ShopeNode* temp = head;
            if (size == 1) {
                delete temp;
                head = NULL;
                tail = NULL;
            }
            else {
                head = head->next;
                delete temp;
            }
            size--;
        }
    }

    void deleteLast() {
        if (head == NULL)
            std::cout << "Empty List" << std::endl;
        else {
            ShopeNode* temp = tail;
            if (size == 1) {
                delete temp;
                head = NULL;
                tail = NULL;
            }
            else {
                ShopeNode* current = head;
                for (int i = 0; i < size - 2; i++) {
                    current = current->next;
                }
                tail = current;
                tail->next = NULL;
                delete temp;
            }
            size--;
        }
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos >= size)
            std::cout << "Invalid position" << std::endl;
        else if (pos == 0)
            deleteFirst();
        else if (pos = size - 1)
            deleteLast();
        else {
            ShopeNode* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            ShopeNode* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }


    Shop* getShopAt(int pos) {
        if (pos < 0 || pos >= size) {
            std::cout << "Invalid position" << std::endl;
            return new Shop();
        } else {
            ShopeNode* current = head;
            for (int i = 0; i < pos ; i++) {
                current = current->next;
            }
            //ShopeNode* temp = current->next;
            return current->shop;
        }
    }

    void search(Shop* val) {
        ShopeNode* current = head;
        std::cout << "Positions of the ShopeNodes with elemeent " << val->shopName << " : ";

        for (int i = 0; i < size; i++) {
            if (current->shop == val)
                std::cout << i << " ";

            current = current->next;
        }
        std::cout << std::endl;
    }

    // traverse
    void print() {
        ShopeNode* current = head;

        while (current != NULL) {
            std::cout << current->shop->shopName << endl;
            //current->shop->shopIngr->printIngredients();
            current = current->next;
        }
        std::cout << std::endl;
    }

    void printAllShops() {
        ShopeNode* current = head;
        int i = 1;
        while (current != NULL) {
            std::cout << i << " " << current->shop->shopName << endl;
            current = current->next;
            i++;
        }
        std::cout << std::endl;
    }

    void getUniqueIngredientList() 
    {
        
        ShopeNode* current = head;
        while (current != NULL)
        {
            Shop* currentShop = current->shop;
            int i = 1;
            for (auto const& pair : currentShop->shopIngr->hashTable) {
                uniqueList->insertNewIngredient(new Ingredient(pair.first,pair.second->ingredientPrice,pair.second->shopName));
            }
            current = current->next;

        }
        //uniqueList->printIngredients();
    }

    void budgetListGen() 
    {
        getUniqueIngredientList();
        for (auto const& pair : uniqueList->hashTable) 
        {
            string key = pair.first;
            int price = 0;
            string shopName = "";
            //cout << key << endl;
            for (int i = 0; i < size; i++)
            {
                //cout << i << endl;
                Shop* shopAt = getShopAt(i);
                shopName = shopAt->shopName;
                //cout <<shopName << " " << shopAt->shopIngr->hashTable.size() << endl;
                //shopAt->shopIngr->printIngredients();
                int cPrice = shopAt->shopIngr->getPriceFromKeyByTraversal(key);

                if (cPrice!=-1)
                {
                    if (price==0)
                    {
                        price = cPrice;
                    }
                    else {
                        if (cPrice < price)
                        {
                            cout << cPrice << " < " << price << endl;
                            price = cPrice;
                        }
                    }
                }
            
            }




            budgetList->insertNewIngredient(new Ingredient(key, price, shopName));
        }
        //budgetList->printIngredients();

    }

    

   

};
