#include<bits/stdc++.h>
#include<windows.h>

using namespace std;
int Amount=0;

//MAINPAGE CLASS INCLUDING FIRST SCREEN

class firstpage{
private:

//PRIVATE CHOICE_FIRSTPAGE FOR ENTERING USER SEC OR ADMIN SEC OR EXIT
//1,2,3 OPTION RESP

    char choice_firstPage='0';
public:

//PUBLIC FUNCTIONS HOME,SCANCHOICE OF FIRST PAGE
//GETCHOICE

    //HOME(FIRST PAGE)
    void home(){
        cout<<"WELCOME TO FOODOHOLIC"<<endl;
        cout<<"1.User               "<<endl;
        cout<<"2.Admin              "<<endl;
        cout<<"3.Exit               "<<endl;
        cout<<"4.Register User      "<<endl;
        cout<<"Enter correct choice: "<<endl;
        //CALLING OBJECT FUNCTION INSIDE ANOTHER OBJECT FUNCTION
        this->scanchoice();
    }


    void scanchoice(){
        char choice;
        cin>>choice;
        while(choice !='1' && choice!='2' && choice!='3' && choice!='4'){
            system("CLS");
            this->home();
            cout<<"Enter correct option: ";
            cin>>choice;
            cout<<endl;
        }
        this->choice_firstPage=choice;
    }


    char getchoice(){
    return this->choice_firstPage;
    }

};

class driver{
private:
    int DriverId;

    string DriverName;
    bool status=true;//free
public:
    static int driverCounter;


    driver(){

        DriverId=driverCounter;
        setDrivername();
        driverCounter++;
    }
    bool isFree(){
        return status;
    }

    int getDriverid(){
        return DriverId;
    }
    void setDrivername(){
        driverName:
        system("CLS");
    cout<<"Enter Driver Name: ";
    string dname;
    cin>>dname;
    if(dname.length()<6){
    cout<<"Short Name"<<endl;
        goto driverName;
    }

    this->DriverName=dname;
    }

    string getDriverName(){
        return DriverName;
    }

    void showdriver(){
        cout<<"Driver Id: "<<DriverId<<endl;
        cout<<"Driver Name: "<<DriverName<<endl;
        cout<<"Is Free Status: "<<(status?"Free":"Not Free")<<endl;

    }

    void togglestatus(){
    if(status){
        status=false;
        return;
    }
    status=true;

    }


};

int driver::driverCounter;
vector<driver> DriverVector;

int Ucounter(){
        ifstream ip;
        int counterUser=0;
        ip.open("userCredintial.txt");
        //char ch;
        string line;
        getline(ip,line);

        while(!ip.eof()){
            //cout<<line<<endl;
            counterUser++;
            getline(ip,line);
        }



        ip.close();
        return counterUser;
    }

class User{
public:
    string userpassword;
    string username;
    string userAddress;

    string getUser(){
        system("CLS");
        cout<<"Enter Username: ";
        cin>>username;
        cout<<endl<<"Enter User Password: "<<endl;
        cin>>userpassword;
        string colon=":",userline;//="yagnik:pass";
        userline=userline+username;
        userline=userline+colon;
        userline=userline+userpassword;


    //userfromlist(userline);
    return userline;
    }



    int userfromlist(string userline){
        ifstream ip;
        ip.open("userCredintial.txt");
        //char ch;
        int flag=0;
        string line;
        getline(ip,line);

        while(!ip.eof()){
            //cout<<line<<endl;
            if(line==userline){
                cout<<"User Verified..."<<endl;
                flag=1;
                break;
            }
            getline(ip,line);
        }
            if(flag==0){

                cout<<"You entered incorrect username or password"<<endl;
                Sleep(500);
            }


        ip.close();
        return flag;
    }

    virtual void Welcome(){
    cout<<"Welcome "<<username<<endl;
    Sleep(1000);
    }




};

class userMenu:public User{
public:
    friend class Admin;
    virtual void Welcome(){
    cout<<"Welcome "<<username<<endl;
    Sleep(1000);
    }
    int menu[4]={};
    int cost[4]={0,50,100,15};
    int total=0;
    string menulist[4]={"","Veg burger","Dosa","tea"};
    void showMenu(){
    system("CLS");
    //userWelcome();
    cout<<"1.Veg burger"<<endl;
    cout<<"2.Dosa"<<endl;
    cout<<"3.tea"<<endl;
    cout<<"4.exit"<<endl;
    }
    int order(){

        s:
    this->showMenu();
    cout<<"Enter your order: ";
    char menuchoice;
    cin>>menuchoice;
    while(menuchoice!='1'&&menuchoice!='2'&&menuchoice!='3'&&menuchoice!='4'){
        system("CLS");
        this->showMenu();
        cout<<endl<<"Enter your valid order item: ";
        cin>>menuchoice;
    }


    if(menuchoice=='4'){
        return 0;
    }
    int menuchoiceint=int(menuchoice)-48;


    cout<<"Enter Quantity"<<endl;
    char quantity=0;
    cin>>quantity;
    while(quantity!='1'&&quantity!='2'&&quantity!='3'&& quantity!='4'&&quantity!='5'){
        cout<<endl<<"Enter a valid quantity: ";
        cin>>quantity;
    }
    int quantitya=int(quantity)-48;
    menu[menuchoiceint]+=quantitya;

    system("CLS");
    cout<<"1.order more"<<endl;
    cout<<"2.exit"<<endl;
    char car;
    cout<<"Enter a option: ";
    cin>>car;
    while(car!='1'&&car!='2'){
        cout<<endl<<"You entered invalid number enter valid one: ";
        cin>>car;
    }
    if(car=='1'){
        goto s;
    }

        //PRint bill
            cout<<"User Name"<<username<<endl;
            cout<<"Item                        "<<"Quantity                   "<<"Cost"<<endl;
            for(int i=1;i<=3;i++){
                if(menu[i]!=0){
                    cout<<menulist[i]<<"               "<<menu[i]<<"                 "<<cost[i]*menu[i]<<endl;
                    total+=cost[i]*menu[i];
                }

            }
            cout<<"Total Cost: "<<total<<endl;
            Sleep(2000);
            return total;


    }
};

    int Acounter(){
        ifstream ip;
        ip.open("AdminCredintial.txt");
        //char ch;
        int counterAdmin=0;
        string line;
        getline(ip,line);

        while(!ip.eof()){
            counterAdmin++;
            cout<<counterAdmin<<line<<endl;
            getline(ip,line);
        }

        ip.close();
        return counterAdmin;
    }

class Admin{
public:
    friend int Acounter();
    friend int Ucounter();
    string Adminpassword;
    string Adminname;
    string AdminAddress;

    string getAdmin(){
        system("CLS");
        cout<<"Enter Adminname: ";
        cin>>Adminname;
        cout<<endl<<"Enter Admin Password: "<<endl;
        cin>>Adminpassword;
        string colon=":",Adminline;//="yagnik:pass";
        Adminline=Adminline+Adminname;
        Adminline=Adminline+colon;
        Adminline=Adminline+Adminpassword;

        //adminfromList(Adminline);
        return Adminline;
    }
    bool adminfromList(string Adminline){
        ifstream ip;
        ip.open("AdminCredintial.txt");
        //char ch;
        bool flag=false;
        string line;
        getline(ip,line);

        while(!ip.eof()){
            //cout<<line<<endl;
            if(line==Adminline){
                cout<<"Welcome Admin Sir..."<<endl;
                flag=true;
                break;
            }
            getline(ip,line);
        }
            if(!flag){
                cout<<"You entered incorrect username or password"<<endl;
            }


        ip.close();
        return flag;
    }




    void Welcome(){
    cout<<"Welcome "<<Adminname<<endl;
    Sleep(1000);
    }

    void showMenu(){
        system("CLS");
        cout<<"1.Drivers available."<<endl;
        cout<<"2.Add driver"<<endl;
        cout<<"3.Count User"<<endl;
        cout<<"4.Count Admin"<<endl;
        cout<<"5.Exit"<<endl;
    }

    void AdminMenu(){

        sa:
        this->showMenu();
    cout<<"Enter your option: ";
    char op;
    cin>>op;
    while(op!='1'&&op!='2'&&op!='3'&&op!='4'&&op!='5'){
        system("CLS");
        this->showMenu();
        cout<<endl<<"Enter your valid option: ";
        cin>>op;
    }


    if(op=='5'){
        exit(15);
    }else if(op=='1'){
        show:
        system("CLS");
        vector<driver>::iterator drive=DriverVector.begin();
        int i=0;
        int n=DriverVector.size();


        while(i<n){
            DriverVector[i].showdriver();
            i++;
        }
        cout<<endl<<endl;
        cout<<"Enter 1 to toggle driver status "<<endl;
        cout<<"Enter 2 to continue"<<endl;
        char tog;
        cin>>tog;
        while(tog!='1'&&tog!='2'){
            cout<<"Enter a valid option";
            cin>>tog;
        }
        if(tog=='1'){
            cout<<"Enter Driver Id"<<endl;
            int id;
            cin>>id;
            while(id>=n && id <0){
                cout<<"Enter a valid id";
                cin>>id;
            }
            DriverVector[id].togglestatus();
            system("CLS");
            goto show;

        }



    }else if(op=='2'){
        driver drivertemp;
        DriverVector.push_back(drivertemp);

    }else if(op=='3'){
        system("CLS");
        cout<<"User Count: "<<Ucounter();
        Sleep(1000);
    }else if(op=='4'){
        system("CLS");
        cout<<"Admin Count: "<<Acounter();
        Sleep(1000);
    }



    int opint=int(op)-48;
    system("CLS");
    cout<<"1.Stay on admin page:"<<endl;
    cout<<"2.exit"<<endl;
    char car;
    cout<<"Enter a option: ";
    cin>>car;
    while(car!='1'&&car!='2'){
        cout<<endl<<"You entered invalid number, enter valid one: ";
        cin>>car;
    }
    if(car=='1'){

        goto sa;
    }

        //PRint bill


    }


};


class sample{
public:
    sample(){
    this->calling();
    }


    void calling(){
        firstpage homepage;
        homepage.home();
        char choiceAdminUser=homepage.getchoice();
        //cout<<choiceAdminUser;
        if(choiceAdminUser=='1'){
                //USERA
            userMenu usera,*userpointer=NULL;

            askagain:
            string userline=usera.getUser();
            int flag=usera.userfromlist(userline);


            if(flag==1){
                    Sleep(300);
                system("CLS");
                userpointer=&usera;
                userpointer->Welcome();
                //cout<<"count User"<<usera.counter()<<endl;
                    //usera.showMenu();
//Driver class banane hae//friend function se banane hae counter theek karne hae
//menu save kar vu che file ma
                Amount+=usera.order();

            }else{
            goto askagain;
            }
        }else if(choiceAdminUser=='2'){
            Admin admina,*adminpointer=NULL;
            asktwice:
            string adminline=admina.getAdmin();
            bool flag=admina.adminfromList(adminline);
            if(flag==true){
                Sleep(500);
                adminpointer=&admina;
                adminpointer->Welcome();
                admina.showMenu();
                admina.AdminMenu();


                //driver
                //copy constructor thi temp driver ma detaails lai ne vector ma pussback karva
                //cout<<"Admin Counter "<<admina.counter();
            }else{
            goto asktwice;
            }
        }else if(choiceAdminUser=='3'){
        exit(11);
        }else if(choiceAdminUser=='4'){
            User userb;
            string userline=userb.getUser();
            ofstream op;
            op.open("userCredintial.txt",ios::app);
            op<<userline<<endl;
            op.close();
            cout<<"Registering user";
            for(int i=0;i<5;i++){
                Sleep(100);
                cout<<"..";
            }
            cout<<endl;
            cout<<"User registered."<<endl;
        }


    }
};


/*
class counter:public Admin,public User{

};
*/

int main(){
    char ch='a';
while(ch!='e'){

    system("CLS");
    sample s;
    cout<<endl<<endl<<endl;
    system("CLS");
    cout<<"1.for new user or admin"<<endl;
    cout<<"2.exit"<<endl;
    cout<<"Enter a option: "<<endl;
    char entryexit;
    cin>>entryexit;

    while(entryexit!='1'&&entryexit!='2'){
    cout<<"Enter valid option: ";
        cin>>entryexit;
    }

    switch(entryexit){
            case '1':
                break;
            case '2':
                cout<<"saving";
                for(int i=0;i<5;i++){
                    Sleep(200);
                    cout<<"..";
                }
                exit(12);
                break;
            default:
                cout<<"You entered something out of the world:"<<endl;
        }
}

}
//kichdi
