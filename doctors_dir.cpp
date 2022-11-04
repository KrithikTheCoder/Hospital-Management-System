#include <iostream>
using namespace std;
#include <string.h>
struct node_d
{
   
   string name;
   string dept;
   string type;
   long int period;
   int rating;
   long int no;
   string email;
   long long int no_of_patients;
    
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
            swap(p->period,q->period);
            swap(p->rating,q->rating);
            swap(p->no,q->no);
            p->email.swap(q->email);
            swap(p->no_of_patients,q->no_of_patients);

        }
        q=p;
        p=p->next;
       
    }

   }
    
}

void insert(string a,string b,string c,long int d,int e,int f,string g,long long int h)
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
void del(string a,string b,string c,int f,string g)
{
    node_d* p=first;
    node_d* q;
    if (p->name==a && p->dept==b && p->type==c && p->no==f && p->email==g)
    {
        first=first->next;
        
        delete p;
    }
    
    
    else{
        q=p;
        p=p->next;
       
        while (p!=0)
        {
            if (p->name==a && p->dept==b && p->type==c && p->no==f && p->email==g)
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
void search_no(node_d* p,int f)
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
      cin>>a;
       search_name(p,a);
     }
     else if (x==2)
     {
         int f;
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

void display(node_d *p)
{
    while (p!=0)
    {
        cout<<p->name<<endl;
        p=p->next;
    }
   
}

int main(int argc, char const *argv[])
{
   insert("Nishkarsh","as","das",3,4,5,"bm21btech1",5);
   insert("krithik","as","das",3,4,5,"bm21btech2",5);
   insert("Nivas","as","das",3,4,5,"bm21btech3",5);
   display(first);
    search(first);
    return 0;
}
