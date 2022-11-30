#include <iostream>
using namespace std;
#include "patients.h"
#include "doctors.h"
#include <string.h>
#include <fstream>
#include <unordered_set>
void rating_update(string a,string b)
{
    int a1=stoi(a);//uid
    int b1=stoi(b);//rate
    node_d* p=first;
    while (p!=0)
    {
        if (p->UID==a)
        {
            int c=stoi(p->rating);
            int d=stoi(p->no_of_patients);
             c=(c*d+b1)/(d+1);
             p->rating=to_string(c);

        }
        
    
    }
    

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
void feedback()
{
    unordered_set <string> s;
    
    fstream fout;
    string rate,f;
    fout.open("feedback.csv",ios::out | ios::app);
    int h;
      cout<<"HOPE YOUR EXPERIENCE WAS GOOD WITH US"<<endl;
      cout<<"YOUR FEEDBACK GIVES US AN IDEA ON WHERE TO IMPROVE"<<endl;
      cout<<"ENTER DOCTORS UID: "<<endl;
      getline(cin,f);
      fout<<f<<", ";
      cout<<"HOW WAS THE DOCTOR ?(OVERALL BASED ON DOCTORS KNOWLEDGE,DOCTORS KINDNESS)"<<endl;
      cout<<"RATE OUT OF 5"<<endl;
      getline(cin,rate);
      fout<<rate<<", ";
      cout<<endl;
      cout<<"WAITING TIME: "<<endl;
      cout<<"1.very good"<<endl;
      cout<<"2.good"<<endl;
      cout<<"3.bad"<<endl;
      cout<<"4.worst"<<endl;
      cin>>h;
      fout<<h<<", ";
      cout<<endl;
      cout<<"HYGIENE: "<<endl;
       cout<<"1.very good"<<endl;
      cout<<"2.good"<<endl;
      cout<<"3.bad"<<endl;
      cout<<"4.worst"<<endl;
      cin>>h;
      fout<<h<<", ";
      fout<<"\n";
      rating_update(f,rate);
      cout<<"SINCE YOU ARE OUR FIRST CUSTOMER DO YOU WANT TO AVAIL DISCOUNT FOR BUYING MEDICINE ?"<<endl;
      cout<<"1.Yes"<<endl;
      cout<<"2.No"<<endl;
      cin>>h;
    

}