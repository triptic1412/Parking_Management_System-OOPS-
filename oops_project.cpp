#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>

using namespace std;
int id =1;

class Floor{
public:

    int visited[11][11];  

    int number_of_vehicles ;
    Floor(){
        for(int i=1;i<=10;i++){   
            for(int j=1;j<=10;j++){   
                visited[i][j]=0;
            }
        }
        number_of_vehicles=0;
    }
};

class building{
public:
    string bname;
    Floor f1,f2,f3;

    building(string bname){
        this->bname = bname;
    }

    string getname(){
        return bname;
    }
};


class location{
public:
    Floor Floor_no;
    int x;
    int y;

};

class vehicle{
public:
    int type_of_vehicle;
    //string name;
    long long phone_no;
    string vehicle_no;
    bool is_self_drive;
    int duration;
    int charges;
    location of_this_vehicle;
    int id_no;
      
    


    
    vehicle(int type_of_vehicle,long long phone_no,string vehicle_no,bool is_self_drive,int duration){
    
        this->type_of_vehicle = type_of_vehicle;
        //this->name = name;
        this->phone_no = phone_no;   
        this->vehicle_no = vehicle_no;    
        this->is_self_drive=is_self_drive;    
        this->duration = duration;

        if(type_of_vehicle==2){

            this->charges = duration*15;
        }

        else{

            this->charges = duration*30;

        }
        this->id_no = id; // ID Declared globally so that it can be revolved througout the program
    }

    void get_E_slip(){
        cout<<endl<<"\t\t\t\t\t\t\t\t**** E-Slip ****"<<endl;
        cout<<"\t\t\t======================================================================================"<<endl;
        //cout<<"\t\t\t\t         Name                : "<<name<<endl;
        cout<<"\t\t\t\t         Vehicle Number      : "<<vehicle_no<<endl;
        cout<<"\t\t\t\t         Phone Number        : "<<phone_no<<endl;
        cout<<"\t\t\t\t         Duration of Parking : "<<duration<<" Hours"<<endl;
        cout<<"\t\t\t\t         Charges             : "<<charges<<endl;
        cout<<"\t\t\t\t         Id                  : "<<id_no<<endl;
        cout<<"\t\t\t\t         Location of Vehicle : ";

        if(type_of_vehicle==2){
            cout<<"1st ";
        }

        else if(type_of_vehicle==4){

            if(is_self_drive){
                    cout<<"2nd ";
                }

            else{
                cout<<"3rd ";
            }
        }
        cout<<"floor, ";
        cout<<"Coordinates are ("<<of_this_vehicle.x<<","<<of_this_vehicle.y<<")"<<endl;
        cout<<"\t\t\t======================================================================================"<<endl<<endl;
    }
};

location getlocation(Floor &datum){ //by reference becoz so that we can change the values of componenets of object datum
    location now ;
    now.Floor_no = datum;
    int flag = 0;

    for(int i=1; i<=10 && flag==0; i++){  
        for(int j=1;j<=10 && flag==0;j++){   
            if(datum.visited[i][j]!=0){
                continue;
            }

            else{
                datum.visited[i][j]=id;
                now.x = i;
                now.y = j;
                flag=1;
            }
        }
    }
    return now;
}

class administrator : public vehicle{
private:
    string password;

public:
    void set_password(){
        string s;

        for(int i=0;i<vehicle_no.size();i++){
            s.push_back(vehicle_no[vehicle_no.size()-1-i]);
            //password is opposite of the vehichle_no
        }
        password=s;
    }

    administrator(int type_of_vehicle,long long phone_no,string vehicle_no,bool is_self_drive,int duration):
    vehicle(type_of_vehicle,  phone_no, vehicle_no,is_self_drive, duration)
    {}

    void display_admin(){
        cout<<"\t\t\tEnter Pass key of this Vehicle : ";
        string pass_key;
        cin>>pass_key;
        if(pass_key==password)
        {
            cout<<endl<<"\t\t\t\t     ** DETAILS OF THE VEHICLE **   "<<endl;
            cout<<"\t\t==========================================================================="<<endl;
            //cout<<"\t\t\t    Name                : "<<name<<endl;
            cout<<"\t\t\t    Vehicle No          : "<<vehicle_no<<endl;
            cout<<"\t\t\t    Phone No            : "<<phone_no<<endl;
            cout<<"\t\t\t    Duration of Parking : "<<duration<<" Hours"<<endl;
            cout<<"\t\t==========================================================================="<<endl<<endl;;
        }
        else{
            cout<<"\n\t\t\t\t*** INVALID PASS KEY ***"<<endl;
        }
    }
};

void display(Floor W){
    cout<<endl;
    for(int i=1;i<=10;i++){ 
        cout<<"\t\t\t\t";   
        for(int j=1;j<=10;j++){  
            cout<<W.visited[i][j]<<"  ";
        }
        cout<<endl;
        }
    cout<<endl;
}

int main(){
    system("clear"); ////////////////////////////////////////////////////////////////////////////////////////



    cout<<endl;
    cout<<"\t\t\t=========================================================================================================================\n";
    cout<<"\t\t\t\t\t\t* * * *      *       * * * *   *     *  * * * *  **      *   * * *  \n";
    cout<<"\t\t\t\t\t\t*      *    * *      *      *  *    *      *     * *     *  *     * \n";
    cout<<"\t\t\t\t\t\t*      *   *   *     *      *  *   *       *     *  *    *  *       \n";
    cout<<"\t\t\t\t\t\t* * * *   * * * *    * * * *   * **        *     *   *   *  *   *** \n";
    cout<<"\t\t\t\t\t\t*        *       *   *  *      *   *       *     *    *  *  *     * \n";
    cout<<"\t\t\t\t\t\t*       *         *  *    *    *    *      *     *     * *  *     * \n";
    cout<<"\t\t\t\t\t\t*      *           * *      *  *     *  * * * *  *      **   * * *  \n";
    cout<<endl;



    cout<<"\t\t\t\t**     **       *       **      *       *        * * *   * * * *  **     **  * * * *  **      *  * * * * * \n";
    cout<<"\t\t\t\t* *   * *      * *      * *     *      * *      *     *  *        * *   * *  *        * *     *      *     \n";
    cout<<"\t\t\t\t*  * *  *     *   *     *  *    *     *   *     *        *        *  * *  *  *        *  *    *      *     \n";
    cout<<"\t\t\t\t*   *   *    * * * *    *   *   *    * * * *    *   ***  * * * *  *   *   *  * * * *  *   *   *      *     \n";
    cout<<"\t\t\t\t*       *   *       *   *    *  *   *       *   *     *  *        *       *  *        *    *  *      *     \n";
    cout<<"\t\t\t\t*       *  *         *  *     * *  *         *  *     *  *        *       *  *        *     * *      *     \n";
    cout<<"\t\t\t\t*       * *           * *      ** *           *  * * *   * * * *  *       *  * * * *  *      **      *     \n";
    cout<<endl;



    cout<<"\t\t\t\t\t\t  * * *   *       *   * * *   * * * * *  * * * *  **     **\n";
    cout<<"\t\t\t\t\t\t*      *   *     *  *      *      *      *        * *   * *\n";
    cout<<"\t\t\t\t\t\t*           *   *   *             *      *        *  * *  *\n";
    cout<<"\t\t\t\t\t\t * * * *     * *     * * * *      *      * * * *  *   *   *\n";
    cout<<"\t\t\t\t\t\t        *     *             *     *      *        *       *\n";
    cout<<"\t\t\t\t\t\t *      *     *      *      *     *      *        *       *\n";
    cout<<"\t\t\t\t\t\t  * * *       *       * * *       *      * * * *  *       *\n";
    cout<<"\t\t\t=========================================================================================================================\n";
    cout<<endl;


    ofstream fout;
    ifstream fin;
    cout<<"\n\t\t\tEnter name of your Building : ";
    string bname;
    cin>>bname;
    building A(bname);
    int total_no_of_vehicle=0;
    vector<administrator> a;

    for(int i=0;i<32;i++)
    {
        administrator ad(0,0,"a",false, 0);

        a.push_back(ad);
    }

    int count_selfdriven_vehicle=0;
    int count_4wheeler_vehicle=0;
    int count_2wheeler_vehicle=0;
    int f=0;

        //USER INTERFACE
        do
        {
            cout<<endl<<"\t\t\tPlease select an option to proceed further"<<endl;
            cout<<"\t\t\t  1. Park a Vehicle"<<endl;  ///
            cout<<"\t\t\t  2. Exit the Parking"<<endl;
            cout<<"\t\t\t  3. Go to Admin Rights"<<endl;
            cout<<"\t\t\t  4. Exit the SYSTEM"<<endl;
            cout<<endl<<"\t\t\tEnter your choice : ";
            int t;
            cin>>t;
            cout<<endl;


            if(t==4){    //////
                fout.open("Database.txt",ios::app);
                fout<<"-----------------------------------------------------------------------------------------";
                fout.close();
                cout<<"\t\t\t======================================================================"<<endl;
                cout<<"\t\t\t\t\t  *** THANK YOU FOR YOUR COOPERATION ****"<<endl<<"\t\t\t\t\t\t **** HAVE A NICE DAY ****"<<endl;
                cout<<"\t\t\t======================================================================"<<endl<<endl;
                return 0;
            }

            if(t==3)
            {
                cout<<"\t\t\t**** YOU ARE IN ADMIN SECTION ***"<<endl;
                
                char pass_to_admin[5];
                //cin>>pass_to_admin;
                //string ch;
                /*for(int i=0;i<4;i++)
                {
                    ch = getch();
                    pass_to_admin[i]=ch;
                    cout<<"*";

                }*/
                
                int g = 3;
                //pass_to_admin[4]='\0';
                while(g--){
                    cout<<"\n\t\t\tENTER PASSWORD : ";
                    cin >> pass_to_admin;
                    cout<<endl;
                    
                    if(strcmp(pass_to_admin,"n007")==0)
                    {
                        cout<<"\t\t\t\t\t*** ACCESS GRANTED ***"<<endl;
                        cout<<"\t\t\tPress 1 to get Floor details / Press 2 to get Vehicle details: ";
                        int q;
                        cin>>q;
    
                        if(q==1)
                        {   cout<<"\n\t\t\t\t\t 1st Floor";
                            display(A.f1);
                            cout<<"\t\t\t\t\t 2nd Floor";
                            display(A.f2);
                            cout<<"\t\t\t\t\t 3rd Floor";
                            display(A.f3);
                        }
    
                        else if(q==2)
                        {
                            cout<<"\t\t\tEnter VEHICLE NO. of the Vehicle : ";
                            string vehicle_number_check;
                            cin>>vehicle_number_check;
                            
                            for(int i=1;i<id;i++)
                            {
                             if(a[i].vehicle_no==vehicle_number_check)
                             {
                                 a[i].display_admin();
                             }
                            /*else{
                                cout<<"\n\t** INCORRECT DETAILS **"<<endl;
                            }*/   
                            }
                         /*if(i==id){
                            cout<<"** INCORRECT DETAILS **"<<endl<<endl;
                        }*/
                        }
                        
                        else{

                            cout<<"\t\t\t\t\t** INVALID CHOICE **"<<endl;
                            cout<<"\t\t\t\t\tPlease select out of the given options"<<endl;///////////////////////////////////
                        }
                        break;
                    }

                    else
                    {
                        cout<<"\t\t\t\t** INCORRECT PASSWORD **"<<endl;
                        cout<<"\t\t\t\tYou have "<<g<<" chance left"<<endl;
                        if(g==0){
                            cout<<"\n\t\t\t\t\t\t==================================================";
                            cout<<"\n\t\t\t\t\t\t**************************************************";
                            cout<<"\n\t\t\t\t\t\t\t\tSystem is shutting down";
                            cout<<"\n\t\t\t\t\t\t**************************************************";
                            cout<<"\n\t\t\t\t\t\t=================================================="<<endl<<endl;
                            exit(1);
                        }
                    }
                
                }
            continue;
        }

        else if(t==2)
        {
            cout<<"\t\t\tEnter your Vehicle ID_NO : ";
            int id_check;
            cin>>id_check;
            int i;
            for(i=1;i<=10;i++)   
            {
                for(int j=1;j<=10;j++)    
                {
                    if(A.f1.visited[i][j]==id_check)
                    {
                        A.f1.visited[i][j]=0;
                        cout<<"\n\t\t\t\t\t   Thanks For Parking at "<<A.getname()<<endl;
                        cout<<"\t\t\t\t\t********* Have a Nice Day *********"<<endl<<endl;
                    }
                    else if(A.f2.visited[i][j]==id_check)
                    {
                        A.f2.visited[i][j]=0;
                        cout<<"\n\t\t\t\t\t   Thanks For Parking at "<<A.getname()<<endl;
                        cout<<"\t\t\t\t\t********* Have a Nice Day *********"<<endl<<endl;
                    }
                    else if(A.f3.visited[i][j]==id_check)
                    {
                        A.f3.visited[i][j]=0;
                        cout<<"\n\t\t\t\t\t   Thanks For Parking at "<<A.getname()<<endl;
                        cout<<"\t\t\t\t\t********* Have a Nice Day *********"<<endl<<endl;
                    }
                    //else{
                   //     cout<<"\t\t\t\t****NO SUCH VEHICLE EXISTS****"<<endl;
                    //}
                }
            }
            /*if(i==11){
                        cout<<"\t\t\t\t**** NO SUCH VEHICLE ID EXISTS ****"<<endl;
                    }*/
            /*cout<<"\n\t\t\t\t   Thanks For Parking at "<<A.getname()<<endl;
            cout<<"\t\t\t\t********* Have a Nice Day *********"<<endl<<endl;*/
            continue;
        }


        else if(t==1){
            total_no_of_vehicle++;
            int type_of_vehicle;
            long long  phone_no;
        //string name;
            string vehicle_no;
            bool is_self_drive;
            int duration;

            fout.open("Database.txt", ios::app); 
            //if not app(append) then it would have deleted all the previous content and not ios::out coz it woukd have erased all the data

            if(fout){
            /*cout<<"\t\t\tEnter your name: ";
            cin>>name;
            a[id].name = name;*/
                cout<<endl<<"\t\t\tSelect the type of your Vehicle"<<endl;
                cout<<"\t\t\tPress 2 for 2 WHEELER / Press 4 for 4 WHEELER : ";
                cin>>type_of_vehicle;

                if(type_of_vehicle==4)
                {
                    cout<<endl<<"\t\t\tIs your Car Self-Driven ?"<<endl<<"\t\t\tPress 1 if Yes / Press 0 if No : ";
                    int choice;
                    cin>>choice;

                    if(choice==1)
                        is_self_drive=true;

                    else
                        is_self_drive=false;

                /*else
                cout<<"\n\t\t\t\t\t*** Please press for a viable option ***"<<endl;*////////////////////////////////////////////////
                }
                else if(type_of_vehicle==2)
                {
                    is_self_drive = false;
                }

            /*else{
                cout<<"\n\t\t\t\t\t*** Please press for a viable option ***"<<endl; //////////////////////////////////////////////////
            }*/

                if(type_of_vehicle==2 && A.f1.number_of_vehicles == 100)
                {
                    cout<<"\t\t\t** NO MORE PARKING SPACE **"<<endl;
                    continue;
                }

                else if(type_of_vehicle==4 && is_self_drive && A.f2.number_of_vehicles == 100) ////
                {
                    cout<<"\t\t\t** NO MORE PARKING SPACE **"<<endl;
                    continue;
                }

                else if(type_of_vehicle == 4 && A.f3.number_of_vehicles == 100)  /////
                {
                    cout<<"\t\t\t** NO MORE PARKING SPACE **"<<endl;
                    continue;
                }

                else /////
                {
                    cout<<endl<<"\t\t\tEnter the Required Details"<<endl;
                    cout<<"\t\t\t    Enter Phone Number : ";
                    cin>>phone_no;
                    a[id].phone_no = phone_no;

                    fout<<endl<<"\t\t\t"<<phone_no<<"\t\t\t  ";

                    cout<<"\t\t\t    Enter Vehicle_no : ";
                    cin>>vehicle_no;
                    a[id].vehicle_no = vehicle_no;
                    fout<<vehicle_no<<"\t\t\t\t";

                    cout<<"\t\t\t    Enter Duration of Parking in hours : ";
                    cin>>duration;
                    a[id].duration = duration;

                    fout<<duration<<"\t\t\t\t\t   ";
                    a[id].set_password();

                    fout<<id<<"\t\t\t\t\t   ";

                    vehicle v(type_of_vehicle, phone_no,vehicle_no, is_self_drive, duration);
                //it will help us reallocate the space as it will search for 0 only // first available parking lot and it will return its location
                    if(type_of_vehicle == 2)
                    {   
                        //floor - a.f1
                        count_2wheeler_vehicle++;
                        v.of_this_vehicle = getlocation(A.f1);
                    }

                    else if(type_of_vehicle==4 && is_self_drive)
                    {
                        count_selfdriven_vehicle++;
                        v.of_this_vehicle = getlocation(A.f2);
                    }

                    else
                    {
                        count_4wheeler_vehicle++;
                        v.of_this_vehicle = getlocation(A.f3);
                    }

                    v.get_E_slip();
                    id++;
                }
                fout.close();
            }
        }

        else{
            cout<<"\t\t\t\t\t** INVALID CHOICE **"<<endl;
            cout<<"\t\t\t\tPlease select out of the given options"<<endl;
        }
    }
    while(f==0); 
    return 0;
}
