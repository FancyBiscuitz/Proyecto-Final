#include "utils.h"

using namespace std;

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
        products << category << ",";
        std::cout << std::endl;

        std::cout << "Description: ";
        std::getline(std::cin, description);
        products << description << ",";
        std::cout << std::endl;

        std::cout << "Definition: ";
        std::getline(std::cin, definition);
        products << definition << ",";
        std::cout << std::endl;

        std::cout << "Price: ";
        std::cin >> price;
        products << price << ",";
        std::cout << std::endl;

        std::cout << "Stock: ";
        std::cin >> stock;
        products << stock << ",";
        std::cout << std::endl;

        std::cout << "Brand: ";
        std::getline(std::cin, brand);
        std::getline(std::cin, brand);
        products << brand << ",";
        std::cout << std::endl;

        products << getProductId(category);
    }
    products.close();
}

