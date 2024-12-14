#include <string>
#include <iostream>
using namespace std;
int const max_cart=10; //maximum number of products in a cart
int const max_shop=10; //maximum number of products in shop
using namespace std;

class Customer;
class Shopkeeper;
class cart;
class Shop;
class product;

class Person{

protected:

string First_Name;
string Last_Name;
string User_Name;
string User_Email;
string Password;
string date;
string address;
string bloodgroup;
string Gender;
string number;

public:
void setfirstname(string s){First_Name=s;}
void setlastname(string s){Last_Name=s;}
void setusername(string s){User_Name=s;}
void setmail(string s){User_Email=s;}
void setpassword(string s){Password=s;}
void setdate(string s){date=s;}
void setaddress(string s){address=s;}
void setbloodgroup(string s){bloodgroup=s;}
void setgender(string s){Gender=s;}
void contactno(string s){number = s;}

virtual void del_data() = 0; 




};

class product{

    int productid;
    string Name;
    int price;
    string company;
    string color;
    int quantity;
    string size;
    string description;
    string category;
    string Company;
    int bquan;

public:

product(){}

void updateproduct(){

while (true){
    cout<<"Enter 1 to Edit product Name"<<endl;
    cout<<"Enter 2 to Edit product Price"<<endl;
    cout<<"Enter 3 to Edit product Company"<<endl;
    cout<<"Enter 4 to Edit product Color"<<endl;
    cout<<"Enter 5 to Edit product Quantity"<<endl;
    cout<<"Enter 6 to Edit product Size"<<endl;
    cout<<"Enter 7 to Edit product Description"<<endl;
    cout<<"Enter 0 to Exit"<<endl;
    int cho;
    cout<<"Enter your choice: "; cin>>cho;

    switch(cho){
    case 1:{
    cout<<"Enter new name for the product: "; string n; cin>>n;
    this->Name = n; break;}
    case 2:{
    cout<<"Enter new price for the product: "; int pr; cin>>pr;
    this->price = pr; break;}

    case 3:{
    cout<<"Enter new Company: "; string cmp; cin>>cmp;
    this->company = cmp; break; }

    case 4:{
    cout<<"Enter new Color: "; string color1; cin>>color1; 
    this->color = color1; break;}

    case 5:{
    cout <<"Enter new quantity: "; int q; cin>>q;
    this->quantity = q; break;}


    case 6:{
    cout<<"Enter new size for the product: "; int si; cin>>si;
    this->size = si; break;}

    case 7:{
    cout<<"Enter Description: "; string desc; cin>>desc;
    this->description = desc; break;}
    }

    if(cho == 0) {
        cout<<"Exiting"<<endl;
        return;
    }
}
}
void upload(string);
void edit_product_detail(); 

void setProductId(int ID) { this->productid = ID; }
    void setPrice(int P) { this->price = P; }
    void setQuantity(int Q) { this->quantity = Q; }
    void setCompany(string Com) { this->company = Com; }
    void setName(string N) { this->Name = N; }
    void setSize(string S) { this->size = S; }
    void setDescription(string D) { this->description = D; }
    void setCatgory(string Cat) { this->category = Cat; }
    void setColor(string Color) { this->color = Color; }
    //void setSalesTax() { this->salesTax = price * 0.02; }
    void setbquan(int i){bquan = i; }
    int getbquan(){return bquan;}
    //int getSalesTax() { return salesTax; }
    int getproductid(){return productid; }
    int getPrice() { return price; }
    int getQuantity() { return quantity; }
    //int getProductId() { return productId; }
    string getName() { return Name; }
    string getCompany() { return company; }
    string getColor() { return color; }
    string getSize() { return size; }
    string getDescription() { return description; }
    string getCategory() { return category; }

    void display_product();

    int operator+(product& p){ return p.price + this->price;}


};

class cart{

protected:
product p[max_cart];
int count;

public:
cart(){count=0;}
void item(int pid, int quan, string cat, string store);
void cart_show();

int total_bill();
void update();
void empty();
void checkout();



};



class Customer: public Person{

protected:
int C_id;
int items_bought;
cart c;


public:

Customer(){items_bought=0;}
void show();
void purchase();
void addtocart(int pid, int quan, string cat, string store);
void getcid();
void getemail();
void setmail(string);
void save();
void display();
void del_data();
void display_shop_products_to_customer(string Shopname);
void setcid(int cid){this->C_id = cid;}



};




class Shop{

    private:
    string Shopname;
    product p[max_shop];
    int count;
    string type;

    public:

    Shop(){count = 0;}

    string getshopname(){return Shopname;}

    void setshopname(string name){
        this -> Shopname = name;
    }

    void display_shop_products();
    void display_shop();
    void add_product();
    void save();
    void display_shop_products_to_customer();
    //void updateproduct(int , string);

};

class Shopkeeper: public Person{

string Business_category;
string shopname;
Shop shp;

protected:
int S_id;

public:

void setshopname(string);
void save();
void display();
void addnew_item();
void delete_product();
void save_shop();
void del_data();
void setsid(int sid){this->S_id=sid;}



};


class Administrator:public Person{

private:

    Shopkeeper sh;
    Customer cs;

public:
    void customersignin();

    void addshopkeeper();

    void shopkeepersignin();

    void editshopkeeper(int);
    void showallshopkeepers();

    void showallcustomers();
    void editcustomers(int);

    void editproduct(string); //string shopname

    void deleteproduct(string);

    void del_data(); //email
    


};

int readshno();
void writeshno(int);
int readcno();
void writecno(int);
int getprdid();
void writeprdid(int);