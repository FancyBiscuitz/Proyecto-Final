#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

std::string itemIdMaker(std::string base, int size);
void register_user();
std::string log_in();
void menuRegisterAndLogin();
void addProduct();
std::string getProductId(std::string category);

//------------------------------------------------------------Classes-----------------------------------------------------------------------------------

class Usuario
{
    static Usuario* instance;

    std::string names;
    std::string surnames;
    std::string userName;
    int age;
    std::string phoneNumber;
    std::string id;
    std::string password;

    Usuario()
    {
        std::ofstream info;
        info.open("users.csv"); 

    }

public:
    static Usuario* getInstance()
    {
        if (instance == NULL)
        {
            instance = new Usuario();
        }
        return instance;
    }
    //getters
    std::string getNames() {return names;}
    std::string getSurnames() {return surnames;}
    std::string getUsername() {return userName;}
    int getAge() {return age;}
    std::string getPhoneNumber() {return phoneNumber;}
    std::string getId() {return id;}
    std::string getPassword() {return password;}
    
    //setters
    void setNames(std::string _names) {names = _names;}
    void setSurnames(std::string _surnames) {surnames = _surnames;}
    void setUsername(std::string _username){userName = _username;}
    void setEdad(int _age) {age = _age;}
    void setPhoneNumber(std::string _phonenumber) {phoneNumber = _phonenumber;}
    void setId(std::string _id) {id = _id;}
    void setPassword(std::string _password) {password = _password;}

};

class Category
{
    std::string category;
    std::string description;

    public:
    
    std::string getCategory()
    {
        return category;
    }
    std::string getDescription()
    {
        return description;
    }

    // setters
    
    void setCategory(std::string _category) {category = _category;};
    void setDescription(std::string _description) {description = _description;}; 

};

class Product : public Category
{
    private:
    std::string id;
    int stock;
    std::string brand;
    int price;
    std::string definition;

    public:
    //getters
    std::string getId()
    {
        return id;
    }
    int getPrice()
    {
        return price;
    }
    std::string getDefinition()
    {
        return definition;
    }
    std::string getBrand(){
        return brand;
    }
    int getStock()
    {
        return stock;
    }

    //setters
    void setId(std::string _id)
    {
        id = _id;
    }
    void setPrecio(int _price)
    {
        price = _price;
    }
    void setDescripcion(std::string _definition)
    {
        definition = _definition;
    }
    void setStock(int _stock)
    {
        stock = _stock;
    }
    void setBrand(int _brand)
    {
        brand = _brand;
    }
};

class Administrador: public Usuario{
    public:

    void addProducts()
    {
        
    }

    void deleteProducts()
    {
        
    }

    void changePrice()
    {
        
    }

    void changeStock()
    {
   
    }
};

class Cliente: public Usuario{
    
    private:
    vector<int> shoppingCart;
    int credit;
 
    public:

    void addProductsToShoppingCart()
    {
        
    }
    
    void viewShoppingCartProducts()
    {

    }

    void deleteProducsToShoppingCart()
    {

    }

};


//------------------------------------------------------------Functions-----------------------------------------------------------------------------------

std::string itemIdMaker(std::string base, int size)
{
    srand(time(NULL));
    std::string id;
    int sas;
    std::string sup = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < size; i++)
    {
        sas = rand() % (sup.size()-1) + 1;
        id += sup[sas];
    }
    id = base + "-" + id;
    return id;
}

void register_user()
{ 
    std::ofstream regis;
    regis.open("users.csv", ios::app); // Abre el archivo
    std::string names, surnames, username, phonenumber, password;
    int age;
    if(regis.good())
    {
        regis << "\n";
        std::cout << "Names: ";
        std::getline(std::cin, names);
        std::cout << std::endl;
        std::cout << "Surnames: ";
        std::getline(std::cin, surnames);
        std::cout << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << std::endl;
        std::cout << "Phone number: ";
        std::cin >> phonenumber;
        std::cout << std::endl;
        std::cout << "Password: ";
        std::cin >> password;
        std::cout << std::endl;
        std::cout << "Age: ";
        std::cin >> age;
        regis << names << "," << surnames << "," << username << "," << age << "," << phonenumber << "," << itemIdMaker("usr", 9) << "," << password;
    }
    regis.close();
}

std::string log_in()
{
    std::vector<std::string> credentials;
    std::string usersup;
    std::string user;
    std::string pass;
    int i = 0;
    int j = 0;
    bool found = false;
    std::ifstream users;
    std::cout << "Username: ";
    std::cin >> user;
    users.open("users.csv", ios::in);
    while (users.good())
    {
        if (i == 6)
        {
            std::getline(users, usersup, '\n');
            credentials.push_back(usersup);
            if (credentials[2] == user)
            {
                found = true;
                break;
            }
            credentials = {};
            i = -1;
        }
        else
        {
            std::getline(users, usersup, ',');
            credentials.push_back(usersup);
        }
        i++;
    }
    users.close();
    if (!found)
    {
        std::cout << "User not found." << std::endl;
        return "0";
    }
    else
    {
        while (i > 3)
        {
            std::cout << "Password: ";
            std::cin >> pass;
            if (pass == credentials[6])
            {
                std::cout << "Successfully logged in! " << std::endl;
                return credentials[5];
            } 
            else
            {
                cout << "You have " << i-3 << " attempts left." << std::endl;
            }
            i--;
        }
        std::cout << "Try again later." << std::endl;
        return "0";
    }
}

void menuRegisterAndLogin()
{
    int choice;
    cout<<"--------------------------------------------¡Welcome to PepegaCoding Market!----------------------------------------------------\n";
    cout << "Please choose a option!\n[1] Login\n[2] Register\n[3] Exit" << endl;
    cin >> choice;
    switch(choice){
        case 1:
            log_in();
            break;
        case 2:
            register_user();
            break;
        case 3:
            exit(0);
    }
}

std::string getProductId(std::string category)
{
    vector<string> categories {"Abarrotes", "Desayuno", "Lacteos", "Carnes y pollos", "Frutas y verduras", "Pasteles", "Snacks", "Bebidas", "Licores", "Limpieza", "Cuidado personal"};
    vector<string> initials {"001", "002", "003", "004", "005", "006", "007", "008", "009", "010", "011"};
    int z;

    for (int i = 0; i < categories.size(); i++)
    {
        if (categories[i] == category)
        {
            z = i;
            break;
        }
    }
    return itemIdMaker(initials[z], 6);
}

void addProduct()
{
    std::ofstream products;
    products.open("products.csv", ios::app); // Abre el archivo
    std::string category, description, id, definition, brand;
    int price, stock;
    if(products.good())
    {
        products << "\n";
        std::cout << "Category: ";
        std::getline(std::cin, category);
        std::cout << std::endl;

        std::cout << "Description of the category: ";
        std::getline(std::cin, description);
        std::cout << std::endl;

        std::cout << "What product do you want to add: ";
        std::getline(std::cin, definition);
        std::cout << std::endl;

        std::cout << "Price of the new product: ";
        std::cin >> price;
        std::cout << std::endl;
        
        std::cout << "Insert product stock: ";
        std::cin >> stock;
        std::cout << std::endl;

        std::cout << "Insert the brand of the product: ";
        std::getline(std::cin, brand);
        std::cout << std::endl;

        products << category << "," << description << "," << definition << "," << price << "," << stock << "," << brand << "," << getProductId(category);
    }
    products.close();
}

void deleteProduct()
{
    
}

int main(void)
{
    addProduct();
}
