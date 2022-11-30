#include <iostream>
using namespace std;
#include <string.h>

struct node_p
{
   
   string name;
   string dept;
   string roll;
   string type;
   string ethics_rating;
   string ph_no;
   string email;
   string past;
   string adress;
   bool student;
   
   node_p* next;

}*first1=NULL,*last1=NULL;

int count1(node_p* p)
{
    int count=0;
    while (p!=0)
    {
        count++;
        p=p->next;
    }
    return count;
}

void sort1()
{
   node_p* q;
   node_p* p=first1;
    int x=count1(first1);
    for(int i=0;i<x;i++)
    {  p=first1;
        q=p;
       p=p->next;
         while (p!=0)
    {
        if (p->name.compare(q->name)<0)
        {
        
            p->name.swap(q->name);
            p->dept.swap(q->dept);
            p->type.swap(q->type);
            p->roll.swap(q->roll);
            p->ethics_rating.swap(q->ethics_rating);
            p->ph_no.swap(q->ph_no);
            p->email.swap(q->email);
           
            p->past.swap(q->past);
            p->adress.swap(q->adress);
            
            
        }
        q=p;
        p=p->next;
       
    }

   }
    
}

void insert1(string a,string b,string d,string e,string f,string g ,string h,string i,string c)
{
    node_p* p=first1;
    node_p* t;
    if (p==NULL)
    {
        t=new node_p;
        t->name=a;
        t->dept=b;
        t->roll=c;
        t->type=d;
        t->ethics_rating=e;
        t->ph_no=f;
        t->email=g;
        
        t->past="NONE";
        t->adress=i;
        t->next=NULL;
        first1=last1=t;
        
    }
    
       
  else{
    while (p!=0)
    {
      
        if ( p->name==a && p->email==g &&p->ph_no==f)
        {
           cout<<"This entry already exists"<<endl;
           return;
        }
       
    
        p=p->next;

    }

        t=new node_p;
        t->name=a;
        t->dept=b;
        t->roll=c;
        t->type=d;
        t->ethics_rating=e;
        t->ph_no=f;
        t->email=g;
        t->past="NONE";
        t->adress=i;
      
        t->next=NULL;
        last1->next=t;
        last1=t;

  }
      sort1();
}

void del1(string a,string f,string g)
{
    node_p* p=first1;
    node_p* q;
    if (p->name==a && p->ph_no==f && p->email==g)
    {
        first1=first1->next;
        
        delete p;
    }
    
    
    else{
        q=p;
        p=p->next;
       
        while (p!=0)
        {
            if (p->name==a  && p->ph_no==f && p->email==g)
            {
                break;
            }
            q=p;
            p=p->next;
        }

            q->next=p->next;
            
            delete p;
        
    }

}
void search_name1(node_p* p,string a)
{
    
    
    while (p!=0)
    {
        if (p->name==a)
        {
             cout<<"Name found"<<endl;
             cout<<endl;
            cout<<"Department: "<<p->dept<<endl;
            cout<<"Type of employment: "<<p->type<<endl;
            if(p->student)  cout<<"ROll NUMBER: "<<p->roll<<endl;
            cout<<"Ethical Rating: "<<p->ethics_rating<<endl;
            cout<<"Number: "<<p->ph_no<<endl;
            cout<<"Email: "<<p->email<<endl;
            cout<<"Past appointment Hitory: "<<p->past<<endl;
            cout<<"Address: "<<p->adress<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Name not found"<<endl;
}

void search_email1(node_p* p,string a)
{
    
    
    while (p!=0)
    {
        if (p->email==a)
        {
            cout<<"Email found"<<endl;
            cout<<"Name: "<<p->name<<endl;
           cout<<"Department: "<<p->dept<<endl;
             cout<<"Type of employment: "<<p->type<<endl;
            if(p->student)  cout<<"ROll NUMBER: "<<p->roll<<endl;
           cout<<"Ethical Rating: "<<p->ethics_rating<<endl;
            cout<<"Number: "<<p->ph_no<<endl;
            cout<<"Past appointment Hitory: "<<p->past<<endl;
           cout<<"Address: "<<p->adress<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Email not found"<<endl;
}
void search_no1(node_p* p,string a)
{
    
    while (p!=0)
    {
        if (p->ph_no==a)
        {
            cout<<"Number found"<<endl;
           cout<<"Name: "<<p->name<<endl;
            cout<<"Department: "<<p->dept<<endl;
            cout<<"Type of employment: "<<p->type<<endl;
            if(p->student)  cout<<"ROll NUMBER: "<<p->roll<<endl;
          cout<<"Ethical Rating: "<<p->ethics_rating<<endl;
           cout<<"Email: "<<p->email<<endl;
            cout<<"Past appointment Hitory: "<<p->past<<endl;
              cout<<"Address: "<<p->adress<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Email not found"<<endl;
}

void search1(node_p* p)
{
    cout<<"Enter the digit you want to search by:"<<endl;
    cout<<"1.Name\n2.Phone\n3.Email"<<endl;
    int x;
    cin>>x;
    cin.ignore();
     if (x==1)
     {
       string a;
      cout<<"Enter name: "<<endl;
      getline(cin,a);
      search_name1(p,a);
     }
     else if (x==2)
     {
         string f;
        cout<<"Enter phone number: "<<endl;
       
       search_no1(p,f);
     }
     else if (x==3)
     {
        string g;
        cout<<"Enter email: "<<endl;
        getline(cin,g);
        search_email1(p,g);
     }
     
 
}

void update_email1(string a)
{
    node_p* p=first1;
    while (p->email != a)
    {
        p=p->next;
    }
    
    cout<<"Enter the email you want to change by: ";
    getline(cin,p->email);
    
}
void update_name1(string a)
{
    node_p* p=first1;
    while (p->name != a)
    {
        p=p->next;
    }
    
    cout<<"Enter the name you want to change by: ";
    getline(cin,p->name);
    
    sort1(); 
}
void update_roll1(string a)
{
    node_p* p=first1;
    while (p->roll != a)
    {
        p=p->next;
    }
    
    cout<<"Enter the name you want to change by: ";
    getline(cin,p->roll);
    
}
void update_no1(string a)
{
    node_p* p=first1;
    while (p->ph_no != a)
    {
        p=p->next;
    }
    
    cout<<"Enter the number you want to change by: ";
     cin>>p->ph_no;
    
}
void past_history()
{
    string a,b,c;
    node_p* p=first1;
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

       while (p!=NULL)
       {  if (p->name==a && p->ph_no==b && p->email==c)
           {
                   cout<<"Past Appointment History: "<<p->past;
                   return;
           }
       
          p=p->next;
       }
     cout<<"NOT FOUND"<<endl;
       
}
void display1(node_p *p)
{
    while (p!=0)
    {
        cout<<p->name<<endl;
        p=p->next;
    }
   
}


