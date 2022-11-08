#include <iostream>
using namespace std;
#include <string.h>
struct node_d
{
   
   string name;
   string dept;
   string roll;
   string type;
   int ethics_rating;
   int ph_no;
   string email;
   string past;
   string adress;
   bool student;
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
            p->roll.swap(q->roll);
            swap(p->ethics_rating,q->ethics_rating);
            
            swap(p->ph_no,q->ph_no);
            p->email.swap(q->email);
            p->past.swap(q->past);
            p->adress.swap(q->adress);
            
            
        }
        q=p;
        p=p->next;
       
    }

   }
    
}

void insert(string a,string b,string d,int e,int f,string g ,string h,string i,string c)
{
    node_d* p=first;
    node_d* t;
    if (p==NULL)
    {
        t=new node_d;
        t->name=a;
        t->dept=b;
        t->roll=c;
        t->type=d;
        t->ethics_rating=e;
        t->ph_no=f;
        t->email=g;
        t->past=h;
        t->adress=i;
        t->next=NULL;
        first=last=t;
        
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

        t=new node_d;
        t->name=a;
        t->dept=b;
        t->roll=c;
        t->type=d;
        t->ethics_rating=e;
        t->ph_no=f;
        t->email=g;
        t->past=h;
        t->adress=i;
        t->next=NULL;
        last->next=t;
        last=t;

  }
      sort();
}

void del(string a,int f,string g)
{
    node_d* p=first;
    node_d* q;
    if (p->name==a && p->ph_no==f && p->email==g)
    {
        first=first->next;
        
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
void search_name(node_d* p,string a)
{
    
    
    while (p!=0)
    {
        if (p->name==a)
        {
            cout<<"Name found"<<endl;
            cout<<p->dept<<endl;
            cout<<p->type<<endl;
            if(p->student)  cout<<p->roll<<endl;
            cout<<p->ethics_rating<<endl;
            cout<<p->ph_no<<endl;
            cout<<p->email<<endl;
            cout<<p->past<<endl;
            cout<<p->adress<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Name not found"<<endl;
}

void search_email(node_d* p,string a)
{
    
    
    while (p!=0)
    {
        if (p->email==a)
        {
            cout<<"Email found"<<endl;
            cout<<p->name<<endl;
            cout<<p->dept<<endl;
            cout<<p->type<<endl;
            if(p->student)  cout<<p->roll<<endl;
            cout<<p->ethics_rating<<endl;
            cout<<p->ph_no<<endl;
            cout<<p->past<<endl;
            cout<<p->adress<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Email not found"<<endl;
}
void search_no(node_d* p,int a)
{
    
    while (p!=0)
    {
        if (p->ph_no==a)
        {
            cout<<"No found"<<endl;
            cout<<p->name<<endl;
            cout<<p->dept<<endl;
            cout<<p->type<<endl;
            if(p->student)  cout<<p->roll<<endl;
            cout<<p->ethics_rating<<endl;
            cout<<p->email<<endl;
            cout<<p->past<<endl;
            cout<<p->adress<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"Email not found"<<endl;
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
         int f;
        cout<<"Enter phone number: "<<endl;
       
       search_no(p,f);
     }
     else if (x==3)
     {
        string g;
        cout<<"Enter email: "<<endl;
        getline(cin,g);
        search_email(p,g);
     }
     
 
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
void update_roll(string a)
{
    node_d* p=first;
    while (p->roll != a)
    {
        p=p->next;
    }
    
    cout<<"Enter the name you want to change by: ";
    getline(cin,p->roll);
    
}
void update_no(int a)
{
    node_d* p=first;
    while (p->ph_no != a)
    {
        p=p->next;
    }
    
    cout<<"Enter the number you want to change by: ";
     cin>>p->ph_no;
    
}
void display(node_d *p)
{
    while (p!=0)
    {
        cout<<p->name<<endl;
        p=p->next;
    }
   
}

