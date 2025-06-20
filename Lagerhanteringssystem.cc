#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
private:
    string name;
    int quantity;
    double price;

public:
    // Konstruktor för att skapa en produkt
    Product(string name, int quantity, double price) {
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }

    // Funktion för att visa produktinformation
    void showProduct() {
        cout << "Product: " << name << ", Quantity: " << quantity << ", Price: " << price << " SEK\n";
    }

    // Funktion för att uppdatera mängden av produkten
    void updateQuantity(int amount) {
        quantity += amount;
    }

    // Funktion för att få produktens namn
    string getName() {
        return name;
    }

    // Funktion för att få produktens mängd
    int getQuantity() {
        return quantity;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    // Funktion för att lägga till produkt i lagret
    void addProduct(string name, int quantity, double price) {
        products.push_back(Product(name, quantity, price));
        cout << "Product added to inventory.\n";
    }

    // Funktion för att ta bort en produkt från lagret
    void removeProduct(string name) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getName() == name) {
                products.erase(it);
                cout << "Product removed from inventory.\n";
                return;
            }
        }
        cout << "Product not found in inventory.\n";
    }

    // Funktion för att uppdatera mängden av en produkt
    void updateProductQuantity(string name, int quantity) {
        for (auto& product : products) {
            if (product.getName() == name) {
                product.updateQuantity(quantity);
                cout << "Product quantity updated.\n";
                return;
            }
        }
        cout << "Product not found in inventory.\n";
    }

    // Funktion för att visa alla produkter i lagret
    void showInventory() {
        if (products.empty()) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "\nInventory:\n";
        for (auto& product : products) {
            product.showProduct();
        }
    }
};

int main() {
    Inventory inventory;
    int choice;
    string name;
    int quantity;
    double price;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Update Product Quantity\n";
        cout << "4. Show Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter product name: ";
                cin.ignore();  // För att ignorera eventuell kvarvarande newline från tidigare input
                getline(cin, name);
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter price (SEK): ";
                cin >> price;
                inventory.addProduct(name, quantity, price);
                break;

            case 2:
                cout << "Enter product name to remove: ";
                cin.ignore();
                getline(cin, name);
                inventory.removeProduct(name);
                break;

            case 3:
                cout << "Enter product name to update: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new quantity: ";
                cin >> quantity;
                inventory.updateProductQuantity(name, quantity);
                break;

            case 4:
                inventory.showInventory();
                break;

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
