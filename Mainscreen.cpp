#include <iostream>
using namespace std;
#include <unordered_set>
#include <fstream>
#include "appointment.h"
#include <string.h>
char id='1001';
string up(string s1)
{
   transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    return s1;
}
int check_exist(string a,string b,string c)
{
    node_p* p=first1;
    int d=0;
       while (p!=0)
       {
           if (p->name==a && p->ph_no ==b && p->email==c)
           {
               d=1;
           }
        
           p=p->next;
       }


      return d;
    
    
}
void update_feedback(string a,int b,int c,int d)
{
     ofstream feed;
     feed.open("feedback.csv",ios::app);
     feed<<a<<",";
     feed<<b<<",";
     feed<<c<<",";
     feed<<d<<",";
}
void transfer_patient()
{
  ifstream pat("patient_dir.csv");
     string a,b,c,d,e,f,g,h,i;
     while (pat.good())
     {
          getline(pat,a,',');//name
          getline(pat,b,',');//dept
           getline(pat,c,',');//designation
          getline(pat,d,',');//ethics
          getline(pat,e,',');//ph_no
          getline(pat,f,',');//email
          getline(pat,g,',');//past
           getline(pat,h,',');//address
            getline(pat,i,'\n');//roll
            
         
          insert1(a,b,c,d,e,f,g,h,i);

     }
}
void append_pdetails(string a,string b,string c,string d,string f,string g,string i)
{
      ofstream patient;
         patient.open("patients.csv",ios::app);
      patient<<a<<", ";
        patient<<b<<", ";
        patient<<c<<", ";
        patient<<"5"<<", ";
        patient<<f<<", ";
        patient<<g<<", ";
           patient<<"NONE"<<", ";
          patient<<i<<", ";
           patient<<d<<", ";
          patient<<"\n";
}

void rating_update(string a,int d)
{
    
   
    node_d* p=first;
    while (p!=0)
    {
        if (p->UID==a)
        {
            string b=p->rating;
            string c=p->no_of_patients;
               int f=stoi(b);
               int e=stoi(c);
            f=(f*e+d)/(e+1);
            p->rating=to_string(f);
             
        }
        
    
    }
    

}
void lower(string s2)
{
     transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
}
void transfer_doctor()
{
      ifstream doctor("new_doctors.csv");
     string a,b,c,d,e,f,g,h,i,j; 
     while (doctor.good())
     {
          getline(doctor,a,',');//name
          getline(doctor,b,',');//dept
           getline(doctor,c,',');//type
          getline(doctor,d,',');//period
          getline(doctor,e,',');//rating
          getline(doctor,f,',');//ph_no
          getline(doctor,g,',');//email
           getline(doctor,h,',');//no_of_pat
            getline(doctor,i,',');//day
             getline(doctor,j,'\n');//uid
         
          insert(a,b,c,d,i,e,f,g,h,j);

     }
}
void transfer_coupons(vector <string> &coupons)
{

      ifstream file("coupons.txt");
     string a;
    
     while (!file.eof())
     {
          getline(file,a);
          coupons.push_back(a);
     }
      
  
}
void delete_line( )
{
    vector <string> v;

    transfer_coupons(v);
    v.erase(v.begin());
    ofstream newfile("coupons.txt");

    for (int i = 0; i < v.size(); i++)
    {
          newfile<<v[i]<<"\n";
    }
    
}

void read_bookingids(vector <string> &list)
{
  string a;
       ifstream f("booking_ids.txt");
       while (!f.eof())
       {
         getline(f,a);
         list.push_back(a);
       }
       
}
   

int main(int argc, char const *argv[])
{    
     vector <string> qeu;
    

     vector <string> v;
   ofstream patient;
         patient.open("patients.csv",ios::app);
    int x,y,student;
    vector <string> Queue;
     string a,b,c,d,e,f,g,h,i,j; 
      int ld=0;
     transfer_doctor();
     transfer_patient();
     transfer_coupons(v);

     start:cout<<"|----------------WELCOME TO IITH HOSPITALS----------------|"<<endl;
     cout<<endl;
     cout<<"|------ENTER THE FOLLOWING KEY TO AVAIL THE SERVICE------|"<<endl;
     cout<<endl;
     cout<<"1.DOCTORS/STAFF DETAILS"<<endl;
     cout<<"2.PATIENTS DETAILS"<<endl;
     cout<<"3.MAKE AN APPOINTMENT"<<endl;
     cout<<"4.QUIT"<<endl;
     cin>>x;
     
      switch (x)
     {
     case 1:
     doctor:cout<<"|------ENTER THE FOLLOWING KEY TO AVAIL THE SERVICE------|"<<endl;
        cout<<endl;
         cout<<"1.ENTER DOCTOR/STAFF DETAILS"<<endl;
     cout<<"2.UPDATE DETAILS"<<endl;
     cout<<"3.SEARCH FOR DETAILS"<<endl;
     cout<<"4.DELETE DETAILS"<<endl;
     cout<<"5.BACK"<<endl;
     cin>>y;
       switch (y)
       {
       case 1:
        cin.ignore();
        cout<<"ENTER NAME: ";
        getline(cin,a);
        cout<<endl;
        cout<<"ENTER DEPARTMENT: ";
        getline(cin,b);
        cout<<endl;
         cout<<"ENTER YOUR TYPE OF EMPLOYMENT: ";
        getline(cin,c);
        cout<<endl;
         cout<<"ENTER YOUR PERIOD OF AVAILABILITY: ";
        getline(cin,d);
        cout<<endl;
         cout<<"ENTER PHONE NO: ";
        getline(cin,f);
        cout<<endl;
         cout<<"ENTER EMAIL: ";
        getline(cin,g);
        cout<<endl;
         cout<<"ENTER NUMBER OF PATIENT: ";
        getline(cin,h);
        cout<<endl;
        cout<<"ENTER YOUR DAYS THAT IS FREE: "<<endl;
        getline(cin,i);
        cout<<endl;
       j="DR"+id;
       id++;
        insert(a,b,c,d,"3",f,g,h,i,j);
        cout<<endl;
        cout<<"|-----DETAILS ADDED----|"<<endl;
         goto doctor;
        break;
      
       case 2:

       cout<<"WHAT DETAIL DO YOU WANT TO CHANGE: ";
       cout<<endl;
       cout<<"1.NAME"<<endl;
        cout<<"2.EMAIL"<<endl;
        cout<<"3.PHONE NO"<<endl;
       cin>>x;
       cin.ignore();
       cout<<endl;
       if (x==1)
       {
          cout<<"ENTER NAME: ";
          getline(cin,a);
         update_name(a);
       }
       if (x==2)
       {
         cout<<"ENTER EMAIL: ";
          getline(cin,b);
         update_email(b);
       }
       if (x==3)
       {
         cout<<"ENTER PHONE NO: ";
          getline(cin,c);
         update_no(c);
       }
       cout<<"|-----DETAIL CHANGED----|"<<endl;
        goto doctor;
      break;
      
      case 3:

       search(first);
        goto doctor;
       break;
      
      case 4:
       cin.ignore();
       cout<<"ENTER YOUR NAME: ";
       getline(cin,a);
       cout<<endl;
       cout<<"ENTER YOUR PH NO: ";
       getline(cin,b);
       cout<<endl;
       cout<<"ENTER YOUR EMAIL: ";
       getline(cin,c);
       cout<<endl;
       del(a,b,c);
       cout<<"|------"<<a<<" DETAILS DELETED------|"<<endl;
        goto doctor;
        break;
       
       case 5:
       goto start;
       break;
       }
        break;

     case 2:
     patient:
     cout<<"|------ENTER THE FOLLOWING KEY TO AVAIL THE SERVICE------|"<<endl;
        cout<<endl;
         cout<<"1.ENTER PATIENT DETAILS"<<endl;
     cout<<"2.UPDATE DETAILS"<<endl;
     cout<<"3.SEARCH FOR DETAILS"<<endl;
     cout<<"4.DELETE DETAILS"<<endl;
     cout<<"5.PAST APPOINTMENT DETAILS"<<endl;
     cout<<"6.BACK"<<endl;
     cin>>y;
       
         switch (y)
         {
         case 1:cin.ignore();
         
  patient_entry:
        
        cout<<"ENTER NAME: ";
        getline(cin,a);
      
        cout<<endl;
        cout<<"ENTER DEPARTMENT: ";
        getline(cin,b);
        cout<<endl;
         cout<<"ENTER YOUR TYPE OF EMPLOYMENT: ";
         cout<<"CHOOSE FROM BELOW"<<endl;
        cout<<"1.STUDENT"<<endl;
        cout<<"2.JOB"<<endl;
        cout<<"3.OTHERS"<<endl;
         cin>>x;
          if (x==1)
          {
            c="STUDENT";
          }
          if (x==2)
          {
            c="JOB";
          }
            if (x==3)
          {
            cout<<"ENTER:"<<endl;
            getline(cin,c);
          }
          
        cout<<endl;
        cin.ignore();
        if(x==1)
         {cout<<"ENTER YOUR ROLL NUMBER: ";
        getline(cin,d);
         }
         else{
            d="0";
         }
        
         cout<<"ENTER PHONE NO: ";
        getline(cin,f);
        cout<<endl;
         cout<<"ENTER EMAIL: ";
        getline(cin,g);
        cout<<endl;
       cout<<"ENTER YOUR ADRESS: ";
        getline(cin,i);
        cout<<endl;
       
        insert1(a,b,c,"5",f,g,"NONE",i,d);
        cout<<endl;
        cout<<"|-----DETAILS ADDED----|"<<endl;
        append_pdetails(a,b,c,d,f,g,i);
         goto patient;
            break;

        case 2:

       cout<<"WHAT DETAIL DO YOU WANT TO CHANGE: ";
       cout<<endl;
       cout<<"1.NAME"<<endl;
        cout<<"2.EMAIL"<<endl;
        cout<<"3.PHONE NO"<<endl;
       cin>>x;
       cin.ignore();
       cout<<endl;
       if (x==1)
       {
         cout<<"ENTER NAME:"<<endl;
          getline(cin,a);
         update_name1(a);
       }
       if (x==2)
       {
         cout<<"ENTER EMAIL:"<<endl;
          getline(cin,b);
         update_email1(b);
       }
       if (x==3)
       {
         cout<<"ENTER PHONE NO:"<<endl;
          getline(cin,c);
         update_no1(c);
       }
       cout<<"|-----DETAIL CHANGED----|"<<endl;
        goto patient;
      break;

        case 3:

       search1(first1);
        goto patient;
       break;

        case 4:
       
       cout<<"ENTER YOUR NAME: ";
       getline(cin,a);
       cout<<endl;
       cout<<"ENTER YOUR PH NO: ";
       getline(cin,b);
       cout<<endl;
       cout<<"ENTER YOUR EMAIL: ";
       getline(cin,c);
       cout<<endl;
       del1(a,b,c);
       cout<<"|------"<<a<<" DETAILS DELETED------|"<<endl;
        goto patient;
        break;
        
        case 5:
          past_history();
         break;

        case 6:
        goto start;
        break;
         }
    case 3:
       string booking_id;
    queue <string> q;
    node_d* p=first;
    char x,y;
    string e,f,g,h,i,j;
appoinment:cout<<"BEFORE BOOKING SLOT PLEASE GIVE THE FOLLOWING DETAILS: "<<endl;
    cout<<endl;
    cin.ignore();
   cout<<"ENTER YOUR NAME: "<<endl;
    getline(cin,e);
      cout<<"ENTER YOUR EMAIL: "<<endl;
    getline(cin,f);
      cout<<"ENTER YOUR PHONE NO: "<<endl;
    getline(cin,g);

    ld=0;
    if (check_exist(e,g,f)==0)
    {
        cout<<"PLEASE REGISTER BEFORE BOOKING"<<endl;
        
        ld=1;
         goto patient_entry;
    }
    else{
      ld=0;
    }
    
   slot: cout<<"ENTER THE DEPARTMENT YOU WANT TO BOOK FOR: "<<endl;
    getline(cin,h);
    up(h);

    cout<<"ENTER TIME SLOT YOU WANT: "<<endl;
    cout<<"1. 9AM to 10AM"<<endl;
    cout<<"2. 10AM to 11AM"<<endl;
    cout<<"3. 11AM to 12PM"<<endl;
    cout<<"4. 12PM to 1PM"<<endl;
   cout<<"5. 2:30PM to 4PM"<<endl;
   cout<<"6. 4PM to 5:30PM"<<endl;
   cout<<"7. 5:30PM to 7PM"<<endl;
   cout<<"8. 7PM to 8:30PM"<<endl;
    cin>>x;
     cout<<"ENTER ON WHICH DAY YOU WANT THIS SLOT:"<<endl;
      cout<<"1.MONDAY"<<endl;
    cout<<"2.TUESDAY"<<endl;
    cout<<"3.WEDNESDAY"<<endl;
    cout<<"4.THURSDAY"<<endl;
   cout<<"5.FRIDAY"<<endl;
   cout<<"6.SATURDAY"<<endl;
   cout<<"7.SUNDAY"<<endl;
    cin>>y;
    while (p!=0)
    {
        if (p->dept==h && p->rating[0]>='3'&&( p->period[0]==x||p->period[1]==x||p->period[2]==x||p->period[3]==x||p->period[4]==x)&&doctor_day_exist(p->day,y))
        {
            cout<<"Name of Doctor: "<<p->name<<endl;
            cout<<"Email of Doctor: "<<p->email<<endl;
            cout<<"UID: "<<p->UID<<endl;
            cout<<endl;
            
        }
        p=p->next;
    }
    cin.ignore();
    cout<<"Enter the doctors UID to book your slot: "<<endl;
    getline(cin,j);
    booking_id=j+x+y;
    ofstream fil("booking_ids.txt",ios::app);
    if (Queue.size()==0)
    {
        Queue.push_back(booking_id);
        fil<<booking_id<<"\n";
    }
    else{
      for (int i = 0; i < Queue.size(); i++)
      {
           if (Queue[i]==booking_id)
           {
               cout<<"SORRY THE SLOT IS ALREADY BOOKED , PLEASE BOOK ANOTHER SLOT "<<endl;
               goto slot;
           }
           
      }
      Queue.push_back(booking_id);
      fil<<booking_id<<"\n";
    }
    cout<<"|------------SLOT BOOKED------------|"<<endl;
    cout<<endl;
    cout<<endl;
   
    int rate;
    string f1;
   
    int h1;
    int h2;
      cout<<"HOPE YOUR EXPERIENCE WAS GOOD WITH US"<<endl;
      cout<<"YOUR FEEDBACK GIVES US AN IDEA ON WHERE TO IMPROVE"<<endl;
      cout<<"ENTER DOCTORS UID: "<<endl;
      getline(cin,f1);
      
      cout<<"HOW WAS THE DOCTOR ?(OVERALL BASED ON DOCTORS KNOWLEDGE,DOCTORS KINDNESS)"<<endl;
      cout<<"RATE OUT OF 5"<<endl;
     cin>>rate;
    
      cout<<endl;
      cout<<"WAITING TIME: "<<endl;
      cout<<"1.very good"<<endl;
      cout<<"2.good"<<endl;
      cout<<"3.bad"<<endl;
      cout<<"4.worst"<<endl;
      cin>>h1;
     
      cout<<endl;
      cout<<"HYGIENE: "<<endl;
       cout<<"1.very good"<<endl;
      cout<<"2.good"<<endl;
      cout<<"3.bad"<<endl;
      cout<<"4.worst"<<endl;
      cin>>h2;
      
       update_feedback(f1,h1,rate,h2);
      rating_update(f1,rate);
     
      
      break;

  }
  goto start;
    return 0;
}
