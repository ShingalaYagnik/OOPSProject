#include<iostream>
#include<string>
#include<conio.h>
#include <cctype>
#include<windows.h>
#include<time.h>
using namespace std;
//******************************************************************************************************************************************
//                                      FUNCTION DECLEARTION
//*******************************************************************************************************************************************
//void user();
void userMenu_2();
void mainmenu();
void admin();
void foodmenu();
void menu();
void display();
void updation();
void membership();
void display_user();
void rates();
void user();
void GoBackUser();
void signUP();
void signIn();
void addBalance();
void orderAndDelivery();
void  receipt();
void address();
void Exit();
void wait( int seconds );
void Return();                 // function for user which contain all data of customer where user can order and see the menu
//******************************************************************************************************************************************
//                                      structure declartaion and instans for foodItem
//*******************************************************************************************************************************************
struct foodItem
{
 int productId;
 string productName;
 int productPrice;
 int productquantity;

}items[15];

//******************************************************************************************************************************************
//                                       structure declartaion and instans customer regesteration
//*******************************************************************************************************************************************

struct customerRegestration
{

        char name[30];
        char addres[65];
 int balance;
 int password;
 int addBalance;

}reg[20];

//******************************************************************************************************************************************
//                                      declare global variable
//*******************************************************************************************************************************************
int pass[50];
int count=0;
int password;
int passwordu;
int extraCharges;
int counter=0;
int bills;
int DBill;
char choice;
int sum;
char yn;
int itemquantity[]={50,100,25,50,30,40,50,30,35,40};
int quantity;
//******************************************************************************************************************************************
//                                      start main
//*******************************************************************************************************************************************

// start main
int main()
{


 mainmenu();                            // mainmenu function call
 return 0;

}

//******************************************************************************************************************************************
//                                      start  main menu
//*******************************************************************************************************************************************
void mainmenu()
{


 cout<<"                       **********************"<<endl;
 cout<<"******************   WelCome to LEP Restaurant   **************"<<endl;
 cout<<"                       ************************\t\t\t\t\t"<<endl;

 cout<<"*************************************************************************"<<endl<<endl;
 cout<<"** Press a for Adminstartor         a::Admin                           **"<<endl<<endl;
 cout<<"**                                                                     **"<<endl<<endl;
 cout<<"** Press b for Customerservice      b::Customer Service                 **"<<endl<<endl;
 cout<<"**                                                                     **"<<endl<<endl;
 cout<<"** Press c  for User                c::User                            **"<<endl<<endl;
 cout<<"**                                                                     **"<<endl<<endl;
 cout<<"** Press E for  Exit                E:EXIT                             **"<<endl<<endl;
    cout<<"*************************************************************************"<<endl<<endl;
 system("color 1f");
 char choice;
 cin>>choice;

 // if (isalpha(tolower(choice)))
 {system("cls");
 system("color 9e");
 switch(choice)
  {


  case 'a' :
  system("cls");
  admin();
  Return();
  break;
  case 'b':
  system("cls");
  membership();
  Return();
  break;
  case 'c':
  system("cls");
  user();                                   //user function call
  Return();
  break;
  case 'e':
  Exit();
  break;
  default:
   {
    system("cls");
    cout<<"you enter wrong selection try again"<<endl;
    {
     mainmenu();                          //mainmenu function call
    }

   }

  }


 }

}

//******************************************************************************************************************************************
//                                      switch end main menu
//*******************************************************************************************************************************************
//******************************************************************************************************************************************
//                                    MENU DEFENATION
//*******************************************************************************************************************************************
void menu()
{
 //foodmenu funcrtion call
 foodmenu();                    //***********************************
}
//******************************************************************************************************************************************
//                                   REGESTRATION DEFENATION
//*******************************************************************************************************************************************
void membership()
{
 cout<<"-----------------------------------------------------------------------"<<endl;
 cout<<"name\t\t\taddress\t\t\t\t\tbalance"<<endl;
 cout<<"-----------------------------------------------------------------------"<<endl;
 customerRegestration info[]=

 {


  {"sheeraz Anwar     ","chak no w/b distrct vehari     "  ,0},

  {"muhammad ammar    ","beshak colony distrct vehari   "  ,0},

  {"muhammad jahazaib ","baghdad colony rahim yar khan  "  ,0},

  {"raja noman sarfaz ","depo chok rawalpindi           "  ,0},

  {"umer bhutta       ","kotli bhutta sialkot           "  ,0},

  {"bilal khokhar     ","chak no w/r multan             "  ,0},

  {"muhammad waqar    ","baghdad colony rahim yar khan  "  ,0},

  {"muhammad asadullah","university colony attock       "  ,0},

  {"usman malik       ","khorata syedan sialkot         "  ,0}

 };
 cout<<"------------------------------------------------------------------------"<<endl;
 for(int i=0;i<9;i++)
 {
  info[i].balance=200;

  cout<<info[i].name<<"\t"<<info[i].addres<<"\t"<<"\t"<<info[i].balance<<endl;

 }
 cout<<"-------------------------------------------------------------------------"<<endl;
 cout<<"-------------------------------------------------------------------------"<<endl;
 }

//******************************************************************************************************************************************
//                                      exit function defention
//*******************************************************************************************************************************************

void Exit()
//void function use  for exiting or  terminate  program

{

 system("cls");
 cout<<endl<<endl<<endl;
 wait(1);
 cout<<"\t\t\t\t------------------------ "<<endl;
 wait(2);
 cout<<"\t\t\t switching off"<<endl;
 wait(2);

}

//******************************************************************************************************************************************
//                                      wait function defenation which use for exit function
//*******************************************************************************************************************************************
void wait ( int seconds )
//this function contains void type & returns nothing


{
 clock_t waitend;
 waitend = clock () + seconds * CLOCKS_PER_SEC ;
 while (clock() < waitend) {}
}
//******************************************************************************************************************************************
//                                      return type function
//*******************************************************************************************************************************************
void Return()
{
    cout<<"do you want to goto main menu? "<<endl;
 cout<<"Yes==Y";
 cin>>choice;
 if (choice=='y' || choice=='Y')
 {  system("cls");
 mainmenu();
 }
 else
 {
  mainmenu();
 }

}

//******************************************************************************************************************************************
//                                      add balance function call
//*******************************************************************************************************************************************


void addBalance()
{
 int x=0;
 int amount;
 int balance=0;
 cout<<"enter amount=";
 cin>>amount;
 reg[count].balance=reg[count].balance+amount;
 cout<<"balance added succesfully\n";
 cout<<"your new balance ="<<balance;


}

//******************************************************************************************************************************************
//                                     user function defenation
//*******************************************************************************************************************************************
void user()

{
    cout<<"*************************************************************************"<<endl<<endl;
    cout<<"** press a for signup user             a::signup                       **"<<endl<<endl;
    cout<<"**                                                                     **"<<endl<<endl;
    cout<<"** press b for signin user             b::user sign                    **"<<endl<<endl;
    cout<<"**                                                                     **"<<endl<<endl;
    cout<<"** press c  for sign out               c::signout                      **"<<endl<<endl;
    cout<<"**                                                                     **"<<endl<<endl;
    cout<<"** press E for  return                 E:return                        **"<<endl<<endl;
    cout<<"*************************************************************************"<<endl<<endl;
 cin>>choice;
     if (isalpha(tolower(choice)))
    {

     switch(choice)

     {
     case 'a':

      system("cls");

      signUP();


      user();

      break;

     case 'b':

      signIn();
      system("cls");

      //GoBackUser();
      Return();
      break;
      case 'c':
      system("cls");
      main();                    //main function call
      break;
      case 'e':                     //this function use  for exit
      Return();
      break;
      default:
      system("cls");
      cout<<"wrong entry"<<endl;
      user();

     }
    }else
    {
     system("cls");

     cout<<"you enter wrong input try again"<<endl;
     user();
    }
}

//******************************************************************************************************************************************
//                                      sign up  function defenation
//*******************************************************************************************************************************************
void signUP()
{
 count++;
 cout<<"enter full name"<<endl;
 cin>>reg[count].name;
 cout<<"enter ur password"<<endl;
 cin>>reg[count].password;
 cout<<"enter ur addres"<<endl;
 cin>>reg[count].addres;
 cout<<"please add balance"<<endl;
 cin>>reg[count].addBalance;

 // cout<<"enter ur balance"<<endl;
 // cin>>reg[count].balance;

 cout<<"enter balnce"<<"=\n";
 cin>>reg[counter].balance;

 cout<<endl;

    reg[count].balance +=200;

}

//******************************************************************************************************************************************
//                                     sign in function
//*******************************************************************************************************************************************

/*void signIn()
{
 int x=0;
 char yn='y';
 int balance=0;
 int password=0;
 cout<<"plese enter ur password ="<<endl;
 cin>>passwordu;

 //string nam;
 //cout<<"Enter name"<<endl;
 // getline (cin, nam, '.');

 for(int m=1;m<=count;m++)
 {


  if(passwordu=reg[m].password)
  {
   x=1 ;
  }
  else
  {
   if(passwordu=reg[m].password)
   {
    x=2;
   }
  }


  //else

}
 if(x=2)
 {
  user();
 }
 else
 {
  if(x=1)
  {
   signIn();
  }
 }

 cout<<"welcome to dear customer\t\t\t\t\t\t\t\t\t\t\t\t";
 {
  display();
 }
 cout<<"do u want make an order"<<endl;
 {
  orderAndDelivery();
 }

 address();


}*/void signIn()
 {


   char yn='y';
  int balance=0;
  cout<<"plese enter ur password"<<"="<<endl;
  cin>>password;
 cout<<endl;

  //string nam;
  //cout<<"Enter name"<<endl;
 // getline (cin, nam, '.');

 if(password==reg[count].password )
   {
 cout<<"welcome to dear customer\t\t\t\t\t\t\t\t\t\t\t\t";
{
display();
}
 cout<<"do u want make an order"<<endl;
 {
  orderAndDelivery();
 }

 address();


 }else{
  signIn();
 }


 }

//******************************************************************************************************************************************
//                                     order function defenation
//*******************************************************************************************************************************************

void orderAndDelivery()
{

 int order=0;

 int blnce=0;


 int productchoice=0;

 int distination=0;

 int homeDelivery=0;
 int distance =0;
 cout<<"do u want make an  order (Y/N)?\n";
        cin>>yn;
 cout<<"what do you want sir please check the menu\t\t\t"<<endl;
 cout<<"how many product you want"<<endl;
 cin>>productchoice;
        cout<<endl;
 cout<<"please enter productId"<<endl;
 cin>>order;
 sum= items[order].productPrice*productchoice;
        cout<<items[order].productPrice<<endl;
 cout<<"sir your total bill is "<<endl;
 cout<<sum<<endl;
 address();                           cout<<"do u want to order more"<<endl;
 cin>>yn;
 if(yn=='y'||yn=='Y')
 {

  orderAndDelivery();
 } else{

  mainmenu();
 }
 }

//******************************************************************************************************************************************
//                                 start    administartor function defenation and admin work
//*******************************************************************************************************************************************

void admin()
{

 string adminName ="usmanmalik";

    string administratorName;

    string name;


    string adminPassword="malik786";


    string password;

                cout<<"Please Enter Your AdminName : ";
    cin>>adminName;
    cout<<endl;
    cout<<"Please Enter your Passsword :";
    cin>>password;


    if(password==adminPassword && name==administratorName  )
    {
cout<<"*************************************************************************"<<endl<<endl;
     cout<<"** Press a for Foodmenu             a::Foodmenu                        **"<<endl<<endl;
     cout<<"**                                                                     **"<<endl<<endl;
     cout<<"** Press b for Display              b::Display                         **"<<endl<<endl;
     cout<<"**                                                                     **"<<endl<<endl;
     cout<<"** Press c  for Membership          c::Membership                      **"<<endl<<endl;
     cout<<"**                                                                     **"<<endl<<endl;
     cout<<"** Press E for  Return              E:Return                           **"<<endl<<endl;
     cout<<"**                                                                     **"<<endl<<endl;
     cout<<"** Press d Display User             d::Display user                    **"<<endl<<endl;
     cout<<"*************************************************************************"<<endl<<endl;
     cin>>choice;
     if (isalpha(tolower(choice)))
     {


      //******************************************************************************************************************************************
      //                                      start switch and cases
      //*******************************************************************************************************************************************
     switch(choice)
      {

      case 'a':

       foodmenu();
              system("cls");
            //mainmenu();
             break;
            case 'b':
       system("cls");
       display();
     char y;
       cout<<"Do u want to go back to "<<endl;
       cin>>y;
       if(y=='y'||y=='Y')
       {
        admin();                                              //admin function call
       }
       else{

        Return();

       }
       break;

      case 'c':

       membership();

       // regestration();                                     //regesteration function call


       cout<<"Do u want to go back to"<<endl;
       cin>>yn;
       if(yn=='y'||yn=='Y')
       {
        admin();                                        // admin function call
       }
       else
       {
        Return();

       }

      break;
      case 'e':                                                 // e for exit
       //Return();
                   Return();
                    break;
      case 'd':
                              system("cls");

        display_user();
                                                                 Return();
                                                                default:
       {
        system("cls");
        cout<<"Wrong input try again"<<endl;
        admin();
       }
      }
      cout<<"Do u want to continue y/n "<<endl;
      cin>>choice;

      if(choice=='y'||choice =='Y')
      {

      mainmenu();
      }


     }

 }
 else
 {
  cout<<"Invalid Input"<<endl;
  admin();
 }


 }

//******************************************************************************************************************************************
 //                                      fooditem functionn defenation
 //*******************************************************************************************************************************************

 void foodmenu()
 {

  do
  {
   counter++;
   items[counter].productId=counter;
   cout<<"Enter Product ID"<<endl;
   cin>>items[counter].productId;
   cout<<"Enter Product Name"<<endl;
   getline(cin,items[counter].productName,'.');
   items[counter].productPrice=counter;

   cout<<"Enter product price"<<endl;
   cin>>items[counter].productPrice;

   items[counter].productquantity=counter;

   cout<<"Enter Product Quantity"<<endl;
   cin>>items[counter].productquantity;

   cout<<"Do u want add more"<<endl;
   cin>>choice;
  }while(choice=='y' || choice=='Y');
  admin();

}


 //******************************************************************************************************************************************
 //                                      foodmenu display function
 //*******************************************************************************************************************************************


 void display_user()
 {

  //cout<<"itemId\t\tname\t\tprice\t\tquantity"<<endl;
  for(int u=1;u<count;u++)
  {
   cout<<reg[u].name<<"\t\t"<<reg[u].password<<endl<<"\t\t"<<reg[u].addres<<"\t\t"<<reg[u].addBalance<<"\t\t"<<reg[u].balance<<endl;

  }
 }

 //******************************************************************************************************************************************
 //                                      foodmenu display function
 //*******************************************************************************************************************************************

 void display()
 {

  cout<<"itemId\t\tname\t\tprice\t\tquantity"<<endl;
  for(int k=1;k<counter;k++)
  {


   cout<<"***_________________________________________________________________________________***"<<endl;
   cout<<"***_________________________________________________________________________________***"<<endl;
   cout<<items[k].productId<<"\t\t"<<items[k].productName.substr(1,items[k].productName.length())<<"\t\t"<<items[k].productPrice<<"\t\t"<<items[k].productquantity<<endl;


  }
 }

 void GoBackUser()

 {
  signIn();
 }

        void receipt()

 {

  cout<<"******************************************************"<<endl;
  cout<<"****         calculation  bills                  ****"<<endl;
  cout<<"******************************************************"<<endl;
  cout<<endl;
  {
   cout<<"-------------------------------------------------------"<<endl;
   cout<<"------------------------------------------------------"<<endl;
  }
  cout<<"Deliver charge ="<<extraCharges<<endl;
  cout<<"Charge with out Delivery"<<sum<<endl;
  cout<<"Total charge ="<<DBill<<endl;
  cout<<"THANKX FOR SHOPPING "<<endl;


 }

 /* --------------------------------------------------------------------------------------------------------*/

 void address(void)
 {


  int tem_bill=0;
  int selection;
  char restaurantDes;
  string sector;
  DBill=sum;

  int sector_distance=0;

  cout<<"We Deliver only in Islambad"<<endl;

  cout<<"Restaurant Distination i8 Markaz"<<endl;
  cin>>restaurantDes;
  int  Distance[12]={10,14,15,21,25,28,30,33,35,40,42,44};
  cout<<"We Deliver in these sectors"<<endl;
  cout<<"press 1 for sector  i8 "<<endl;
  cout<<"press 2 for sector  i9 "<<endl;
  cout<<"press 3 for sector  i10"<<endl;
  cout<<"press 4 for sector  i11"<<endl;
  cout<<"press 5 for sector  g8 "<<endl;
  cout<<"press 6 for sector  g9 "<<endl;
  cout<<"press 7 for sector  g10"<<endl;
  cout<<"press 8 for sector  g11"<<endl;
  cout<<"press 9 for sector  f8 "<<endl;
  cout<<"press 10 for sector f9 "<<endl;
  cout<<"press 11 for sector f10"<<endl;
  cout<<"press 12 for sector f11"<<endl;
  cout<<"Select your sector "<<endl;
  cin>>selection;
  sector_distance=Distance[selection]-20;
  if(Distance[selection-1]>20)
  {
   extraCharges=sector_distance*2;
   DBill=DBill+extraCharges;
   receipt();
  }
  else
  {
   receipt();
  }


 }
