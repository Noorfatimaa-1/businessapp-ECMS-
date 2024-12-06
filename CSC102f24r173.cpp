#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//making structures

struct products
{
    string pdtnames;       //storing names
    float pdtprices;       //storing prices
    int pdtquantity;       //storing quantities      
};


struct orders
{
    string order_names;       //storing cart pdts names
    float order_prices;       //cart prices
    int order_quantities;     //cart pdt quantities

};

//making independent functions below

//input validation
void intvalid(int input)
{

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(300,'\n');
        cout<<"Invalid";
        cout<<endl;
        cout<<"Re-enter";
        cout<<endl;
        
    }
    
}

//requests validation
int intvalid1(int input)
{

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(300,'\n');
        cout<<"Invalid";
        cout<<endl;
    }
    
}


//loading data
bool loadproducts(products arr[],int &number_of_pdts,int &no_of_orders,orders arr2[],int &totalprice,const int MAX_PDTS,const int max)
{
    
    ifstream fin;
    fin.open("pdts.txt");
    if(!fin)
    {
        cout<<"unable to open the file"<<endl;
        return false;;

    }
    number_of_pdts=0;
    while(fin>>arr[number_of_pdts].pdtnames>>arr[number_of_pdts].pdtprices>>arr[number_of_pdts].pdtquantity )
    {   
                
       number_of_pdts++;
    }
    fin.close();
    

    fin.open("order.txt");
    if(!fin)
    {
        cout<<"unable to open the file"<<endl;
        return false;
    }
    no_of_orders=0;
    while( fin>>arr2[no_of_orders].order_names>>arr2[no_of_orders].order_prices>>arr2[no_of_orders].order_quantities)
    {
       
        no_of_orders++;
    }          
    fin.close();
    

    return true;
    


}


//saving data
bool savepdts(products arr[],int &number_of_pdts,int &no_of_orders,orders arr2[],int &totalprice,const int MAX_PDTS,const int max)
{
 
    ofstream fout;
    fout.open("pdts.txt");
    if(!fout)
      {
         cout<<"Unable to open the file";
         return false;
      }
      cout<<endl;
    for(int i=0;i<number_of_pdts;i++)
    {
      fout<<arr[i].pdtnames<<" "<<arr[i].pdtprices<<" "<<arr[i].pdtquantity<<endl;
    }
    fout.close();
    

    fout.open("order.txt");
    if(!fout)
      {
         cout<<"Unable to open the file";
         return false;
      }
      cout<<endl;
    for(int i=0;i<no_of_orders;i++)
    {
      fout<<arr2[i].order_names<<" "<<arr2[i].order_prices<<" "<<arr2[i].order_quantities<<endl;
    }
    fout.close();
    


    return true;
    

}


//validation functions
bool checkname(string &name)
{
    if(name.length()<=15)
    {
    for(int i=0;i<name.length();i++)
    {
       if((name[i]>='a'&&name[i]<='z')||(name[i]>='A'&&name[i]<='Z')||(name[i]==' '))
       return true;
    }
    }
    else
    {
      cout<<"Length>15."<<endl;
      return false;
    }
    
}


bool validation(string pdtnames[],float pdtprices[],int pdtquantity[],int &number_of_pdts)
{
    for(int i=0;i<number_of_pdts;i++)
    {
        if(checkname(pdtnames[i])&&pdtprices[i]>0&&pdtprices[i]>0)
        return true;
    }
    return false;
}

bool validprice(float price)
{
    if(price>0)
    return price==static_cast<int>(price);
    else
    {
      cout<<"Re-enter : "<<endl;
      return false;
    }
}



bool validquantity(int quantity)
{
     
    if(quantity>0)
    return quantity==static_cast<int>(quantity);
    else
    {
      cout<<"Re-enter : "<<endl;
      return false;
    }

}


void header()                    //function for printing the header             
{
    cout <<setw(70)<<left<< "=============================================================" << endl;
    cout <<setw(70)<<left<< " ^^^^^^^^      ^^^^^^^        ^^^^^^     ^^^^^^        ^^^^^" << endl;
    cout <<setw(70)<<left<< " *******     *)       (*      **   *    *   ***      *)      (*"<<endl;
    cout <<setw(70)<<left<< " ^)         ^)         (^     ^)    ^^ ^^    (^     ^)        (^" << endl;
    cout <<setw(70)<<left<< " ^)         ^)                ^)     ^^^     (^      ^)" << endl;
    cout <<setw(70)<<left<< " *******    *)                *)      *      (*       *) "<<endl;
    cout <<setw(70)<<left<< " ^^^^^^^^   ^)                ^)             (^         ^^^" << endl;
    cout <<setw(70)<<left<< " ^)         ^)                ^)             (^             (^" << endl;
    cout <<setw(70)<<left<< " ^)         ^)         (*     ^)             (^      ^)      (^" << endl;
    cout <<setw(70)<<left<< " *******     *)       (^      *)             (*      *)      (*" <<endl;
    cout <<setw(70)<<left<< " ^^^^^^^^      ^^^^^^         ^)             (^        ^^^^^" << endl;
    cout <<setw(70)<<left<< "=============================================================" << endl;

    cout << endl;
    cout << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout <<setw(40)<<left<< "**     E -  **" << endl;
    cout <<setw(40)<<left<< "**     C ommerce  **" << endl;
    cout <<setw(40)<<left<< "**     M anagement   **" << endl;
    cout <<setw(40)<<left<< "**     S ystem   **" << endl;

    for (int i = 0; i < 30; i++)
    {
        cout << "*";
    }
    cout << endl;            
}                              //end of 1st function             
 


void mainmenu()                  //function for mainmenu
{
    for (int i = 0; i < 40; i++)
    {
        cout << "~";
    }
    cout << endl;
    cout << setw(23) << right << "   WELCOME to ECMS   " << endl;
    for (int i = 0; i < 40;i++)
    {
        cout << "~";
    }
    cout << endl;
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "1. Login as Admin(seller)" << endl;
    cout << "2. Proceed as Buyer" << endl;
    cout << "0. Exit" << endl;
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;

}                     
//end of function(main menu)


//seller menu functions
void adminmenu()                    //admin menu printing function
{
    for (int i = 0; i < 40; i++)
    {
       cout << "~";
    }
    cout<<endl;
    cout << setw(30) << right << "Welcome Admin(seller)" << endl;
    for (int i = 0; i < 40; i++)
    {
       cout << "~";
    }
    cout<<endl;
    cout << "**MENU**";
    cout << endl;
    cout << "1. Add product" << endl;
    cout << "2. Delete product" << endl;
    cout << "3. Edit product" << endl;
    cout << "4. View product" <<endl;
    cout << "5. View orders" << endl;
    cout << "6. Sales" << endl;
    cout << "7. logout" << endl;
    cout << "Select what you want(1 to 6) :" << endl;  
}     



void addproducts(products arr[],int &number_of_pdts,const int MAX_PDTS)                                //function for adding products by seller
{
   if(number_of_pdts<90)
    {
        for (int i = 0; i < 24; i++)
        {
        cout << "~";
        }
        cout<<endl;
        cout<<"(You can add new products now)"<<endl;
            for (int i = 0; i < 24; i++)
        {
        cout << "~";
        }
        cout<<endl;
        string namepdt;
        int quantitypdt;
        float pricepdt;
        cout<<"Enter product name (less that 15 characters long): "<<endl;
        cin.ignore();
        getline(cin,namepdt);         //array storing names
        while(!checkname(namepdt))
        {
        cout<<"Invalid name "<<endl;
        cout<<"Re-enter: ";
        getline(cin,namepdt);  
        }
        arr[number_of_pdts].pdtnames=namepdt;

        cout<<"Enter product price : "<<endl;
        do
        {
            cin>>pricepdt; 
            intvalid1(pricepdt);
            
        } while (!validprice(pricepdt));
        
        
        arr[number_of_pdts].pdtprices=pricepdt;

        cout<<"Enter product quantity : "<<endl;
        do
        {
            cin>>quantitypdt; 
            intvalid1(quantitypdt);  
        } while (!validprice(quantitypdt));

        arr[number_of_pdts].pdtquantity=quantitypdt;
        number_of_pdts++;                              //incrementing as tghe products are adding
        cout<<"PRODUCT ADDED!"<<endl;                  // msg after succesful addition

    }
    else
    {
        for (int i = 0; i < 60; i++)
        {
        cout << "*";
        }
        cout<<endl;
        cout<<setw(45) << right << "MAXIMUM NUMBER OF PRODUCTS HAS BEEN ADDED!"<<endl;
        cout<<setw(40) << right << "No more products can be added!"<<endl;
        cout<< setw(30) << right <<"THANK YOU!!"<<endl;
        for (int i = 0; i < 60; i++)
        {
        cout << "*";
        }
        cout<<endl;
    }
}
//end of add products function


void deleteproducts(products arr[],int &number_of_pdts,const int MAX_PDTS)                           //function for deleting products by the seller
{
    string delete_pwd;
    int delpdt;
    for (int i = 0; i < 40; i++)
        {
        cout << "*";
        }
    cout<<endl;
    cout<< setw(32)<< right <<"You can delete products now:"<<endl;
    for (int i = 0; i < 40; i++)
        {
        cout << "*";
        }
    cout<<endl;
    cout << endl;
    cout<<"Enter a product number to delete: " << endl;

    do
    {
        cin>>delpdt; 
        intvalid1(delpdt);  
    } while (!validprice(delpdt));
    cout<<"FOR EXTRA SECURITY,we have added a new option."<<endl;
    cout<<"Enter the password of the system then the deletion will take place"<<endl;
    cin>>delete_pwd;
    if(delete_pwd=="2abc")
    {
        if(delpdt>=1&&delpdt<=number_of_pdts)
        {
            for(int i=delpdt-1;i<number_of_pdts-1;i++)
            {
               arr[i].pdtnames=arr[i+1].pdtnames;
               arr[i].pdtprices=arr[i+1].pdtprices;
               arr[i].pdtquantity=arr[i+1].pdtquantity;
            }
        number_of_pdts--;
        cout<<"Product deleted successfully"<<endl;
        }
        else
        {
            cout<<"This product number is not valid"<<endl;
            return;
        }
    }
    else
    {
        cout<<"Wrong password";
        cout<<endl;
    }
}
//end of del products function


void updatingproducts(products arr[],int &number_of_pdts,const int MAX_PDTS)                //function for updating products
{
    string update_pwd;                  //again taking pwd for extra featuring
    int productnum,update;             //identifier for product number to update(index)
    string new_name_of_pdt;            //identifier for new product
    int newquan;
    float newprice;              //identifier to store new product characteristics
    for(int i=0;i<24;i++)
    {
        cout<<"~";               
    }
    cout<<endl;
    cout<<"You can update products now "<<endl;
    for(int i=0;i<24;i++)
    {
        cout<<"~";               
    }
    cout<<endl;
    cout<<"Enter product number to update : "<<endl;
    
    do
    {
        cin>>productnum; 
        intvalid1(productnum);  
    } while (!validprice(productnum));

    if(productnum>=1&&productnum<=number_of_pdts)
    {
        cout<<"What do you want to change about the product?"<<endl;
        cout<<"1.Name"<<endl;
        cout<<"2.Quantity"<<endl;
        cout<<"3.Price"<<endl;
        cin>>update;
        if(update==1||update==2||update==3)
        {
            if(update==1)
            {
                cout<<"CURRENT NAME OF PRODUCT IS : "<< arr[productnum-1].pdtnames;
                cout<<endl;
                cout<<"Enter new name : ";
                cin.ignore();
                getline(cin,new_name_of_pdt);
                if(checkname(new_name_of_pdt))
                {
                    cout<<"FOR SECURITY PURPOSE , you have to enter the password."<<endl;
                    cout<<"Enter";
                    cin>>update_pwd;
                    if(update_pwd=="2abc")
                    {
                        arr[productnum-1].pdtnames=new_name_of_pdt;
                        cout<<"Changed successfully";
                    }
                    else
                    {
                        cout<<"Wrong credentials"<< endl;
                    }
                    cout<<endl;
                }
                else
                {
                    cout<<"Invalid";
                    cout<<endl;
                    return;
                }
            }
            else if(update==2)
            {
                cout<<"CURRENT quantity OF PRODUCT IS : "<< arr[productnum-1].pdtquantity;
                cout << endl;
                cout<<"Enter new quantity"<<endl;
                 do
                {
                    cin>>newquan; 
                    intvalid1(newquan);  
                } while (!validprice(newquan));
                cout<<"FOR EXTRA SECURITY,we have added a new option."<<endl;
                cout<<"Enter the password of the system then the changes will take place"<<endl;
                cin>>update_pwd;
                if(update_pwd=="2abc")
                {
                    cout<<"Changed successfully";
                    cout<<endl;
                    arr[productnum-1].pdtquantity=newquan;
                }
                else
                {
                    cout<<"Wrong password !!";
                    cout<<endl;
                }
            }
            else if(update==3)
            {
                cout<<"CURRENT price OF PRODUCT IS : "<< arr[productnum-1].pdtprices;
                cout << endl;
                cout<<"Enter new price"<<endl;
                 do
                {
                    cin>>newprice; 
                    intvalid1(newprice);  
                } while (!validprice(newprice));
                cout<<"FOR EXTRA SECURITY,we have added a new option."<<endl;
                cout<<"Enter the password of the system then the changes will take place"<<endl;
                cin>>update_pwd;
                if(update_pwd=="2abc")
                {
                    cout<<"Changed successfully";
                    cout<<endl;
                   arr[productnum-1].pdtprices=newprice;
                }
                else
                {
                    cout<<"Wrong password !!";
                    cout<<endl;
                }
            }
        }
        else
        {
            cout<<"Enter (1,2,3) for update purpose"<<endl;
            return;
        }
    }
    else
    {
        cout<<"This product number is not valid"<<endl;
        cout<<"You can only edit the available products"<<endl;
        cout<<"ENTER 1 to "<<number_of_pdts<<endl;              
    }
}
//end of update products function


void listingout(products arr[],int &number_of_pdts,const int MAX_PDTS)                    //function for listing the products out
{
    if(number_of_pdts==0)
    {
         for(int i=0;i<40;i++)
        {
            cout<<"~";               
        }
        cout<<endl;
        cout<<setw(24)<<right<<"NO PRODUCTS AVAILABLE "<<endl;
            for(int i=0;i<40;i++)
        {
            cout<<"~";               
        }
        cout<<endl;
    }
    else
    {
      for(int i=0;i<60;i++)
        {
            cout<<"~";               
        }
        cout<<endl;
        cout<< setw(40) << right << "PRODUCTS ARE LISTED BELOW"<<endl;
            for(int i=0;i<60;i++)
        {
            cout<<"~";               
        }
        cout<<endl;
        cout<<endl;
        cout<<setw(15)<<left<<"Seriel no."<<setw(18)<<left<<"Names"<<setw(10)<<left<<"Price"  <<setw(15)<<right<<"Quantity: "<<endl;
        for(int i=0;i<60;i++)
                {
                    cout<<"-";               
                }
        cout<<endl; 
        for(int i=0;i<number_of_pdts;i++)
            {
                cout<<setw(15)<<left<<(i+1)<<setw(18)<<left<<arr[i].pdtnames<<arr[i].pdtprices<<"PKR"<<setw(12)<<right<<arr[i].pdtquantity<<endl;
                for(int i=0;i<60;i++)
                {
                cout<<"-";               
                }
                cout<<endl;
            }
    }
}
//end of listing out function


void vieworders(orders arr2[],const int max,int &no_of_orders)                     //seller can view the orders
{
    if(no_of_orders==0)
    {
         for(int i=0;i<35;i++)
         {
           cout<<"~";               
         }
        cout<<endl;
        cout<<setw(24)<<right<<"NO Orders Yet "<<endl;
         for(int i=0;i<35;i++)
         {
           cout<<"~";               
         }
        cout<<endl;
    }
    else
    {
    for(int i=0;i<35;i++)
        {
            cout<<"~";               
        }
        cout<<endl;
        cout<<setw(25)<<right<<"YOU CAN VIEW ORDERS!!"<<endl;
        for(int i=0;i<35;i++)
        {
            cout<<"~";               
        }
        cout<<endl;
        cout<<endl;
        cout<<setw(15)<<left<<"Sr. no."<<setw(18)<<left<<"Names"<<setw(15)<<left<<"Prices"<<setw(10)<<right<<"Quantity";
        cout<<endl;
        for(int i=0;i<60;i++)
                {
                    cout<<"-";               
                }
        cout<<endl; 
        for(int i=0;i<no_of_orders;i++)
        {
            cout<<setw(15)<<left<< i+1 <<setw(18)<<left<<arr2[i].order_names<<arr2[i].order_prices<<"PKR"<<setw(16)<<right<<arr2[i].order_quantities;
            cout<<endl;
            for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
            cout<<endl;
        }
    cout<<endl;  
    }
}
//end od vieworders function


void showingsales(orders arr2[],const int max,int &no_of_orders ,int totalprice)
{
    if(no_of_orders>0)
    {
        for(int i=0;i<35;i++)
        {
            cout<<"~";               
        }
        cout<<endl;
        cout<<setw(24)<<right<<"SALES PANEL"<<endl;
        for(int i=0;i<35;i++)
        {
            cout<<"~";               
        }
        cout<<endl;
        cout<<endl;
        cout<<setw(15)<<left<<"Sr. no."<<setw(18)<<left<<"Names"<<setw(15)<<left<<"Prices"<<setw(12)<<right<<"Quantity";
        cout<<endl;
        for(int i=0;i<60;i++)
                {
                    cout<<"-";               
                }
        cout<<endl; 
        for(int i=0;i<no_of_orders;i++)
        {
            cout<<setw(15)<<left<< i+1 <<setw(18)<<left<<arr2[i].order_names<<arr2[i].order_prices<<"PKR"<<setw(16)<<right<<arr2[i].order_quantities;
            cout<<endl;
            for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
            cout<<endl;

            totalprice=totalprice+(arr2[i].order_prices*arr2[i].order_quantities);
        }
        cout<<endl;                   
        cout<<"THE TOTAL SALE IS OF AMOUNT : ";
        cout<<totalprice <<"PKR "<<endl;                    
        cout<<endl;
    }
    else
    {
        for(int i=0;i<35;i++)
        {
            cout<<"-";               
        }
        cout<<endl;
        
        cout<<setw(22)<<right<<"NO SALES ";
    
        cout<<endl;
        for(int i=0;i<35;i++)
        {
            cout<<"-";               
        }
        cout<<endl;
    }
}
//showing sales end


void logoutseller()                     //function for seller logout
{
    for(int i=0;i<35;i++)
    {
        cout<<"~";               
    }
    cout<<endl;
    cout<<setw(22)<< right << "LOGGING OUT"<<endl;
    cout<<setw(30)<<right <<"You are logging out of the system!!"<<endl;
    for(int i=0;i<35;i++)
    {
        cout<<"~";               
    }
    cout<<endl;

}
//end of logout seller function


 //buyer menu functions

 void welcomeprint()                 //printing welcome line on console
 {
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << setw(25) << right <<  "WELCOME buyer" << endl;
    cout << setw(32) << right << "YOU CAN SHOP FROM OUR STORE!!" << endl;
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "WILL TRY TO PROVIDE YOU THE BEST SERVICE"<<endl;
     for (int i = 0; i < 40; i++)
        {
            cout << "*";
        }
    cout << endl;
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout<< endl;
}
//end 


void buyermenu()                //printing buyer menu on console
{      
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout<< setw(25)<< right <<"**BUYER MENU**"<<endl;
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "1. View products" << endl;
    cout << "2. View cart" << endl;
    cout << "3. Place Order" << endl;
    cout << "4. Checkout"<<endl;
    cout << "5. Remove order"<<endl;
    cout << "6. Help section" << endl;
    cout << "7. Exit" <<endl;
}
//end of buyer menu function


void cart(orders arr2[],int &no_of_orders,const int max)                //function to print cart on console
{
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << setw(25) << right << "  **BUYER CART**"<<endl;
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;
    if(no_of_orders==0)
    {
        for (int i = 0; i < 40; i++)
        {
        cout << "*";
        }
        cout << endl;
        cout<< setw(30) << right <<  "NO PRODUCT IS IN THE CART"<<endl;
        for (int i = 0; i < 40; i++)
        {
        cout << "*";
        }
        cout << endl;
        cout<< endl;
        cout << endl;
    }
    else
    {
    cout<<setw(15)<<left<<"Sr. no."<<setw(18)<<left<<"Names"<<setw(15)<<left<<"Prices"<<setw(13)<<right<<"Quantity";
    cout<<endl;
    for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
    cout<<endl; 
    for(int i=0;i<no_of_orders;i++)
    {
        cout<<setw(15)<<left<< i+1 <<setw(18)<<left<<arr2[i].order_names<<arr2[i].order_prices<<"PKR"<<setw(17)<<right<<arr2[i].order_quantities;
         cout<<endl;
         for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
        cout<<endl; 
    }
    }
    
}
//end of cart function


void orderplacingpanel(products arr[],int &number_of_pdts,int &no_of_orders,const int MAX_PDTS)
{
   
    
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << setw(28 )<< right <<" ORDER PLACING PANEL"<<endl;
    for (int i = 0; i < 40; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << endl;
    if(number_of_pdts==0)                             //checking if any product available
    {
        for (int i = 0; i < 40; i++)
        {
        cout << "*";
        }
        cout << endl;
        cout<<setw(30)<<right <<"No Products Added by Admin yet"<<endl;
        for (int i = 0; i < 40; i++)
        {
        cout << "*";
        }
        cout << endl;
    }
    if(no_of_orders>=10)
    {
         for (int i = 0; i < 30; i++)
        {
           cout << "*";
        }
        cout << endl;
        cout<<"No more orders can be placed "<<endl;
        cout<<"Maximum limit reaached.";
        cout<<endl;

        for (int i = 0; i < 30; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
     if(no_of_orders<10)
    {
        for (int i = 0; i < 40; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << setw(30) << right << " YOU CAN PLACE ORDERS NOW !!"<<endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout<< endl;
   
        cout<<endl;
        listingout(arr,number_of_pdts,MAX_PDTS);                 //listing out function calling again to show the user available products
        cout << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "*";
        }
        cout << endl;
        cout<<"You can place 10 orders at a time"<<endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
//end of orderplacing panel function


void orderplacing(products arr[],const int MAX_PDTS,int &number_of_pdts,orders arr2[],const int max,int &no_of_orders)         //function for buyer to place orders
{
    
    int orderid,order_quantity;              //taking order
    string addorder;                         //asking user if he wants to order again
    int totalprice=0;
    while(no_of_orders<10)                    //loop starts 
    {
    cout<<"Enter the product id"<<endl;
    do
    {
        cin>>orderid; 
        intvalid1(orderid);
    } while (!validprice(orderid));
    while(!(orderid>=1&&orderid<=number_of_pdts))
        {
           cout<<"Invalid product id ";
           cout<< " Re-enter : ";
           cin>>orderid;
           intvalid(orderid);
           cout<<endl;
    
        }
 
       
     
    orderid--;                               //decrementing it because we have index starting from 0
   
    if(arr[orderid].pdtquantity==0)
        {
            cout<<"SOLD OUT!";
            cout<<endl;
            break;
        }
    else
    {
    cout<<"Enter the product quantity"<<endl;
    
   do
    {
        cin>>order_quantity; 
        intvalid1(order_quantity);  
    } while (!validprice(order_quantity));
    while(!(order_quantity>=1&&order_quantity<=arr[orderid].pdtquantity))
    {
    
        cout<<"Invalid"<<endl;
        cout<<"Re-enter : ";
        cin>>order_quantity;
        intvalid1(order_quantity);
        cout << endl;
    }
    
    arr2[no_of_orders].order_names=arr[orderid].pdtnames;     
    arr2[no_of_orders].order_quantities=order_quantity;  
    arr2[no_of_orders].order_prices=arr[orderid].pdtprices;
    no_of_orders++;

    arr[orderid].pdtquantity=arr[orderid].pdtquantity-order_quantity;
    totalprice=totalprice+arr2[no_of_orders].order_prices;

    cout<<"PRODUCT ADDED!!"<<endl;
    
    cout<<"IF you dont want to order another product press N else press anyother key"<<endl;
    cin>>addorder;
    if(addorder=="N"||addorder=="n")
    break;
    else
    {
       continue;
    }
   }
  }   //loop ends here
    if(no_of_orders==10)
    {
        cout<<"MAX LIMIT REACHED!"<<endl;
        cout<<endl;
    }
}
//end of order placing function


void helpsection()             //function to display help section
{
    for(int i=0;i<30;i++)
        {
            cout<<"~";               
        }
    cout<<endl;
    cout<<endl;
    cout<<setw(25)<<right<< "WELCOME TO HELP SECTION"<<endl;
    cout<<endl;
    for(int i=0;i<30;i++)
        {
            cout<<"~";               
        }
    cout<<endl;
    cout << endl;
    for(int i=0;i<30;i++)
        {
            cout<<"-";               
        }
    cout<<endl;
    cout<<"You can use the system the following way";
    cout<<endl;
    for(int i=0;i<30;i++)
        {
            cout<<"-";               
        }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<50;i++)
        {
            cout<<"*";               
        }
    cout<<endl;
    cout<<endl;
    cout << " 1. You can view products by pressing 1"<<endl;
    cout << " 2. You can view cart by pressing 2"<<endl;
    cout << " 3. You can place order by pressing 3"<<endl;
    cout << " 4. You can view checkout by pressing 4"<<endl;
    cout << " 5. You can exit the buyer section by pressing 5"<<endl;
    cout<<endl;
    for(int i=0;i<50;i++)
        {
            cout<<"*";               
        }
    cout<<endl;
    
}
//end of helpsection function


void checkout(orders arr2[],const int max,int &no_of_orders,int totalprice)       //checkout function start
{
    if(no_of_orders>0)
    {

        for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
        cout<<endl;
        
        cout<<setw(38)<<right<<"BILL SUMMARY"<<endl;
        for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
        cout<<endl;
        cout<<setw(15)<<left<<"Sr. no."<<setw(18)<<left<<"Names"<<setw(15)<<left<<"Prices"<<setw(12)<<right<<"Quantity";
        cout<<endl;
        for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
        cout<<endl;   
        for(int i=0;i<no_of_orders;i++)
        {

            cout<<setw(15)<<left<< i+1 <<setw(18)<<left<<arr2[i].order_names<<arr2[i].order_prices<<" PKR"<<setw(14)<<right<<arr2[i].order_quantities;
            cout << endl;
            for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
            cout<<endl;   
            totalprice=totalprice+(arr2[i].order_prices*arr2[i].order_quantities);
        }
        cout<<endl;
        cout<<endl;               
        for(int i=0;i<60;i++)
            {
                cout<<"~";               
            }
        cout<<endl;
        cout<<setw(23)<<right<<"THE AMOUNT YOU HAVE TO PAY IS ------- "<<totalprice<<" PKR"<<endl;
        for(int i=0;i<60;i++)
            {
                cout<<"~";              
            }
        cout<<endl;
        cout<<endl;                  
        for(int i=0;i<60;i++)
            {
                cout<<"*";               
            }
        cout<<endl;
        cout<<setw(42)<<right<<"THANKYOU FOR SHOPPING "<<endl;
        for(int i=0;i<60;i++)
            {
                cout<<"*";               
            }
        cout<<endl;
        cout<<endl;     
        cout<<setw(60)<<right<<"-------"<<endl;
        cout<<setw(59)<<right<<"ECMS"<<endl;
        cout<<setw(60)<<right<<"-------"<<endl;
        no_of_orders=0;
    }
     else
    {
        for(int i=0;i<40;i++)
            {
                cout<<"-";               
            }
        cout<<endl; 
        cout<< setw(30)<<right << "YOU HAVE NOT PLACE ANY ORDER YET!!";
        cout<<endl;
        for(int i=0;i<40;i++)
            {
                cout<<"-";               
            }
        cout<<endl;     
    }
}
//end of checkout function



void buyerexit()               //buyerexit function
{
    for(int i=0;i<24;i++)
    {
        cout<<"*";               
    }
    cout<<endl;
    cout<<"Thank you for using!!  "<<endl;
     for(int i=0;i<24;i++)
    {
        cout<<"*";               
    }
    cout<<endl;
}


int inputadmin(int adminrequest)
{
    cout<<"Re-enter";
    cin>>adminrequest;
}



//credentials check
bool correctpwd(string username,string pwd)
{
   if(username=="seller"&&pwd=="2abc")
   return true;
   else
   return false;
}



//delete orders
void deleteorders(products arr[],int &number_of_pdts,orders arr2[],const int max,int &no_of_orders)
{
    if(no_of_orders==0)
    {
        cout<<"NO ORDERS PLACED .";
        cout<< endl;
    }
    else
    {
        for(int i=0;i<60;i++)
            {
                cout<<"*";               
            }
        cout<<endl; 
        cout << setw(40) << right <<" ORDER ARE LISTED BELOW ";
        cout<<endl;
        for(int i=0;i<60;i++)
            {
                cout<<"*";               
            }
        cout<<endl; 
        cout<<endl;
        cout<<setw(15)<<left<<"Sr. no."<<setw(18)<<left<<"Names"<<setw(15)<<left<<"Prices"<<setw(10)<<right<<"Quantity";
        cout<<endl;
        for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
        cout<<endl; 
        for(int i=0;i<no_of_orders;i++)
        {
            cout<<setw(15)<<left<< i+1 <<setw(18)<<left<<arr2[i].order_names<<arr2[i].order_prices<<"PKR"<<setw(16)<<right<<arr2[i].order_quantities;
            cout<<endl;
            for(int i=0;i<60;i++)
            {
                cout<<"-";               
            }
            cout<<endl;
        }
    
    int orderdel;
    cout<<"Enter id : ";
    do
    {
        cin>>orderdel; 
        intvalid1(orderdel);                                //function for checking wether the enetredid is integer 
    }while (!validprice(orderdel));                         //entered id is positive

     while(!(orderdel>=1&&orderdel<=no_of_orders))          //while loop for checking wether the entered id exists
        {
           cout<<"Invalid product id ";
           cout<< " Re-enter : ";
           cin>>orderdel;
           intvalid(orderdel);
           cout<<endl;
        }
    orderdel--;                                             //decrementing as index start from 0
    for(int i=orderdel;i<no_of_orders;i++)
    {
       arr2[i].order_names=arr2[i+1].order_names;
       arr2[i].order_quantities=arr2[i+1].order_quantities;
       arr2[i].order_prices=arr2[i+1].order_prices;
    }
    no_of_orders--;
    cout<<"Order deleted successfully.";
    cout<< endl;
    }

}


//main function 
int main()                        
{
    
    int adminrequest;            //input of admin menu
    int buyerrequest;            //buyermenu input
    string  input;               //mainmenu input

   
   
    string username, pwd;        //username and password of admin

    //abt product
    int number_of_pdts=0;          //how many products has added or left
    const int MAX_PDTS=300;
    products arr[MAX_PDTS];
    
    
    //abt order
    const int max=10;
    orders arr2[max];
    int no_of_orders=0;            //products in cart counter;
    int totalprice=0;              //track total sales

    //calling functions

  
    system("cls");             //clearing screenx)
    header();                  //headerprinting
    loadproducts( arr,number_of_pdts,no_of_orders, arr2,totalprice, MAX_PDTS,max);   //loading data from file
    while(true)
    {
        mainmenu();                //mainmenuprinting
        cout << "If u are an admin press 1 and if you are buyer press 2 otherwise you will be exit by pressing 0 ";
        cout << endl;
        cout << "Enter : ";
        cin>>input;
         if(input == "0")     //input 0  if 
            {
                cout << "Exit it is!" << endl;
                break;
            }
         if(!(input=="0"||input=="1"||input=="2"))
        {
            
            cout<<"You have 3 options(0,1,2)";
            cout<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }
         if(input=="1"||input=="2")
        {
        
            
            if (input == "1")            //checking for input  (1st if-of input)
            {
                system("cls");
                cout << "Enter username :";
                cin >> username;
                cout << "Enter password :";
                cin >> pwd;           //taking username and password
                        
                    if (correctpwd(username,pwd))
                    {
                        while(true)
                        {
                            
                            adminmenu();       //calling for printing admin menu on console
                            cin>>adminrequest;
                            intvalid1(adminrequest);
                        
                            if(adminrequest==7)
                            {
                                logoutseller();
                                cout<<endl;
                                break;
                            }
                            if(adminrequest==1||adminrequest==2||adminrequest==3||adminrequest==4||adminrequest==5||adminrequest==6||adminrequest==7)   //validation
                            {
                                switch(adminrequest)             //for selecting one from multiple options 
                                {
                                    case 1:
                                    {
                                        system("cls");
                                        addproducts( arr,number_of_pdts, MAX_PDTS);           //product addition
                                        break;
                                    }
                                    case 2:
                                    {
                                        deleteproducts(arr,number_of_pdts, MAX_PDTS);         //product deletion
                                        break;
                                    }
                                    case 3:
                                    {   
                                        updatingproducts(arr,number_of_pdts, MAX_PDTS);     //product updation
                                        break;
                                    }
                                    case 4:
                                    {
                                        listingout( arr,number_of_pdts,MAX_PDTS);           //listing the products
                                        break;
                                    }
                                    case 5:
                                    {
                                        vieworders(arr2,max,no_of_orders);          //admin viewing the orders
                                        break;
                                    }
                                    case 6:
                                    {
                                        showingsales(arr2,max,no_of_orders,totalprice);      //call for sales panel
                                        break;
                                    }
                                    
                                }       //switch end
                            }         //validation if end
                            else
                            {
                                 cout<<"YOU CAN ONLY PRESS (1,2,3,4,5,6,7)"<<endl;
                            }
                          
                    }   
                }              //if end - pwd checker   
                else           //else of pwd checker 
                {
                    cout<<endl;
                    cout<<"WRONG CREDENTIALS!!"<<endl;
                    cout<<endl;
                    continue;
                }          //else end
                
                
            }                 //if end-input
            
            else if (input == "2")                 //input 2 else if
            {
                welcomeprint();              //wecome sscreen
                while(true)
                {   
                    
                    buyermenu();                 //printing menu on console
                    cout << "Select what you want :" << endl;
                    cin >> buyerrequest;
                    intvalid1(buyerrequest);
                    
                    cout<<endl;

                    if(buyerrequest==7)
                    {
                        buyerexit();
                        cout<<endl;
                        break;
                    }
                    if(buyerrequest==1||buyerrequest==2||buyerrequest==3||buyerrequest==4||buyerrequest==5||buyerrequest==6)   //validation
                    {
                        switch(buyerrequest)         //for selecting one from multiple options
                        {
                            case 1:
                            {
                                listingout(arr,number_of_pdts,MAX_PDTS);           //again using the listing out function for buyer to view the products
                                break;
                            }   
                            case 2:
                            {
                                cart(arr2,no_of_orders,max);                 //function for buyer to view the cart
                                break;
                            }   
                            case 3:
                            {
                                orderplacingpanel( arr,number_of_pdts,no_of_orders, MAX_PDTS);        //displaying panel on console 
                                orderplacing(arr, MAX_PDTS,number_of_pdts, arr2, max,no_of_orders);         //function calling for buyer to place the order
                                break;
                            }   
                            case 4:
                            {
                                checkout( arr2, max,no_of_orders,totalprice);
                                break;
                            } 
                            case 5:
                            {
                                deleteorders(arr,number_of_pdts,arr2,max,no_of_orders);
                                break;
                            }
                            case 6:
                            {
                                helpsection();
                                break;
                            }
                            default:
                            {
                            cout<<"PRESSED THE WRONG KEY !"<<endl;
                            }
                        }         //switch buyer end
                    } 
                            //validation if end          
                    else
                    {
                        cout<<"you can enter (1,2,3,4,5,6) ";
                        cout<<endl;
                    }
                }
             }  
         }           //if end
        

    }
    savepdts(arr,number_of_pdts,no_of_orders, arr2,totalprice, MAX_PDTS,max);
    return 0;
}

