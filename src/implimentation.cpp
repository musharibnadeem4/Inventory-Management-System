#include "ims.cpp"
#include <cstring>
#include <iostream>

int main(){


    Customer c;
    Shopkeeper sh;
    string s;

    Administrator ad;
    Person* person_ptr; //polymorphism
  


    //*********************Driver code*******************
while(true){


    cout<<"********WELCOME TO SHOPIFY<<********"<<endl<<endl<<endl;
    cout<<"1. Sign in"<<endl;
    cout<<"2. Create New Account"<<endl;
    int cho;
    cout<<"Choice: "; 
    cin >>cho;
    system("clear");

switch(cho){

case 1:
{   
    string email_signin;
    string password_signin;

    cout<<"Signin as?"<<endl;
    cout<<"1. Shopkeeper"<<endl;
    cout<<"2. Customer"<<endl;
    cout<<"3. Admin"<<endl;
    int k;
    cin>>k;

switch(k){

case 1:{
    cout<<"*************SIGN IN(shopkeeper)*************"<<endl;
    cout<<endl<<endl;
    cout<<"Enter your Email Address: "; cin>>email_signin;
    cout<<"Enter your Password: "; cin>>password_signin;

    fstream search("created_account_sh.txt");

    while(!search.eof()){
    string temp;
    getline(search, temp);

        if(temp == email_signin){
            sh.setmail(temp);
            getline(search, temp);

            sh.setfirstname(temp);
            getline(search, temp);

            sh.setlastname(temp);
            getline(search, temp);

            if(temp != password_signin )
            {cout<<endl<<"Wrong Password!"<<endl;
                break;}

            sh.setpassword(temp);
            getline(search, temp);

            sh.setdate(temp);

            getline(search, temp);
            sh.setshopname(temp);

            getline(search, temp);
            sh.setaddress(temp);

            getline(search, temp);
            sh.setbloodgroup(temp);

            getline(search, temp);
            sh.setgender(temp);

            getline(search, temp);
            sh.contactno(temp);



            sh.display(); //shopkeeper account display
            //break;

        }
       }
    



    break;}


case 2:{
    cout<<"*************SIGN IN(Customer)*************"<<endl;
    cout<<endl<<endl;
    cout<<"Enter your Email Address: "; cin>>email_signin;
    cout<<"Enter your Password: "; cin>>password_signin;

    fstream search("created_account_ch.txt", ios::in);

    while(!search.eof()){
    string temp;
    getline(search, temp);
        if(temp == email_signin){
            c.setmail(temp);
            getline(search, temp);

            c.setfirstname(temp);
            getline(search, temp);

            c.setlastname(temp);
            getline(search, temp);

            if(temp != password_signin )
            {cout<<endl<<"Wrong Password!"<<endl;
                break;}
            c.setpassword(temp);
            getline(search, temp);

            c.setdate(temp);


            getline(search, temp);
            c.setaddress(temp);

            getline(search, temp);
            c.setbloodgroup(temp);

            getline(search, temp);
            c.setgender(temp);

            getline(search, temp);
            c.contactno(temp);


            c.display(); //customer account display
            break;

        }
        else{
            cout<<"Acccuont Not found"<<endl;
           // break;
        }
    }
    break;}
    
    case 3:{
        system("clear");
        cout<<"**********Administrator login*************"<<endl<<endl;
        string username; int password;

        cout<<"Enter your user name: "; cin>>username;
        cout<<"Enter your password: "; cin>>password;

        if(username == "admin" && password == 123){
            cout<<"**********Administrator account***************"<<endl;

            cout<<endl<<endl<<"ADMINISTRATION APPROVAL:"<<endl;

            int admin_c;
            cout<<"Press 0 for account approvals: "<<endl;
            cout<<"Press 1 for editing shopkeeper details (PRODUCTs Edit)"<<endl;
            cout<<"Press 2 for editing customer details"<<endl;
            cout<<"Press 3 for editing product details"<<endl;
            cout<<"Press 4 to delete shopkeeper or customer"<<endl;
            cout<<"Press 5 to delete Products from a shop"<<endl;
            cout<<"Press 6 to Exit"<<endl;
            cout<<"Enter option: "; cin>>admin_c;
    
            switch(admin_c){
            case 0:{
            cout<<"Press 0 to approve customer account \nPress 1 for shopkeeper account: "<<endl;
            int h; cin>>h;
            
            switch(h){
                case 0:
            ad.customersignin();
            break;
                case 1:
            ad.shopkeepersignin();
            }break;}

            case 1:
            {
                //edit shopkeeper detials
                cout<<"Press 1 to show details of all shopkeepers: "<<endl;
                cout<<"Press 2 to edit shopkeeper details: "<<endl<<endl;
                int opt;
                cin>>opt;
                switch(opt){
                    case 1:
                        ad.showallshopkeepers();

                    case 2:
                        cout<<"Enter shopkeeper number to edit details: ";
                        int shno;
                        cin>>shno;
                        ad.editshopkeeper(shno);
                    

                    break;
                }
            }

            case 2:    {
                //edit shopkeeper detials
                cout<<"Press 1 to show details of all Customers: "<<endl;
                cout<<"Press 2 to edit Customers details: "<<endl<<endl;
                int opt;
                cin>>opt;
                switch(opt){
                    case 1:
                        ad.showallcustomers();

                    case 2:
                        cout<<"Enter Customer number to edit details: ";
                        int shno;
                        cin>>shno;
                        ad.editcustomers(shno); 
                    

                    break;
                }
            }

            case 3: {
                
                cout<<endl<<"++++++++++++++++++"<<endl<<endl<<endl;
                cout<<"Edit Product Details"<<endl;

                cout<<"List of all stores registered: "<<endl<<endl;

                fstream f("Shop.txt", ios::in);
                string display_shop;
                
                string shops[20];
                int no=1;

                while(!f.eof()){
                getline(f, display_shop);
                cout<<"Shop Number: "<<no<<endl;
                cout<<display_shop<<endl;
                shops[no] = display_shop;
                no++;}

                f.close();

                int shpno;

                cout<<"Enter Shop Number you want to edit the products of: "; cin>> shpno;
                ad.editproduct(shops[shpno]);   

                         
            }

            case 4:
                person_ptr = &ad;
                person_ptr->del_data();
                break;

            case 5:



            case 7:
            cout<<"Exiting"<<endl;

            }


    }
        break;
    }

    


    case 4: {
        cout<<endl<<"Account Not found"<<endl;
    }


    break;}
break;
}


case 2:{
    cout<<"***************Sign up****************"<<endl;
    cout<<"Do you want to create acconnt as:"<<endl;
    cout<<"1. Shopkeeper"<<endl;
    cout<<"2. Customer"<<endl;
    serialnorecord();
    int choice;
    cin>>choice;

    switch(choice){
        case 1:{
            string temp;
            cout<<"Enter you First Name"; cin>>temp;
            sh.setfirstname(temp);
            cout<<"Enter your Last Name"; cin>>temp;
            sh.setlastname(temp);
            cout<<"Enter your Email"; cin>>temp;
            sh.setmail(temp);
            cout<<"Enter your Password"; cin>>temp;
            sh.setpassword(temp);
            cout<<"Enter Date"<<endl; cin>>temp;
            sh.setdate(temp);
            cout<<"Enter your Shop's Name: "; cin>>temp;
            sh.setshopname(temp);
            cout<<"Enter your Address: "; cin>>temp;
            sh.setaddress(temp);
            cout<<"Enter your Phone Number: "; cin>>temp;
            sh.contactno(temp);
            cout<<"Enter your Gender: "; cin>>temp;
            sh.setgender(temp);
            cout<<"Enter your Blood Group: "; cin>>temp;
            sh.setbloodgroup(temp);


            sh.save();

            cout<<"Your Data has been saved successfully, it will be overviewed by the administrator"<<endl;

            }
        break;
        case 2:
            cout<<"***************Customer up****************"<<endl;
            string temp;
            cout<<"Enter you First Name"; cin>>temp;
            c.setfirstname(temp);
            cout<<"Enter your Last Name"; cin>>temp;
            c.setlastname(temp);
            cout<<"Enter your Email"; cin>>temp;
            c.setmail(temp);
            cout<<"Enter your Password"; cin>>temp;
            c.setpassword(temp);
            cout<<"Enter Date"<<endl; cin>>temp;
            c.setdate(temp);
            cout<<endl;
            cout<<"Enter your Address: "; cin>>temp;
            c.setaddress(temp);
            cout<<"Enter your Phone Number: "; cin>>temp;
            c.contactno(temp);
            cout<<"Enter your Gender: "; cin>>temp;
            c.setgender(temp);
            cout<<"Enter your Blood Group: "; cin>>temp;
            c.setbloodgroup(temp);
            

            c.save();

            cout<<"Your Data has been saved successfully, it will be overviewed by the administrator"<<endl;

        break;

    }
}
   
    cout<<"=========================================================================="<<endl<<endl;
    cout<<"THIS IS THE ADMISINSTRATION SIDE : "<<endl<<endl;
    cout<<endl<<endl<<"ADMINISTRATION APPROVAL:"<<endl;
    
    cout<<"Press 0 to approve customer account \nPress 1 for shopkeeper account: "<<endl;
    int h; cin>>h;
    
    switch(h){
        case 0:
    ad.customersignin();
    break;
        case 1:
    ad.shopkeepersignin();
    break;}
    
    
}
        

}

}