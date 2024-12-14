#include "header.h"
#include <fstream>
#include <sstream>





//Customer class:

void Customer::save(){
    ofstream outfile;

    outfile.open("waiting.txt", ios_base::app);

    outfile << User_Email <<endl;
    outfile << First_Name <<endl;
    outfile <<  Last_Name <<endl;
    outfile <<  Password    <<endl;
    outfile <<  date   <<endl;
    outfile <<  address <<endl;
    outfile << bloodgroup <<endl;
    outfile << Gender <<endl;
    outfile << number <<endl;



    cout<<"Your information is being processed"<<endl; 
    cout<<"Your account will be approved by the administrator"<<endl;
}

void Customer::setmail(string s){
    User_Email = s;
}



void Customer::display(){

    //system("clear");
    cout<<"Customer Account loged in"<<endl<<endl;
    cout<<"Email: "<<User_Email<<endl;
    cout<<"First name: "<<First_Name<<endl;
    cout<<"Last name: "<<Last_Name<<endl;
    cout<<"Password: "<<Password<<endl;

    ifstream ifs("Shop.txt");
    string read;

    cout<<endl<<"These are the available shops on our Site:"<<endl<<endl; 
    int no =1;
    while(!ifs.eof()){ 
        getline(ifs, read);

        if(read != ""){
        cout<<no<<" "<<read<<endl;
        no++;}
    }
    ifs.close();
    cout<<"Enter number of shop you want to go to:"; int cho; cin>>cho;
    
    ifstream ifs1("Shop.txt");


    for(int i=0; i<cho; i++)
        getline(ifs1, read);

    string file = read+".txt";

    ifs.close();

    fstream ifs2(file);

    cout<<read<<endl;
    display_shop_products_to_customer(read);
    
   
}



//Shopkeeper funciton:

void Shopkeeper::setshopname(string s){
    shopname = s;
}



void Shopkeeper::save(){
    ofstream outfile;

    outfile.open("waitingshopkeeper.txt", ios_base::app); 
    outfile << User_Email <<endl;
    outfile << First_Name <<endl;
    outfile <<  Last_Name <<endl;
    outfile <<  Password    <<endl;
    outfile <<  date   <<endl;    
    outfile << shopname <<endl;
    outfile << address <<endl;
    outfile << bloodgroup <<endl;
    outfile << Gender <<endl;
    outfile << number <<endl;
    ofstream ofs("Shop.txt", ios_base::app);
    ofs <<shopname<<endl;



    cout<<"Your information is being processed"<<endl; 
    cout<<"Your account will be approved by the administrator"<<endl;

}


void Shopkeeper::display(){

    //system("clear");
    cout<<"Shopkeeper Account loged in"<<endl<<endl;
    cout<<"Email: "<<User_Email<<endl;
    cout<<"First name: "<<First_Name<<endl;
    cout<<"Last name: "<<Last_Name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Blood Group: "<<bloodgroup<<endl;
    cout<<"Gender: "<<Gender<<endl;
    cout<<"Number: "<<number<<endl;




    cout<<endl<<"Your Shop name is : "<<shopname<<endl<<endl;


    cout<<endl<<endl<<"Press 1 to go to your shop"<<endl;
    int opt; cin>>opt;

    if(opt == 1){
        shp.setshopname(shopname);

        shp.display_shop();
    }
}




void Shopkeeper::addnew_item(){
    
    cout<<endl<<"Add new item to your store:"<<endl<<endl;



}

void Administrator::customersignin(){

        cout<<endl<<"Following is the account that is in waiting list and need approval of Administrator: "<<endl;


        fstream f;
        fstream temp("temp.txt",ios::out);
        f.open("waiting.txt", ios::in);

        string read, read2, read3, read4,read5, read6;

        getline(f, read);
        getline(f,read2);
        getline(f,read3);
        getline(f,read4);
        getline(f, read5);

        cout<<"Email Adderss"<<read<<endl;
        cout<<"First Name: "<<read2<<endl;
        cout<<"Last Name: "<<read3<<endl;
        cout<<"Password: "<<read4<<endl;
        cout<<"Date: "<<read5<<endl;
        cout<<endl<<endl;
        User_Email =read;
        First_Name =read2;
        Last_Name = read3;
        Password = read4;
        date =read5;
        string shopname = read6;


       // temp<<read<<endl;

    string line;

    while (getline(f, line))
    {
      if (line != read && line !=read2 && line != read3 && line != read4 && line != read5)
        temp << line << endl;
    }


   



       

        cout<<"Email: "; 

        cout<<"press 1 to change email address: "<<endl;
        cout<<"Press 0 to confirm account:" <<endl;
        int choice;
        cin>>choice;


        switch(choice){


            case 0:{
            fstream add;
            add.open("created_account_ch.txt", ios::app);
            add<<readcno()+1<<endl;
            writecno(readcno()+1);
            add << User_Email <<endl;
            add << First_Name <<endl;
            add <<  Last_Name <<endl;
            add <<  Password    <<endl;
            add <<  date   <<endl; 
            add <<  address<<endl;
            add << bloodgroup <<endl;
            add << Gender <<endl;
            add << number <<endl;

            add.close();
            cout<<"Account has been created"<<endl;
            cout<<User_Email<<endl;
  
            f.close();
            temp.close();
            remove("waiting.txt");
            rename("temp.txt", "waiting.txt");
            cout<<endl<<"Waiting list has been updated"<<endl;
            break;}


            case 1:
            string e;
                cout<<"Enter new email address: "; cin>>e;
               User_Email = e;
                cout<<"Email updated successfully"<<endl;
            break;

          

        }
}


void Administrator::shopkeepersignin(){

        cout<<endl<<"Following is the account that is in waiting list and need approval of Administrator: "<<endl;

        string id;
        fstream f;
        fstream temp("temp.txt",ios::out);
        f.open("waitingshopkeeper.txt", ios::in);

        string read, read2, read3, read4,read5, read6, read7, read8, read9, read10;

        getline(f, read);
        getline(f,read2);
        getline(f,read3);
        getline(f,read4);
        getline(f, read5);
        getline(f, read6);   //reads indicate fields in waiting list //read 6 shopname
        getline(f,read7);
        getline(f,read8);
        getline(f,read9);
        getline(f,read10);
        cout<<"Email Adderss"<<read<<endl;
        cout<<"First Name: "<<read2<<endl;
        cout<<"Last Name: "<<read3<<endl;
        cout<<"Password: "<<read4<<endl;
        cout<<"Date: "<<read5<<endl;
        cout<<"Shop Name: "<<read6<<endl;
        cout<<"Address: "<<read7<<endl;
        cout<<"Blood Group: "<<read8<<endl;
        cout<<"Gender: "<<read9<<endl;
        cout<<"Number: "<<read10<<endl;
        cout<<endl<<endl;

        id = readcno()+1;
        writecno(readcno()+1);

        User_Email =read;
        First_Name =read2;
        Last_Name = read3;
        Password = read4;
        date =read5;
        string shopname = read6;
        address = read7;
        bloodgroup = read8;
        Gender = read9;
        number = read10;



       // temp<<read<<endl;

    string line;

    while (getline(f, line))
    {
      if (line != read && line !=read2 && line != read3 && line != read4 && line != read5 && line != read6 && line != read7 && line != read8 && line != read9 && line != read10)
        temp << line << endl;
    }


   



    while(true){
        cout<<"press 1 to change email address"<<endl;
        cout<<"press 2 to change First Name"<<endl;
        cout<<"press 3 to change Last Name"<<endl;
        cout<<"press 4 to change Shopname Name"<<endl;

        cout<<"Press 0 to confirm account:" <<endl;
        int choice;
        cin>>choice;


        switch(choice){


            case 0:{
            fstream add;
            add.open("created_account_sh.txt", ios::app);

          // int serial_number = readsno() + 1;
          // writesrno(serial_number);
          // add<<serial_number;
            add << id<<endl;
            add << User_Email <<endl;
            add << First_Name <<endl;
            add <<  Last_Name <<endl;
            add <<  Password    <<endl;
            add <<  date   <<endl; 
            add << shopname <<endl;
            add << address <<endl;
            add << bloodgroup <<endl;
            add << Gender <<endl;
            add << number <<endl;

            add.close();
            cout<<"Account has been created"<<endl;
            cout<<User_Email<<endl;
  
            f.close();
            temp.close();
            remove("waitingshopkeeper.txt");
            rename("temp.txt", "waitingshopkeeper.txt");
            cout<<endl<<"Waiting list has been updated"<<endl;
            break;}


            case 1:{
            string e;
                cout<<"Enter new email address: "; cin>>e;
               User_Email = e;
                cout<<"Email updated successfully"<<endl;
            break;}
            case 2:{
                string e;
                cout<<"Enter new First Name: "; cin>>e;
                First_Name = e;
                cout<<"First Name updated successfully"<<endl;
                break; 
            }

            case 3:{
                string e;
                cout<<"Enter new Last Name: "; cin>>e;
               User_Email = e;
                cout<<"Last Name updated successfully"<<endl;
                break;
            }

            case 4:{
                string e;
                cout<<"Enter new Shop Name address: "; cin>>e;
                User_Email = e;
                cout<<"Shop Name updated successfully"<<endl;
                break;
            }
            break;
        }

        }
}






//product class methods
void product::display_product(){
    cout<<endl;
    cout<<"Product ID: " << productid <<endl;
    cout << "Name :" <<Name<<endl;
    cout << "Price: "<<price<<endl;
    cout <<"Company: " <<company<<endl;
    cout<<"Color: "<< color<<endl;
    cout<<"Quantity: "<<quantity<<endl;
    cout<<"Size: "<<size<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<"Category: "<<category<<endl;
}

void product::upload(string filename){

    fstream f(filename);
    f << productid <<endl;
    f <<Name<<endl;
    f <<price<<endl;
    f <<Company<<endl;
    f <<color<<endl;
    f <<quantity<<endl;
    f <<size<<endl;
    f <<description<<endl;
    f <<category<<endl;

}


//Shop

void Shop::display_shop(){
    cout<<Shopname<<endl<<endl;

    cout<<"Press 0 to add new product to your shop"<<endl;
    cout<<"Press 1 to display shop products"<<endl;
    int opt; cin>>opt;

    switch(opt){
        case 0:
            add_product();
        case 1:
            display_shop_products();


    }
}


 void Shop::add_product(){
       
     
     cout<<endl<<"*************Shop opened**********"<<endl;
     
        


       if(count <= 10){
        string temp; int t;
        cout<<"Enter product name: "; cin>>temp;
        p[count].setName(temp);
        cout<<"Enter price of the product: "; cin>>t;
        p[count].setPrice(t);
        cout<<"Enter Company: "; cin>>temp;
        p[count].setCompany(temp);
        cout<<"Enter Quantity: "; cin>>t;
        p[count].setQuantity(t);

        cout<<"In how many sizes is the product available in? :"<<endl;
        cout<<"1. Small"<<endl;
        cout<<"2. Small_Medium"<<endl;
        cout<<"3. Small_Medium_Large"<<endl;
        int opt2; cin>>opt2;

        switch(opt2){
            case 1:
                p[count].setSize("Small");
                break;
            case 2:
                p[count].setSize("Small_Medium");
                break;
            case 3:
                p[count].setSize("Small_Medium_Large");
        }
        

        cout<<"Select Product Category: "<<endl;
        cout<<"1. Sports"<<endl;
        cout<<"2. Garments"<<endl;
        cout<<"3. Eatables"<<endl;
        cout<<"4. Medicies"<<endl;
        cout<<"5. Fashion"<<endl;
        cin>>opt2;
    int category_number;
        switch(opt2){
            case 1:
                p[count].setCatgory("Sports");
                category_number = 1000;
                break;
            case 2:
                p[count].setCatgory("Garments");
                category_number = 2000;
                break;
            case 3:
                p[count].setCatgory("Eatables");
                category_number = 3000;
                break;
            case 4:
                p[count].setCatgory("Medicies");
                category_number = 4000;
                break;
            case 5:
                category_number = 5000;
                p[count].setCatgory("Fashion");
                break;
        }

        p[count].setProductId(category_number+getprdid()+1);
        writeprdid(getprdid()+1);



        string color; cout<<"Enter the color of product: "; cin>>color;
        p[count].setColor(color);
       // cout<<"Enter Size "
       cout<<"Enter Description about the product: "; cin>>temp;
       p[count].setDescription(temp);
       //color and categrory
       count++;
       
       cout<<"Press 0 to save add the product in your store: "; int opt; cin>>opt;
       save();
       
       }
       else {
           cout<<endl<<"Maximum Limit for products on your store has been reached"<<endl<<endl;
       }
}


void Shop::display_shop_products(){


    //read items from file

        string filename = Shopname + ".txt";
        ifstream f(filename, ios::in);
        string temp;
        //getline(f, temp);
        cout<<"File read successfully: "<<filename<<endl;
        //cout<<temp<<endl;


       



int i =0;
   while(!f.eof()){
       getline(f,temp);

       if(temp != ""){

          // cout<<"I am entring it "<<i+1<<" times"<<endl;
       //count = stoi(temp);
       count = i+1;
 
  
        getline(f,temp);
        p[i].setName(temp);
        getline(f,temp);
        p[i].setPrice(stoi(temp));
        getline(f, temp);
        p[i].setCompany(temp);
        getline(f, temp);
        int l = stoi(temp);
        p[i].setQuantity(l);
        getline(f,temp);
        p[i].setDescription(temp);
        getline(f,temp);
        p[i].setColor(temp);
        getline(f,temp);
        p[i].setSize(temp);
        getline(f,temp);
        p[i].setCompany(temp);
        i++;
        }}

        cout<<"Total items on your store are: "<<count<<endl<<endl;

    for(int i=0 ;i<count; i++){
        cout<<"item no: "<<i+1<<endl;
        p[i].display_product();
        cout<<endl;
    }

        cout<<endl<<endl<<endl<<"========================="<<endl;
        cout<<"Press 1 to add product: "<<endl;
        cout<<"Press 2 to Update product detailss"<<endl;
        cout<<"Press 0 to exit"<<endl;
        int k;
        cout<<"Enter option: "; cin>>k;

        if(k==1){
            add_product();
        }

        if(k==2){
            cout<<"Enter the product number you want to change: "; int pno1; cin>>pno1; 
            p[pno1-1].updateproduct();

            if(pno1 > count || pno1 <0){
                cout<<"Invalid product number"<<endl;
            }

            for(int i=0; i<count; i++){
                fstream f("temp.txt", ios::app);
                f<<i+1<<endl;

               
                f<< p[i].getName()<<endl;
       
                f<<p[i].getPrice()<<endl;
        
                f<<p[i].getCompany()<<endl;
     
                f<<p[i].getQuantity()<<endl;
      
                f<<p[i].getDescription()<<endl;
       
                f<<p[i].getColor()<<endl;
     
                f<<p[i].getSize()<<endl;
      
                f<<p[i].getCompany()<<endl;

            }

             const char* rename_file = filename.c_str();
            remove(rename_file);

            rename("temp.txt", rename_file);
        }

          
    

        if(k==0){
            cout<<"Exiting"<<endl;
            return;
        }


    

    
}

void Shop::save(){
    string filename = Shopname + ".txt";
    fstream f(filename, ios::app);
   // cout<<"File of name: "<<filename<<" has been created: "<<endl;
   //f <<Shopname<<endl;
    
    for(int i=0; i<count+1;i++){
  //  f<< p[i].getproductid()<<endl;
    f<<count<<endl;
    count = count-1;
    f<< p[count].getName()<<endl;
    f<< p[count].getPrice()<<endl;
    f<< p[count].getCompany()<<endl;  
    f<< p[count].getQuantity()<<endl;
    f<< p[count].getDescription()<<endl;

    f<< p[i].getColor()<<endl;
    f<< p[i].getSize()<<endl;

  //  f<< p[i].getCategory()<<endl;
    f<< p[i].getCompany()<<endl;
    f.close();
}}

void cart::item(int pid, int quan, string cat, string store){
    count++;
    //p[count];
    string shname = store + ".txt";
fstream f(shname, ios::in);
string temp;
while(!f.eof()){
       getline(f,temp);

       if(temp != ""){
       int no = stoi(temp);

       if(pid == no){
        getline(f,temp);
        p[count-1].setName(temp);
        getline(f,temp);
        p[count-1].setPrice(stoi(temp));
        cout<<"PRICE: "<<temp<<endl;
        getline(f, temp);
        p[count-1].setCompany(temp);
        getline(f, temp);
        p[count-1].setQuantity(stoi(temp));
        getline(f,temp);
        p[count-1].setDescription(temp);
        getline(f,temp);
        p[count-1].setColor(temp);
        getline(f,temp);
        p[count-1].setSize(temp);
        getline(f,temp);
        p[count-1].setCompany(temp);
        p[count-1].setbquan(quan);
        }
        else{
        getline(f,temp);
        getline(f,temp);
        getline(f,temp);
        getline(f,temp);
        getline(f,temp);
        getline(f,temp);
        getline(f,temp);
        getline(f,temp);}

    }

cout<<"Item added to cart"<<endl;
}
}

void cart::cart_show(){

    cout<<"Products in cart: "<<count<<endl<<endl;

    for(int i = 0; i <count; i++){
    cout<<"Product no: "<<i+1<<endl;
    p[i].display_product();   
    cout<<endl; 
    }

    cout<<"Press 1 to proceed to checkout"; int j; cin>>j;
    if(j==1)
        {
            checkout();
        }

}

void Customer::addtocart(int pid, int quan, string cat, string store){
   c.item(pid, quan, cat, store);
   cout<<"product added to cart"<<endl;
}

void Customer::show(){
    c.cart_show();
}


//cart bill
int cart::total_bill(){
    int total=0;
    for(int i=0; i<count; i++)
    total += p[i].getPrice() * p[i].getbquan();

    return total;
    
}

void cart::checkout(){ 
    cout<<endl<<"Your Total bill is: "; cout<<total_bill();
    cout<<"Press 1 to checkout: "; int i; cin>>i;
    if(i==1){
        cout<<"Your have paid the bill"<<endl;
    }
}


//Administration
void Administrator::showallshopkeepers(){

    cout<<"Record of all shopkeeps is as follows:"<<endl<<endl;
    fstream f("created_account_sh.txt", ios::in);
    string s;
    int num=1;
    while (!f.eof()){
        cout<<"Shopkeeper No: "<<num<<endl;
        cout<<"---------------"<<endl;
        getline(f,s);
        cout<<"Shopkeer ID: "<<s<<endl;
        getline(f,s);
        cout<<"Email of shopkeeper: "<<s<<endl;
        getline(f,s);

        cout<<"First Name: "<<s<<endl;
        getline(f,s);
        cout<<"Last Name: "<<s<<endl;
        getline(f,s);
        getline(f,s);
        cout<<"Date of Accout creation"<<s<<endl;
        getline(f,s);
        cout<<"Shop Name: "<<s<<endl;
        
        getline(f,s);
        cout<<"Address: "<<s<<endl;
        getline(f,s);
        cout<<"Blood Group: "<<s<<endl;
        getline(f,s);
        cout<<"Gender: "<<s<<endl;
        getline(f,s);
        cout<<"Number: "<<s<<endl;
        cout<<endl;
        num++;
    }
    
}


void Administrator::showallcustomers(){

    cout<<"Record of all Customers is as follows:"<<endl<<endl;
    fstream f("created_account_ch.txt", ios::in);
    string s;
    int num=1;
    while (!f.eof()){
        cout<<"Customer No: "<<num<<endl;
        cout<<"---------------"<<endl;
        getline(f,s);
        cout<<"Customer ID:"<<s<<endl;
        getline(f,s);
        cout<<"Email of Customer: "<<s<<endl;
        getline(f,s);

        cout<<"First Name: "<<s<<endl;
        getline(f,s);
        cout<<"Last Name: "<<s<<endl;
        getline(f,s);
        getline(f,s);
        cout<<"Date of Accout creation"<<s<<endl;
        getline(f,s);
        cout<<"Address: "<<s<<endl;
        getline(f,s);
        cout<<"Blood Group: "<<s<<endl;
        getline(f,s);
        cout<<"Gender: "<<s<<endl;
        getline(f,s);
        cout<<"Number: "<<s<<endl;
        cout<<endl;
        

       // getline(f,s);
       // cout<<"Shop Name: "<<s<<endl;
       // cout<<endl;
        num++;
    }
    
}




void Administrator::editshopkeeper(int n){
   fstream f;

        cout<<"This function is called value of n is: "<<n<<endl;
        fstream temp("temp.txt",ios::out);
        f.open("created_account_sh.txt", ios::in);

        string read, read2, read3, read4,read5, read6, read7, read8, read9, read10;

        for(int i=0;i<n; i++){
        getline(f, read);
        getline(f,read2);
        getline(f,read3);
        getline(f,read4);
        getline(f, read5);
        getline(f, read6);
        getline(f, read7);
        getline(f, read8);
        getline(f, read9);
        getline(f, read10);

        }

        cout<<"Email Adderss"<<read<<endl;
        cout<<"First Name: "<<read2<<endl;
        cout<<"Last Name: "<<read3<<endl;
        cout<<"Password: "<<read4<<endl;
        cout<<"Date: "<<read5<<endl;
        cout<<"Address: "<<read6<<endl;
        cout<<"Blood Group: "<<read7<<endl;
        cout<<"Gender: "<<read8<<endl;
        cout<<"Number: "<<read9<<endl;





        cout<<endl<<endl;
        User_Email =read;
        First_Name =read2;
        Last_Name = read3;
        Password = read4;
        date =read5;
        string shopname = read6;
        address = read7;
        bloodgroup =read8;
        Gender = read9;
        number = read10;
        

       // temp<<read<<endl;

    string line;

    while (getline(f, line))
    {
      if (line != read && line !=read2 && line != read3 && line != read4 && line != read5 && line != read6 && line != read7 && line!= read8 && line != read9 && line != read10)
        temp << line << endl;
    }


       
        cout<<"Enter 1 to change email address: "<<endl;
        cout<<"Enter 2 to change First Name: "<<endl;
        cout<<"Enter 3 to change Last Name: "<<endl;
        cout<<"Enter 4 to change Shop Name: "<<endl;
        cout<<"Press 0 to confirm account:" <<endl;
        int choice;
        cin>>choice;

string e;
        switch(choice){

            case 1:{
            string e;
                cout<<"Enter new email address: "; cin>>e;
               User_Email = e;
                cout<<"Email updated successfully"<<endl;
                break;}
            case 2:
               { cout<<"Enter First Name: "; cin>>e;
                First_Name =e;
                cout<<"First Name has been updated successfully"<<endl;
                break;}

            case 3:
              {  cout<<"Enter Last Name: "; cin>>e;
                Last_Name =e;
                cout<<"Last Name has been updated successfully"<<endl;
                break;}

            case 4:{
                cout<<"Enter New Shop Name: "; cin>>e;
                shopname = e;
                break;}

            
            
        


            case 0:{
            fstream add;
            add.open("temp.txt", ios::app);
           
            add << User_Email <<endl;
            add << First_Name <<endl;
            add <<  Last_Name <<endl;
            add <<  Password    <<endl;
            add <<  date   <<endl; 
            add<< shopname <<endl;
            add.close();
            cout<<"Account has been Edited"<<endl;
            cout<<User_Email<<endl;
  
            f.close();
            temp.close();
            remove("created_account_sh.txt");
            rename("temp.txt","created_account_sh.txt");
            cout<<endl<<"Changes have been made in file system"<<endl;
            break;}

        }


//to save information this step is must


fstream add;
            add.open("temp.txt", ios::app);
           
            add << User_Email <<endl;
            add << First_Name <<endl;
            add <<  Last_Name <<endl;
            add <<  Password    <<endl;
            add <<  date   <<endl; 
            add<< shopname <<endl;
            add<<address <<endl;
            add << bloodgroup <<endl;
            add << Gender <<endl;
            add << number <<endl;
            add.close();
            cout<<"Account has been Edited"<<endl;
            cout<<User_Email<<endl;
  
            f.close();
            temp.close();
            remove("created_account_sh.txt");
            rename("temp.txt","created_account_sh.txt");
            cout<<endl<<"Changes have been made in file system"<<endl;



}





void Administrator::editcustomers(int n){
   fstream f;

        cout<<"This function is called value of n is: "<<n<<endl;
        fstream temp("temp.txt",ios::out);
        f.open("created_account_ch.txt", ios::in);

        string read, read2, read3, read4,read5, read6, read7, read8, read9;

        for(int i=0;i<n; i++){
        getline(f, read);
        getline(f,read2);
        getline(f,read3);
        getline(f,read4);
        getline(f, read5);
        getline(f, read6);
        getline(f, read7);
        getline(f, read8);
        getline(f, read9);
        }

        cout<<"Email Adderss"<<read<<endl;
        cout<<"First Name: "<<read2<<endl;
        cout<<"Last Name: "<<read3<<endl;
        cout<<"Password: "<<read4<<endl;
        cout<<"Date: "<<read5<<endl;
        cout<<"Address: "<<read6<<endl;
        cout<<"Blood Group: "<<read7<<endl;
        cout<<"Gender: "<<read8<<endl;
        cout<<"Number: "<<read9<<endl;
        cout<<endl<<endl;
        User_Email =read;
        First_Name =read2;
        Last_Name = read3;
        Password = read4;
        date =read5;
        address = read6;
        bloodgroup = read7;
        Gender = read8;
        number = read9;
        

       // temp<<read<<endl;

    string line;

    while (getline(f, line))
    {
      if (line != read && line !=read2 && line != read3 && line != read4 && line != read5 && line != read6 && line!= read7 && line != read8 && line != read9)
        temp << line << endl;
    }


       
        cout<<"Enter 1 to change email address: "<<endl;
        cout<<"Enter 2 to change First Name: "<<endl;
        cout<<"Enter 3 to change Last Name: "<<endl;
        cout<<"Press 0 to confirm account:" <<endl;
        int choice;
        cin>>choice;

string e;
        switch(choice){

            case 1:{
            string e;
                cout<<"Enter new email address: "; cin>>e;
               User_Email = e;
                cout<<"Email updated successfully"<<endl;
                break;}
            case 2:
               { cout<<"Enter First Name: "; cin>>e;
                First_Name =e;
                cout<<"First Name has been updated successfully"<<endl;
                break;}

            case 3:
              {  cout<<"Enter Last Name: "; cin>>e;
                Last_Name =e;
                cout<<"Last Name has been updated successfully"<<endl;
                break;}
            
        


            case 0:{
            fstream add;
            add.open("temp.txt", ios::app);
           
            add << User_Email <<endl;
            add << First_Name <<endl;
            add <<  Last_Name <<endl;
            add <<  Password    <<endl;
            add <<  date   <<endl; 
            add.close();
            cout<<"Account has been Edited"<<endl;
            cout<<User_Email<<endl;
  
            f.close();
            temp.close();
            remove("created_account_ch.txt");
            rename("temp.txt","created_account_ch.txt");
            cout<<endl<<"Changes have been made in file system"<<endl;
            break;}

        }


//to save information this step is must


fstream add;
            add.open("temp.txt", ios::app);
           
            add << User_Email <<endl;
            add << First_Name <<endl;
            add <<  Last_Name <<endl;
            add <<  Password    <<endl;
            add <<  date   <<endl; 
            add.close();
            cout<<"Account has been Edited"<<endl;
            cout<<User_Email<<endl;
  
            f.close();
            temp.close();
            remove("created_account_sh.txt");
            rename("temp.txt","created_account_sh.txt");
            cout<<endl<<"Changes have been made in file system"<<endl;



}


void Administrator::editproduct(string shopname){
    string filename= shopname + ".txt";

    product p[5];
    //read items from file

    ifstream f(filename, ios::in);
    string temp;
        //getline(f, temp);
        cout<<"File read successfully: "<<filename<<endl;
    int count;
    int i =0;
    while(!f.eof()){
       getline(f,temp);

       if(temp != ""){

       count = i+1;
 
  
        getline(f,temp);
        p[i].setName(temp);
        getline(f,temp);
        p[i].setPrice(stoi(temp));
        getline(f, temp);
        p[i].setCompany(temp);
        getline(f, temp);
        int l = stoi(temp);
        p[i].setQuantity(l);
        getline(f,temp);
        p[i].setDescription(temp);
        getline(f,temp);
        p[i].setColor(temp);
        getline(f,temp);
        p[i].setSize(temp);
        getline(f,temp);
        p[i].setCompany(temp);
        i++;
        }}

        cout<<"Total items on store "<<shopname<<" are: "<<count<<endl<<endl;

    for(int i=0 ;i<count; i++){
        cout<<"item no: "<<i+1<<endl;
        p[i].display_product();
        cout<<endl;
    }

        cout<<endl<<endl<<endl<<"========================="<<endl;
        cout<<"Press 1 to Update product detailss"<<endl;
        cout<<"Press 0 to exit"<<endl;
        int k;
        cout<<"Enter option: "; cin>>k;


        if(k==1){
            cout<<"Enter the product number you want to change: "; int pno1; cin>>pno1; 
            p[pno1-1].updateproduct();

            if(pno1 > count || pno1 <0){
                cout<<"Invalid product number"<<endl;
            }

            for(int i=0; i<count; i++){
                fstream f("temp.txt", ios::app);
                f<<i+1<<endl;

               
                f<< p[i].getName()<<endl;
       
                f<<p[i].getPrice()<<endl;
        
                f<<p[i].getCompany()<<endl;
     
                f<<p[i].getQuantity()<<endl;
      
                f<<p[i].getDescription()<<endl;
       
                f<<p[i].getColor()<<endl;
     
                f<<p[i].getSize()<<endl;
      
                f<<p[i].getCompany()<<endl;

            }

             const char* rename_file = filename.c_str();
            remove(rename_file);

            rename("temp.txt", rename_file);
        }

          
    

        if(k==0){
            cout<<"Exiting"<<endl;
            return;
        }

    
}

void serialnorecord(){ 
    fstream f("srno.txt", ios::out);
    f<<"0"<<endl;
    f<<"0"<<endl;
}



void Administrator::deleteproduct(string shopname){

    string shop = shopname + ".txt";

    fstream f(shop);
    fstream temp("temp.txt");

    string s;

    while(!f.eof()){
    getline(f, shop);
    }



} 

void Administrator::del_data(){

cout<<"Enter 1 to Delete a Shopkeeper"<<endl;
cout<<"Enter 2 to Delete a Customer"<<endl;
int c; cin>>c;

switch(c){
case 1:
sh.del_data();
break;

case 2:
cs.del_data();
break;}

}




void Shopkeeper::del_data(){


        fstream f;
        fstream temp("temp.txt",ios::out);
        f.open("created_account_sh.txt", ios::in);

        string read, read2, read3, read4,read5, read6, read7, read8, read9, read10;

        cout<<endl<<"Enter Email address of the Shopkeeper you want to DELETE: "; string search; cin>>search;


        while(!f.eof()){
            getline(f, read);
            if(read == search) break;
        }

        getline(f,read2);
        getline(f,read3);
        getline(f,read4);
        getline(f, read5);
        getline(f, read6);   //reads indicate fields in waiting list
        getline(f, read7);
        getline(f, read8);
        getline(f, read9);
        getline(f, read10);


        cout<<"=============== WARNING!!! =============="<<endl;
        cout<<"This shopkeeper wil be deleted: "<<endl<<endl;
        cout<<"Email Adderss"<<read<<endl;
        cout<<"First Name: "<<read2<<endl;
        cout<<"Last Name: "<<read3<<endl;
        cout<<"Password: "<<read4<<endl;
        cout<<"Date: "<<read5<<endl;
        cout<<"Shop Name: "<<read6<<endl;
        cout<<"Address: "<<read7<<endl;
        cout<<"Blood Group: "<<read8<<endl;
        cout<<"Gender: "<<read9<<endl;
        cout<<"Number: "<<read10<<endl;

        cout<<endl<<"Press 1 to delete"<<endl;
        cout<<endl<<"Press 0 to exit"<<endl;
        cout<<"Enter your option: "; int sel; cin>>sel;
        if(sel ==0)
        return;

        cout<<endl<<endl;
        User_Email =read;
        First_Name =read2;
        Last_Name = read3;
        Password = read4;
        date =read5;
        string shopname = read6;
        


       // temp<<read<<endl;

    string line;

    while (getline(f, line))
    {
      if (line != read && line !=read2 && line != read3 && line != read4 && line != read5 && line != read6 && line != read7 && line != read8 && line != read9 && line != read10)
        temp << line << endl;
    }

        remove("created_account_sh.txt");

        rename("temp.txt", "created_account_sh.txt");


}



void Customer::del_data(){


        fstream f;
        fstream temp("temp.txt",ios::out);
        f.open("created_account_ch.txt", ios::in);

        string read, read2, read3, read4,read5,read6, read7, read8, read9;

        cout<<endl<<"Enter Email address of the Customer you want to DELETE: "; string search; cin>>search;


        while(!f.eof()){
            getline(f, read);
            if(read == search) break;
        }

        getline(f,read2);
        getline(f,read3);
        getline(f,read4);
        getline(f, read5);
        getline(f, read7);
        getline(f, read8);
        getline(f, read9);
       //reads indicate fields in waiting list

        cout<<"=============== WARNING!!! =============="<<endl;
        cout<<"This shopkeeper will be deleted: "<<endl<<endl;
        cout<<"Email Adderss"<<read<<endl;
        cout<<"First Name: "<<read2<<endl;
        cout<<"Last Name: "<<read3<<endl;
        cout<<"Password: "<<read4<<endl;
        cout<<"Date: "<<read5<<endl;
        cout<<"Address: "<<read6<<endl;
        cout<<"Blood Group:"<<read7<<endl;
        cout<<"Gender: "<<read8<<endl;
        cout<<"Number: "<<read9<<endl;

        cout<<endl<<"Press 1 to delete"<<endl;
        cout<<endl<<"Press 0 to exit"<<endl;
        cout<<"Enter your option: "; int sel; cin>>sel;
        if(sel ==0)
        return;

        cout<<endl<<endl;
        User_Email =read;
        First_Name =read2;
        Last_Name = read3;
        Password = read4;
        date =read5;


       // temp<<read<<endl;

    string line;

    while (getline(f, line))
    {
      if (line != read && line !=read2 && line != read3 && line != read4 && line != read5 && line != read6 && line != read7 && line != read8 && line != read9)
        temp << line << endl;
    }

        remove("created_account_ch.txt");

        rename("temp.txt", "created_account_ch.txt");


}








void Customer::display_shop_products_to_customer(string Shopname){

    int count = 0;
    product p[10];
    //read items from file
        string file = Shopname;
        string filename = Shopname + ".txt";
        ifstream f(filename, ios::in);
        string temp;
        cout<<"Shop opened successfully: "<<filename<<endl;


       



int i =0;
   while(!f.eof()){
       getline(f,temp);

       if(temp != ""){

          // cout<<"I am entring it "<<i+1<<" times"<<endl;
       //count = stoi(temp);
       count = i+1;
 
  
        getline(f,temp);
        p[i].setName(temp);
        getline(f,temp);
        p[i].setPrice(stoi(temp));
        getline(f, temp);
        p[i].setCompany(temp);
        getline(f, temp);
        int l = stoi(temp);
        p[i].setQuantity(l);
        getline(f,temp);
        p[i].setDescription(temp);
        getline(f,temp);
        p[i].setColor(temp);
        getline(f,temp);
        p[i].setSize(temp);
        getline(f,temp);
        p[i].setCompany(temp);
        i++;
        }}

        cout<<"ITEM COUNT: "<<count<<endl<<endl;

    for(int i=0 ;i<count; i++){
        cout<<"item no: "<<i+1<<endl;
        p[i].display_product();
        cout<<endl;
    }

        cout<<endl<<endl<<endl<<"========================="<<endl;


      





//Customers Adds the product to the cart with


 while(true){
    cout<<endl<<endl<<"Enter the item no id you want to add to cart: ";
    cout<<"Press 0 to exit"<<endl;

    int prdno;
    cin >>prdno;
  

    if(prdno==0){
            cout<<"Exiting"<<endl;
            return;
        }




    if(prdno >count)
    {
        cout<<"Invalid productno entered"<<endl;
        cout<<"Exiting cart"<<endl;
        return;
    }

    cout<<"Enter Quantity: "; int quan; cin>>quan;

    //Check for item quantity:


    while(quan > p[prdno-1].getQuantity()){
      cout<<"Please reenter valid quntity (press 0 to exit): "; cin>>quan;
      if(quan == 0){ return;} 
    }

//Quantity deduction:
    int new_quan = p[prdno-1].getQuantity() - quan;

    p[prdno-1].setQuantity(new_quan);


    cout<<"Enter Size: "; string cat; cin>>cat;







    addtocart(prdno, quan, cat, file);
    cout<<endl<<"Your items have been successfully added to cart"<<endl;
    cout<<"press 0 to view the cart"<<endl;
    cout<<"press 1 to add more items"<<endl;
    cout<<"press 2 for back"<<endl;
    
    cout<<"Option: "; 
    int option; cin >> option;

    if(option==0)
        c.cart_show();
        break;
    if(option ==2)
        break;
        
}


        //For updating after the purchase has been made
            for(int i=0; i<count; i++){
                fstream f("temp.txt", ios::app);
                f<<i+1<<endl;

               
                f<< p[i].getName()<<endl;
       
                f<<p[i].getPrice()<<endl;
        
                f<<p[i].getCompany()<<endl;
     
                f<<p[i].getQuantity()<<endl;
      
                f<<p[i].getDescription()<<endl;
       
                f<<p[i].getColor()<<endl;
     
                f<<p[i].getSize()<<endl;
      
                f<<p[i].getCompany()<<endl;

            }

             const char* rename_file = filename.c_str();
            remove(rename_file);

            rename("temp.txt", rename_file);
    
}

int readshno(){
    fstream f("srno.txt", ios::in);
    string sno;
    getline(f,sno);
    return stoi(sno);
}

int readcno(){
    fstream f("srno.txt", ios::in);
    string sno;
    getline(f,sno);
    getline(f,sno);
    return stoi(sno);
}

void writeshno(int i){
    fstream f("temp.txt", ios::out);
    fstream f1("srno.txt", ios::in);

    f<<i<<endl;
    string towrite;
    getline(f1, towrite);
    getline(f1, towrite);

    f<<towrite<<endl;
    getline(f1, towrite);
    f<<towrite<<endl;

    remove("srno.txt"); rename("temp.txt", "srno.txt");
}

void writecno(int i){
        fstream f("temp.txt", ios::out);
    fstream f1("srno.txt", ios::in);

    string towrite;
    getline(f1, towrite);

    f<<towrite<<endl;
    f<<i<<endl;
    getline(f1, towrite);
    f<<towrite<<endl;


    remove("srno.txt"); rename("temp.txt", "srno.txt");


}

int getprdid(){
  fstream f("srno.txt", ios::in);
    string sno;
    getline(f,sno);
    getline(f,sno);
    getline(f,sno);
    return stoi(sno);
}

void writeprdid(int i){
    fstream f("temp.txt", ios::out);
    fstream f1("srno.txt", ios::in);

    string towrite;
    getline(f1, towrite);
    f<<towrite<<endl;
    getline(f1, towrite);

    f<<towrite<<endl;
    f<<i<<endl;

        remove("srno.txt"); rename("temp.txt", "srno.txt");


}
