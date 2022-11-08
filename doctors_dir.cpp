#include <iostream>
using namespace std;
#include <string.h>
#include <fstream>
struct node_d
{
   
   string name;
   string dept;
   string type;
   string period;
   string rating;
   string no;
   string email;
   string no_of_patients;
    
   node_d* next;

}*first=NULL,*last=NULL;

int count(node_d* p)
{
    int count=0;
    while (p!=0)
    {
        count++;
        p=p->next;
    }
    return count;
}

void swap(int *a,int *b)
{
    int* temp=a;
    a=b;
    b=temp;

}

void sort()
{
   node_d* q;
   node_d* p=first;
    int x=count(first);
    for(int i=0;i<x;i++)
    {  p=first;
        q=p;
       p=p->next;
         while (p!=0)
    {
        if (p->name.compare(q->name)<0)
        {
            p->name.swap(q->name);
            p->dept.swap(q->dept);
            p->type.swap(q->type);
            p->period.swap(q->period);
           p->no.swap(q->no);
            p->email.swap(q->email);
             p->no_of_patients.swap(q->no_of_patients);
             p->rating.swap(q->rating);

        }
        q=p;
        p=p->next;
       
    }

   }
    
}

void insert(string a,string b,string c,string e,string f,string g,string h,string d)
{
    node_d* p=first;
    node_d* t;
    if (p==NULL)
    {
        t=new node_d;
        t->name=a;
        t->dept=b;
        t->type=c;
        t->period=d;
         t->rating=e;
        t->no=f;
        t->email=g;
        t->no_of_patients=h;
        t->next=NULL;
        first=last=t;
        
    }
    
  else{
    while (p!=0)
    {
        if ( p->name==a && p->dept==b && p->type==c && p->no==f && p->email==g)
        {
           cout<<"This entry already exists"<<endl;
           return;
        }
        p=p->next;

    }
        t=new node_d;
        t->name=a;
        t->dept=b;
        t->type=c;
        t->period=d;
        t->rating=e;
        t->no=f;
        t->email=g;
        t->no_of_patients=h;
        t->next=NULL;
        last->next=t;
        last=t;
  }
      sort();
}
void del(string a,string f,string g)
{
    node_d* p=first;
    node_d* q;
    if (p->name==a && p->no==f && p->email==g)
    {
        first=first->next;
        
        delete p;
    }
    
    
    else{
        q=p;
        p=p->next;
       
        while (p!=0)
        {
            if (p->name==a  && p->no==f && p->email==g)
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
void search_name(node_d* p,string a)
{
    
    
    while (p!=0)
    {
        if (p->name==a)
        {
            cout<<"Name found"<<endl;
            cout<<p->dept<<endl;
            cout<<p->type<<endl;
            cout<<p->period<<endl;
            cout<<p->rating<<endl;
            cout<<p->no<<endl;
            cout<<p->email<<endl;
            cout<<p->no_of_patients<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Name not found"<<endl;
}
void search_email(node_d* p,string g)
{
    
    while (p!=0)
    {
        if (p->email==g)
        {
            cout<<"Email found"<<endl;
            cout<<p->name<<endl;
            cout<<p->dept<<endl;
            cout<<p->type<<endl;
            cout<<p->period<<endl;
            cout<<p->rating<<endl;
            cout<<p->no<<endl;
            cout<<p->no_of_patients<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Email not found"<<endl;
}
void search_no(node_d* p,string f)
{
    while (p!=0)
    {
        if (p->no==f)
        {
            cout<<"Number found"<<endl;
            cout<<p->name<<endl;
            cout<<p->dept<<endl;
            cout<<p->type<<endl;
            cout<<p->period<<endl;
            cout<<p->rating<<endl;
            cout<<p->email<<endl;
            cout<<p->no_of_patients<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Number not found"<<endl;
}
void search(node_d* p)
{
    cout<<"Enter the digit you want to search by:"<<endl;
    cout<<"1.Name\n2.Phone\n3.Email"<<endl;
    int x;
    cin>>x;
     if (x==1)
     {
       string a;
      cout<<"Enter name: "<<endl;
      getline(cin,a);
      search_name(p,a);
     }
     else if (x==2)
     {
         string f;
        cout<<"Enter phone number: "<<endl;
        cin>>f;
       search_no(p,f);
     }
     else if (x==3)
     {
        string g;
        cout<<"Enter email: "<<endl;
        cin>>g;
        search_email(p,g);
     }
     
 
}
void update_name(string a)
{
    node_d* p=first;
    while (p->name != a)
    {
        p=p->next;
    }
    
    cout<<"Enter the name you want to change by: ";
    getline(cin,p->name);
    
    sort(); 
}
void update_email(string a)
{
    node_d* p=first;
    while (p->email != a)
    {
        p=p->next;
    }
    
    cout<<"Enter the email you want to change by: ";
    getline(cin,p->email);
    
}
void update_no(string a)
{
    node_d* p=first;
    while (p->no != a)
    {
        p=p->next;
    }
    
    cout<<"Enter the number you want to change by: ";
     cin>>p->no;
    
}
void display(node_d *p)
{
    while (p!=0)
    {
        cout<<p->name<<endl;
        p=p->next;
    }
   
}

int main()
{
    string a,b,c,d;
    string e,f,g;
    ifstream file;
    file.open("doctors_dir.csv");
    while (file.good())
    {
        getline(file,a,',');
        getline(file,b,',');
        getline(file,c,',');
        getline(file,d,',');
        getline(file,e,',');
        getline(file,f,',');
        getline(file,g,'\n');
      insert(a,b,c,d,e,f,g," ");

         
    }
  
 
    return 0;
}

