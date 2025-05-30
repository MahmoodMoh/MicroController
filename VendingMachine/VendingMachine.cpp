#include <iostream>  
#include <vector>     //for dynamic array (vector) container
#include <map>      // for key-value pair (map) container
#include <set>     // for unique element (set) container
#include <string>     // for string data type
#include <iomanip>      // for stream manipulators (e.g., setw, setprecision)
#include <limits> 

// C++ compiler did not comile € symbol, that is why $ sign is used instead
using namespace std;

namespace VendingSystem {
    class VendingComponent {
        protected:
        string name = "";

        public:
        // Default constructor
        VendingComponent() = default;
        VendingComponent(const string& n) : name(n) {} // Parameterized Constructor
        virtual ~VendingComponent() = default; // Virtual destructor
        virtual void displayInfo() const = 0; // pure virtual function to make the base class abstract

        // Encapsulation for name (Getter & Setter)
        string getName() const { return name; }
        void setName(const string& n) { name = n; }
        

    };

    // Derived Class 'Product'
    class Product : public VendingComponent {
        
        protected:
        double price = 0.0;
        int stock = 0;

        public:
        Product() = default; // Default constructor
        Product(const string& n = "", double p = 0.0, int s = 0) : VendingComponent(n), price(p), stock(s) {}

        virtual ~Product() = default;

        void displayInfo() const override {
            cout << "Product: " << name << ", Price: $" << price << fixed << setprecision(2) << "Stock: " << stock << endl;
        }
        // Encapsulation for Price and Stock ...
        double getPrice() const { return price;}
        double getStock() const { return stock;}
        void setPrice(double p) { price = p;}
        void setStock(int s) { stock = s; }

        Product operator +(const Product& other) const { // Operator overloading for adding two products
            return Product (name + "_" + other.name, (price + other.price) / 2, stock + other.stock);
        }
        friend ostream& operator<<(ostream& os, const Product& p) { // Friend function to overload << operator
            os << p.name << " ($" << fixed << setprecision(2) << p.price
               << ", " << p.stock << " in stock)";
            return os;
        }
    };

    // Subclass derived from Product
    class Snack : public Product {
        
        private: 
        string flavor;

        public: 
        // Constructor with default values
        Snack(const string&n = "", double p = 0.0, int s = 0, const string& f = "") : Product(n, p, s), flavor(f) {}

        void displayInfo() const override {     // Overriding display method
            cout << "Snack: " << name << " (" << flavor << "), Price: €" << fixed
                 << setprecision(2) << price << ", Stock: " << stock << endl; 
        }
    
        string getFlavor() const { return flavor; }        
        void setFlavor(const string& f) { flavor = f; }       
     };

    class Beverage : public Product {
        
        private: 
        string type;

        public:
        // Constructor with default values
        Beverage(const string& n = "", double p = 0.0, int s = 0, const string& t = "") : Product(n, p, s), type(t) {}
        void displayInfo() const override {
            cout << "Beverage: " << name << " (" << type << "), Price: $" << fixed << setprecision(2) << price << ", Stock: " << stock << endl;
        }
        string getType() const { return type;}
        void setType(const string& t) {type = t;}

     };

     // Helper Class 'VendingMachine'
     class VendingMachine {
        private:
        vector<Product*> inventory;     // Vector to store pointers to Product objects
        map<string, int> sales;         // Map to track sales count by product name
        set<string> outOfStock;         // Set to track out-of-stock products
        double balance = 0.0;         
        double totalEarnings = 0.0;

        public:
        VendingMachine () { // Constructor

            inventory.push_back( new Beverage ("Coke", 2.99, 15, "Soda"));
            inventory.push_back( new Beverage ("Red Bull", 3.55, 20, "Energy Drink"));
            inventory.push_back( new Beverage ("Apple Juice", 1.20, 10, "Juice"));
            inventory.push_back( new Beverage ("Water", 1.85, 15, "Still"));
            inventory.push_back( new Beverage ("Lemonade", 2.99, 12, "Soda"));
            inventory.push_back( new Beverage ("Iced Tea", 2.55, 7, "Tea"));
            inventory.push_back( new Beverage ("Monster", 2.80, 10, "Energy Drink"));

            inventory.push_back( new Snack ("Potato Chips", 2.50, 10, "Sour Cream"));
            inventory.push_back( new Snack ("Chocolate Bar", 2.20, 15, "Milk Chocolate"));
            inventory.push_back( new Snack ("Popcorn", 2.00, 7, "Butter Flavor"));
            inventory.push_back(new Snack ("Protein Bar", 3.00, 15, "Strawberry"));
            inventory.push_back( new Snack ("Nuts", 1.80, 12, "Mixed"));
            inventory.push_back( new Snack ("Cookies", 2.80, 12, "Chocolate"));
            inventory.push_back( new Snack ("Crackers", 2.30, 12, "Plain"));

        }
        ~VendingMachine() {
            for (Product*p : inventory) {
                delete p;
            }
        }

        void displayInventory() {
            int category;
        
            while(true) {
                cout << "\n *** Product Inventory *** \n";
                cout <<"0. Back to Main Menu \n\n";
                cout <<"Select Category: \n";
                cout <<"1. Beverage \n 2. Snacks \n\n Enter Choice: ";
                cin >> category;
                if (category == 0) break;
                
                switch (category) {
                    case 1: {     // Beverages Menu Header (setw = sets weidth)
                        cout <<" \n *** Beverages ***\n ";
                        cout << left ; // For the left alignement text
                        cout << setw(5) << "No." << setw(20) << "Name" << setw(15) << "Type" << setw(15) << "Price ($)" << setw(10) << "Stock" << endl;
                        cout << string (70, '_') << endl;

                        size_t index = 0;
                        for (size_t i = 0; i < inventory.size(); i++) {
                            Beverage* beverage = dynamic_cast<Beverage*> (inventory[i]);
                            if (beverage) {
                                ++index;
                                cout << setw(5) << index << setw(20) << beverage->getName() << setw(15) << beverage->getType()
                                     << setw(15) << fixed << setprecision(2) << beverage->getPrice()
                                     << setw(10) << beverage->getStock() << endl;

                            }
                        }
                        int selection;
                        cout << "\n Select a Beverage (1-" << index << ", 0 to go back): ";
                        cin >> selection;
                        if (selection > 0 && selection <= static_cast<int>(index)) {
                            Beverage* beverage = dynamic_cast<Beverage*>(inventory[selection - 1]);
                            if (beverage) {
                                cout << "Selected: " << *beverage << endl;
                            }
                        }
                        break;
                    }

                    case 2: {   // Snacks Menu Header
                        cout <<" \n --- Snacks --- \n ";
                        cout << left ; // for the left alignment text
                        cout << setw(5) << "No." << setw(20) << "Name" << setw(15) << "Flavor" << setw(15) << "Price ($)" << setw(10) << "Stock" << endl;
                        cout << string(70, '-') << endl;
                        size_t index = 0;
                        
                        for (size_t i = 0; i < inventory.size(); i++) {
                            Snack* snack = dynamic_cast<Snack*>(inventory[i]);
                            if (snack) {
                                ++index;
                                cout << setw(5) << index << setw(20) << snack->getName() << setw(15) << snack->getFlavor()
                                     << setw(15) << fixed << setprecision(2) << snack->getPrice()
                                     << setw(10) << snack->getStock() << endl;
                        }
                    }
                    int selection;
                    cout << "\nSelect a snack (1-" << index << ", 0 to go back): ";
                    cin >> selection;
                    if (selection > 0 && selection <= static_cast<int>(index)) {
                        Snack* snack = dynamic_cast<Snack*>(inventory[selection - 1]);
                        if (snack) {
                            cout << "Selected: " << *snack << endl;
                        }
                    }
                    break;
                }
                default:
                    cout << "Invalid category!\n";
                    }
                }
            }

            // Method to insert money into the machine
            void insertMoney(double amount) {                       
                if (amount > 0) {
                    balance += amount;
                    cout << "Inserted: EUR" << fixed << setprecision(2) << amount
                    << ". Current balance: $" << balance << endl;
                } else {
                    cout << "Invalid amount!\n";
                }
             }

             // Function to purchase a product
             void purchase(const string& productName) {
                for (Product* p : inventory) {
                    if (p->getName() == productName) {
                        if (p->getStock() == 0) {
                            outOfStock.insert(productName);
                            cout << productName << " is out of stock! \n";
                            return;
                        }
                        if (balance >= p->getPrice()) {
                            balance -= p->getPrice();
                            p->setStock(p->getStock() -1);
                            sales[productName] ++;
                            totalEarnings += p->getPrice();
                            cout << "Purchased " << *p << endl;
                            cout << "Remaining balance: $" << fixed << setprecision(2) << balance << endl;
                        }
                        else {
                            cout << "Insufficient balance! Insert $" << fixed << setprecision(2) << p->getPrice() << endl;
                        }
                        return;
                    }
                }
                cout << "Product not found! \n";
             }

             // Returning Money
             void returnChange(){
                if (balance > 0) {
                    cout << "Returning Change: $" << fixed << setprecision(2) << balance << endl;
                    balance = 0;
                }
             }

             // Restocking a Product
             void restock(const string& productName, int quantity) {
                for (Product* p : inventory) {
                    if (p->getName() == productName) {
                        p-> setStock(p->getStock() + quantity);
                        outOfStock.erase(productName);
                        cout << productName << " restocked with " << quantity << " units \n";
                        return;
                    }
                }
                cout << "Product not found! \n";
             }

             // Display total Earnings of the machine 
             void displayEarnings() const {
                cout << "Total Earnings: $" << fixed << setprecision(2) << totalEarnings << endl;
                cout << "Sales by product: \n";
                for (const auto& sale : sales) {
                    cout << sale.first << ": " << sale.second << " units \n";
            }
        }
    };
} // namespace VendingSystem ends here


// Main function Starts here
int main() {
    using namespace VendingSystem;

    // Create an instance of VendingMachine
    VendingMachine vm;   
    int choice;
    string productName;
    double amount;
    // Infinite loop
    while (true) {                                          
        cout << "\n ----- Vending Machine Menu -----\n";
        cout << "1. View Products\n2. Insert Money\n3. Purchase Item\n"
             << "4. Return Change\n5. Admin: Restock\n6. Admin: View Earnings\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                vm.displayInventory();   
                break;
            case 2:
                cout << "Enter amount to insert: ";
                cin >> amount;
                vm.insertMoney(amount);                     
                break;
            case 3:
                cout << "Enter product name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, productName);
                vm.purchase(productName);                   
                break;
            case 4:
                vm.returnChange();                          
                break;
            case 5: {
                cout << "Enter product name to restock: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, productName);
                int quantity;
                cout << "Enter quantity: ";
                cin >> quantity;
                vm.restock(productName, quantity);          
                break;
            }
            case 6:
                vm.displayEarnings();                       
                break;
            case 7:
                cout << "Thank you for using the vending machine!\n";
                return 0;                                   
            default:
                cout << "Invalid choice!\n";      
        }
    }
}

 
