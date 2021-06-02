#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

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

    void register_user()
    {
        
        ofstream archivo;
        archivo.open("users.csv", ios::out); // Abre el archivo

        if(archivo.fail()){
            cout << "No se pudo abrir el archivo";
            exit(1);
        }
    }
    /*
    bool login(){
        if ()
    }*/
};

class Producto
{
    private:
    std::string ID;
    int Precio;
    std::string Descripcion;
    std::string Proveedor;
    public:
    //getters
    std::string getID()
    {
        return ID;
    }
    int getPrecio()
    {
        return Precio;
    }
    std::string getDescripcion()
    {
        return Descripcion;
    }
    std::string getProveedor()
    {
        return Proveedor;
    }
    //setters
    void getID(std::string id)
    {
        ID = id;
    }
    void getPrecio(int precio)
    {
        Precio = precio;
    }
    void getDescripcion(std::string descripcion)
    {
        Descripcion = descripcion;
    }
    void getProveedor(std::string proveedor)
    {
        Proveedor = proveedor;
    }
};

class Administrador: public Usuario{
    public:

    void addProducts(){
        
    }

    void deleteProducts(){
        
    }

    void changePrice(){
        
    }

    void changeStock(){
   
    }

};

class Cliente: public Usuario{
    
    private:
    vector<int> shoppingCart;
    int credit;
 
    public:

    void addProductsToShoppingCart(){
        
    }
    
    void viewShoppingCartProducts(){

    }

    void deleteProducsToShoppingCart(){

    }

};

std::string itemIdMaker(std::string base)
{
    std::string id;
    int sas;
    std::string sup = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 9; i++)
    {
        sas = rand() % (sup.size()-1) + 1;
        id += sup[sas];
    }
    id = base + "-" + id;
    return id;
}

int main(void)
{
    std::ofstream ids;
    std::ofstream test;
    /*
    ids.open("user_ids.csv");
    for (int i = 0; i < 500; i++)
    {
        ids << itemIdMaker("usr") << "\n";
    }
    ids.close();
    */
    test.open("users.csv");
    test.close();
}
