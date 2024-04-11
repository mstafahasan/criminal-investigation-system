#include <iostream>
#include <cstring>
#include <string>


using namespace std;

int a= 1;        // number of users
int id = 0;     // id of user
int re = 0;      // number of records




struct user
{
    string user_name;
    string password;
    int id =1;
    bool Isadmin;
    int rec_num = 0;
    struct record
    {
        string criminal_name;
        int record_date;
        int age;
        string criminal_act;
    };
    record rec[25];
}r[30];





void Register(){
    cout<<char(178)<<"Enter your username:>";
    cin>>r[a].user_name;
    cout<<char(178)<<"Enter your password:>";
    cin>>r[a].password;
    cout<<endl;
    a++;
    r[a].id++;
    ( r[a].user_name == "admin" )? r[a].Isadmin = true : r[a].Isadmin = false ;
    cout<<"\t\t\t\t"<<char(178)<<"account registration accomplished successfully :) "<<char(178)<<endl;
    return;
}

int Login()
{
    string input_user_name,input_password;  
    cout<<char(178)<<"Enter user name :>";
    cin>>input_user_name;
    p:
    cout<<char(178)<<"Enter your password :>";
    cin>>input_password;
    int counter;
    for(counter=0;counter<=a;counter++)
    {
        if (input_user_name==r[counter].user_name)
            break;  
    }
    if (input_user_name != r[counter].user_name)
    {   
        cout<<"\t\t\t"<<char(178)<<" NOT found please Register >>>"<<endl;
        return 0;
    }
    else
    {
        if (input_password != r[counter].password)
        {
            cout<<"\t\t\t"<<char(178)<<" Wrong password :( "<<endl;
            goto p;
        }
    }

    if (input_password==r[counter].password&&input_user_name==r[counter].user_name)
        cout<<endl<<"\t\t\t"<<char(178)<<"valid login and Your current id :> "<<r[counter].id<<endl;   

    if ( r[counter].user_name == "admin" )
        r[counter].Isadmin = true;    
    return r[counter].id;
}

void display()
{ 
    char arr[][40] = {"1-  Register","2-  LOGIN","3-  Add new record","4-  Delete a record","5-  Display all the crimes/criminals","6-  update record","0-  EXIT"};
    cout<<endl<<endl;
    for (size_t i = 0; i < 25; i++)
    {
        cout<<char(178);
        if ( i == 10)
            cout<< " Criminal Investigation System ";
    }
    cout<<endl<<endl;
    if (id != 0)
        cout<<"\t\t\t"<<char(178)<<char(178)<<char(178)<<" Your current Id is :> "<<id<<" "<<char(178)<<char(178)<<char(178)<<endl;
    for (size_t i = 0; i < 7; i++)
    {
        cout<<endl<<"\t";
        cout<<char(178)<<arr[i]<<endl;
    }
    cout<< " Pick option 1,2,3,4,5 or 0 for exit "<<endl;
}

void add_record(int id_num)
{
    cout<<endl<<"\t\t\t"<<char(178)<<char(178)<<"....... Adding record ......."<<char(178)<<char(178)<<endl<<endl;
    cout<<char(178)<<" Enter name of criminal :> ";
    cin>>r[id_num].rec[r[id_num].rec_num].criminal_name;
    cout<<char(178)<<" Enter age of criminal :> ";
    cin>>r[id_num].rec[r[id_num].rec_num].age;
    cout<<char(178)<<" Enter date of record :> ";
    cin>>r[id_num].rec[r[id_num].rec_num].record_date;
    cout<<char(178)<<" Enter his crime :> ";
    //getline( cin , r[id_num].rec[re].criminal_act );
    cin>>r[id_num].rec[r[id_num].rec_num].criminal_act;
    cout<<endl;
    re++;
    r[id_num].rec_num++;
    cout<<endl<<"\t\t\t"<<char(178)<<char(178)<<"....... NEW Record created :) ......."<<char(178)<<char(178)<<endl<<endl;

}

void print_rec(int re_num , int id)
{
    if ( re_num > r[id].rec_num ) return; 
    cout<<endl<<"\t\t\t"<<char(178)<<char(178)<<"....... Record #" << re_num + 1<< " ......."<<char(178)<<char(178)<<endl<<endl;
    cout<<"\t"<<char(178)<<" The criminal is : "<<r[id].rec[re_num].criminal_name<<endl;
    cout<<"\t"<<char(178)<<" The criminal age is : "<<r[id].rec[re_num].age <<endl;
    cout<<"\t"<<char(178)<<" The record date is : "<<r[id].rec[re_num].record_date <<endl;
    cout<<"\t"<<char(178)<<" The crim activity is : "<<r[id].rec[re_num].criminal_act <<endl;
    cout<<endl<<"\t\t\t"<<char(178)<<char(178)<<"................................................."<<char(178)<<char(178)<<endl<<endl;
} 

void show_record(int id)
{
    int indx;
    if ( r[id].rec_num == 0 )
    {
        cout<<char(178)<<" There are 0 records belong to you create your records first  "<<endl;    
        return;
    }
    cout<<char(178)<<" There are "<<r[id].rec_num<<" records belong to you enter one index of them or enter 0 for all "<<endl;
    cin>>indx;
    if ( indx == 0 )
    {
        for (size_t i = 0; i < r[id].rec_num; i++)
            print_rec(i , id);    
    }
    else
    {
        print_rec(indx -1 , id);
    }
    return;
}

void delete_record(int id)
{
    int indx;
    cout<<endl<<"\t"<<char(178)<<char(178)<<" Enter the number of the record you want to remove :>";
    cin>>indx;
    if ( r[id].rec_num >= indx )
    {
        for (size_t i = 0; i < r[id].rec_num -1 ; i++)
        {
            if(indx -1 <= i)
                r[id].rec[i] = r[id].rec[i +1];
        }
        cout<<endl<<"\t\t\t"<<char(178)<<char(178)<<" Record removed successfully  :) ";
        r[id].rec[r[id].rec_num -1 ] = { "",0,0,"" };
        r[id].rec_num--;
    }else { cout<<endl<<"\t\t\t"<<char(178)<<char(178)<<" Invalid record number :( >>>>>>>> ";   }
}

void update_rec(int id_num, int rec_num)
{
    if ( rec_num > r[id_num].rec_num )
    {
        cout<<endl<<"\t\t\t"<<char(178)<<char(178)<<" Invalid record number :( >>>>>>>> ";    
    }
    else
    {
        cout<<endl<<"\t\t\t"<<char(178)<<char(178)<<"....... updating record ......."<<char(178)<<char(178)<<endl<<endl;
        cout<<char(178)<<" Enter name of criminal :> ";
        cin>>r[id_num].rec[rec_num -1].criminal_name;
        cout<<char(178)<<" Enter age of criminal :> ";
        cin>>r[id_num].rec[rec_num -1].age;
        cout<<char(178)<<" Enter date of record :> ";
        cin>>r[id_num].rec[rec_num -1].record_date;
        cout<<char(178)<<" Enter his crime :> ";
        //getline( cin , r[id_num].rec[re].criminal_act );
        cin>>r[id].rec[rec_num -1].criminal_act;
        cout<<endl<<endl<<"\t\t\t"<<char(178)<<char(178)<<"....... Record updated ......."<<char(178)<<char(178)<<endl<<endl;
    }
}

void search_record_for_admin (){
    string input_name;
    int treu=0;
    cout<<" Entre name of crimminal"<<endl;
    cin>>input_name;
    for (int s=0;s<=a;s++)
    {
        for (int w=0;w<= r[a].rec_num ;w++)
        {  
            if (input_name==r[s].rec[w].criminal_name)
            {
                print_rec(w,s);
                treu++;
            }
        }
    }
    if (treu==0)
    {
        cout<<endl<<"\t\t\t"<<char(178)<<char(178)<<" No crimminal found with this name ";
    }
}

int admin_display ()
{ 
    char arr[][40] = {"1- show all records","2-  show all crminals","3-  show records by name of criminal","0-  EXIT"};
    cout<<endl<<endl;
    for (size_t l = 0; l < 25; l++)
    {
        cout<<char(178);
        if ( l == 10)
            cout<< " Criminal Investigation System ";
    }
    cout<<endl<<endl;
    cout<<endl<<"\t\t\t"<<char(178)<< "You are an admin now "<<endl;
    for (size_t v = 0; v <= 3; v++)
    {
        cout<<endl<<"\t";
        cout<<char(178)<<arr[v]<<endl;
    }
    cout<< " Pick option 1,2,3 or 0 for exit "<<endl;
    int op_f;
    cin>>op_f;
    switch (op_f)
    {
    case 1:
        for (int q=0;q<=a;q++)
        {
            for (int w=0;w< r[q].rec_num ;w++  )
            {
                if(r[q].rec->criminal_name == "") continue;
                print_rec(w,q);
            }
        }    
        break;
    case 2:
        for (int q=0;q<=a;q++)
        {
            for (int w=0;w<=r[q].rec_num ;w++  )
            {
                if(r[q].rec->criminal_name == "") continue;
                cout<<"\t"<< r[q].rec[w].criminal_name << endl;
            }
        }
        break;    
    case 3:
        search_record_for_admin();
        break;
    case 0:
        return 0;
        break;    
    default:
        cout<<" Enter valid option :>>> "<<endl;
        break;
    }
    return op_f;
}




int main(){
    int op;
    do
    {
        display();
        cout<<"Enter your choice without spaces :>";
        cin>>op;
        cout<<endl;
        switch (op)
        {
        case 0:
            break;
        case 1:
            Register();
            continue;
        case 2:
            id = Login();
            if ( r[id].Isadmin ) 
            {
                int vc;
                do
                {
                    vc = admin_display();
                } while ( vc != 0);
            }
            continue;
        case 3:
            if (id != 0 )
            {
                add_record(id);
            }
            else
            {
                cout<<endl<<"\t\t\t"<<char(178)<<" Log in first :) "<<endl<<endl;
            }
            continue;
        case 4:
            if (id != 0 )
            {
                delete_record(id);
            }
            else
            {
                cout<<endl<<"\t\t\t"<<char(178)<<" Log in first :) "<<endl<<endl;
            }
            continue;
        case 5:
            if (id != 0 )
            {
                show_record(id);
            }
            else
            {
                cout<<endl<<"\t\t\t"<<char(178)<<" Log in first :) "<<endl<<endl;
            }
            continue;
        case 6:
            if (id != 0 )
            {
                int index_;
                cout<<endl<<"\t"<<char(178)<<" Enter number of the record to modify :>";
                cin>>index_;
                update_rec(id , index_ );
            }
            else
            {
                cout<<endl<<"\t\t\t"<<char(178)<<" Log in first :) "<<endl<<endl;
            }
            continue;               
        default :
            cout<<"Enter valid id :( "<<endl;
            break;
        }
    } while (op != 0);
    
    
    
    return 0;
}