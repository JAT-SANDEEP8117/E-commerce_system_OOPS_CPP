#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <limits>
// #include<time>   *LIBRARY FOR RAND FUNCTION* 
using namespace std;

class Product {
public:
    string name;
    string brand;
    double price;

    Product(string name, string brand, double price) : name(name), brand(brand), price(price) {}

    virtual void display() const = 0; // Pure virtual function
    virtual vector<string> getRecommendations() const = 0; // Get product recommendations
};

class Electronics : public Product {
public:
    Electronics(string name, string brand, double price) : Product(name, brand, price) {}

    void display() const override
    {
        cout << "Electronics: " << name << " by " << brand << " for ₹" << price << endl;
    }

    vector<string> getRecommendations() const override {
        return {"Wireless EarBuds", "Phone Case"}; // Example recommendations
    }
};

class Fashion : public Product {
public:
    Fashion(string name, string brand, double price) : Product(name, brand, price) {}

    void display() const override
    {
        cout << "Fashion: " << name << " by " << brand << " for ₹" << price << endl;
    }

    vector<string> getRecommendations() const override {
        return {"Sneakers", "Hoodie"}; // Example recommendations
    }
};

class HomeAppliance : public Product {
public:
    HomeAppliance(string name, string brand, double price) : Product(name, brand, price) {}

    void display() const override
    {
        cout << "Home Appliance: " << name << " by " << brand << " for ₹" << price << endl;
    }

    vector<string> getRecommendations() const override {
        return {"Toaster", "Blender"}; // Example recommendations
    }
};

class Book : public Product {
public:
    Book(string name, string brand, double price) : Product(name, brand, price) {}

    void display() const override
    {
        cout << "Book: " << name << " by " << brand << " for ₹" << price << endl;
    }

    vector<string> getRecommendations() const override {
        return {"E-book Reader", "Book Light"}; // Example recommendations
    }
};

class Sports : public Product {
public:
    Sports(string name, string brand, double price) : Product(name, brand, price) {}

    void display() const override
    {
        cout << "Sports: " << name << " by " << brand << " for ₹" << price << endl;
    }

    vector<string> getRecommendations() const override {
        return {"Water Bottle", "Sports Bag"}; // Example recommendations
    }
};
 // ** RECOMMENDATION USING RAND FUNCTION :
    
    /vector<string> getRandomRecommendations(const vector<Product>& products) const {
        vector<string> recommendations;
        vector<int> indices;
        while (recommendations.size() < 2) {
            int index = rand() % products.size();
            if (products[index]->name != name && find(indices.begin(), indices.end(), index) == indices.end()) {
                recommendations.push_back(products[index]->name);
                indices.push_back(index);
            }
        }
        return recommendations;*/

class User {
public:
    string name;
    string email;
    string password;
    string address, phonenumber;
    vector<string> cart;
    vector<string> purchaseHistory;

    User(string name, string email, string password, string address, string phonenumber)
        : name(name), email(email), password(password), address(address), phonenumber(phonenumber) {}

    void addToCart(const string& product) {
        cart.push_back(product);
    }

    void displayCart() {
        if (cart.empty()) {
            cout << "Your cart is empty." << endl;
            return;
        }

        cout << "Items in your cart:\n";
        for (size_t i = 0; i < cart.size(); ++i) {
            cout << i + 1 << ". " << cart[i] << endl;
        }

        char confirmPurchase;
        cout << "\nWould you like to proceed with purchasing items in your cart? (y/n): ";
        cin >> confirmPurchase;

        if (confirmPurchase == 'y' || confirmPurchase == 'Y') {
            cout << "Enter the numbers of the items you'd like to purchase (separated by spaces): ";
            vector<int> itemIndices;
            int index;

            while (cin >> index) {
                if (index > 0 && index <= cart.size()) {
                    itemIndices.push_back(index - 1);
                } else {
                    cout << "Invalid item number: " << index << ". Please enter valid item numbers.\n";
                }
                if (cin.peek() == '\n') break;
            }

            if (itemIndices.empty()) {
                cout << "No valid items selected for purchase.\n";
                return;
            }

            cout << "Proceeding with the purchase...\n";
            for (int idx : itemIndices) {
                purchaseItem(cart[idx]);
            }
            displayPurchases();

            // Remove purchased items from cart
            for (int i = itemIndices.size() - 1; i >= 0; --i) {
                cart.erase(cart.begin() + itemIndices[i]);
            }

            cout << "Purchase completed successfully!\n";
        }
    }

    void purchaseItem(const string& item) {
        purchaseHistory.push_back(item);
    }

    void displayPurchases() const {
        if (purchaseHistory.empty()) {
            cout << "No purchases made yet." << endl;
        } else {
            cout << "Your purchase history:\n";
            for (const auto& item : purchaseHistory) {
                cout << "- " << item << endl;
            }
        }
    }

    void displayAccount() const {
        cout << "User Details:\n";
        cout << "Name: " << name << "\nEmail: " << email << "\nPhone Number: " << phonenumber << "\nAddress: " << address << endl;
    }
};

bool isValidPhone_number(const string& phoneNumber) {
    if (phoneNumber.length() != 10)
        return false;
    for (char c : phoneNumber) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

void registerNewUser(vector<User*>& users) {
    string name, email, address, password, phone_number;
    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your Email: ";
    cin >> email;
    regex emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!regex_match(email, emailPattern)) {
        cout << "Invalid Email Format.\n";
        return;
    }

    cout << "Enter your Password: ";
    cin >> password;
    cout << "Enter your Phone Number: ";
    cin >> phone_number;
    while (!isValidPhone_number(phone_number)) {
        cout << "Invalid phone number. Please enter a valid 10-digit phone number: ";
        cin >> phone_number;
    }
    cout << "Enter your address: ";
    cin.ignore();
    getline(cin, address);

    users.push_back(new User(name, email, password, address, phone_number));
    cout << "Registration successful!!\n";
}

User* loginUser(vector<User*>& users) {
    string email, password;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> password;

    for (auto user : users) {
        if (user->email == email && user->password == password) {
            cout << "Login successful!! Welcome, " << user->name << "!\n";
            return user;
        }
    }
    cout << "Incorrect email or password.\n";
    return nullptr;
}

void browseProducts(User* loggedInUser, const vector<Product*>& category)
{
    for (size_t i = 0; i < category.size(); ++i) {
        cout << i + 1 << ". ";
        category[i]->display();
    }

    cout << "Enter the product number to add to cart or enter 0 to go back: ";
    int productChoice;
    cin >> productChoice;

    if (productChoice > 0 && productChoice <= category.size()) {
        loggedInUser->addToCart(category[productChoice - 1]->name);
        cout << "Product added to cart successfully!!!\n";

        // *** Display recommendations after adding an item to the cart ***
        vector<string> recommendations = category[productChoice - 1]->getRecommendations();
        cout << "We recommend the following items based on your selection:\n";
        for (const string& rec : recommendations) {
            cout << "- " << rec << endl;
        }
    }
}

void mainMenu(User* loggedInUser, vector<Product*>& electronics, vector<Product*>& fashion,
              vector<Product*>& homeAppliances, vector<Product*>& books, vector<Product*>& sports) {
    while (true) {
        cout << "\n1. Browse Products\n2. View Cart\n3. View Purchase History\n4. Account Details\n5. Log Out\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nChoose a category:\n1. Electronics\n2. Fashion\n3. Home Appliances\n4. Books\n5. Sports\n";
                int categoryChoice;
                cin >> categoryChoice;
                if (categoryChoice == 1) browseProducts(loggedInUser, electronics);
                else if (categoryChoice == 2) browseProducts(loggedInUser, fashion);
                else if (categoryChoice == 3) browseProducts(loggedInUser, homeAppliances);
                else if (categoryChoice == 4) browseProducts(loggedInUser, books);
                else if (categoryChoice == 5) browseProducts(loggedInUser, sports);
                break;
            }
            case 2: loggedInUser->displayCart(); break;
            case 3: loggedInUser->displayPurchases(); break;
            case 4: loggedInUser->displayAccount(); break;
            case 5: return;
            default: cout << "Invalid choice.\n";
        }
    }
}

int main() {
    vector<User *> users;
    // Predefined users
    users.push_back(new User("Niharika", "nikky@gmail.com", "password123", "123 Main St", "1234567890"));
    users.push_back(new User("Bhavya", "bav@gmail.com", "password123", "456 Elm St", "0987654321"));
    users.push_back(new User("Madhav","m@gmail.com","p12","123street","1234567890"));
    users.push_back(new User("sandeep","s@gmail.com","p19","145street","1234565660"));


    vector<Product *> electronics = {
        new Electronics("Smartphone", "(Samsung Galaxy S23 Ultra 5G)", 79.999),
        new Electronics("Laptop", "(HP Laptop 12th Gen Intel Core i5)", 85.999),
        new Electronics("Smart TV", "(Xiaomi 108 cm (43 inches) X Series 4K LED Smart Google TV)",28.999),
        new Electronics("Headphones", "(boAt Rockerz 450 Bluetooth On Ear Headphones)", 2.099),
        new Electronics("Smartwatch", "(Samsung Galaxy Watch4 Classic Bluetooth)", 12.999)};
    vector<Product *> fashion = {
        new Fashion("T-Shirt", "(Levis black)", 429),
        new Fashion("Jeans", "(denim)", 1.299),
        new Fashion("Jacket", "(denim black jacket)", 3.999),
        new Fashion("Sneakers", "(N)ike", 8.654),
        new Fashion("Hat", "(addidas)", 1.499)};
    vector<Product *> homeAppliances = {
        new HomeAppliance("Refrigerator", "(Samsung double door)", 49.999),
        new HomeAppliance("Washing Machine ", "(Godrej front door)", 34.999),
        new HomeAppliance("Microwave", "(LG)", 12.999),
        new HomeAppliance("Blender", "(Philips)", 2.999),
        new HomeAppliance("Vacuum Cleaner", "(KENT Strom)",2.999)};
    vector<Product *> books = {
        new Book("C++ Programming", "(Author : Alexander Stepanov)",299),
        new Book("Data Structures", "(Author : Narasimha Karumanchi)", 699),
        new Book("Design Patterns", " (Author : HERRINGBONE & CHEVRON) ", 2.499),
        new Book("C Programming", " (Author : Yashavant Kanetkar) ", 1.499),
        new Book("Operating Systems", " (Author : Rohit Khurana) ", 999)};
    vector<Product *> sports = {
        new Sports("Basketball", " (Nivia Engraver/14 Panel/Soft Rubberized Moulded/Indoor) ", 499),
        new Sports("Soccer Ball", "(Puma Unisex-Adult Future 2 Soccer Ball) ", 599),
        new Sports("Tennis Racket", " (Cosco Max Power Aluminium Tennis Racquet (Blue) ", 899),
        new Sports("Yoga Mat", " (Boldfit Yoga Mat) ", 29.99),
        new Sports("Dumbbells", "(Symactive Pvc 20 Kg Adjustable Dumbbells.) ", 399)};

    while (true) {
        cout << "\nWelcome to Our E-COMMERCE PLATFORM !\n1. To register\n2. Login\n3. Exit\n";
        int choice;

        if (!(cin >> choice)) {
            // Clear the error state and ignore any remaining input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        try {
            if (choice == 1) {
                registerNewUser(users);
            } else if (choice == 2) {
                User* loggedInUser = loginUser(users);
                if (loggedInUser) {
                    mainMenu(loggedInUser, electronics, fashion, homeAppliances, books, sports);
                }
            } else if (choice == 3) {
                break;
            } else {
                throw choice;
            }
        } catch (int invalidChoice) {
            cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }
    }
    return 0;
}
