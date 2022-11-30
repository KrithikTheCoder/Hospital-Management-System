
#include <queue>
#include "patients.h"
#include "doctors.h"
#include <vector>

void upper(string s2)
{
     transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
}
int doctor_day_exist(string a,char y)
{
     for (int i = 0; i < a.length(); i++)
     {
         if (a[i]==y)
         {
          return 1;
         }
         
     }
     return 0;
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
           else{
               d=0;
           }
           p=p->next;
       }


      return d;
    

}
string func(string x)
{
      if (x=="1")
      {
        return "9AM to 10AM";
      }
       if (x=="2")
      {
        return "10AM to 11AM";
      }
       if (x=="3")
      {
        return "11AM to 12AM";
      }
       if (x=="4")
      {
        return "12AM to 1PM";
      }
       if (x=="5")
      {
        return "2:30PM to 4PM";
      }
       if (x=="6")
      {
        return "4PM to 5:30 PM";
      }
       if (x=="7")
      {
        return "5:30PM to 7PM";
      }
       if (x=="8")
      {
        return "7PM to 8:30PM";
      }
}

void appointment(vector <string> &Queue)
{
  static string booking_id;
  queue <string> q;
    node_d* p=first;
    char x,y;
    string e,f,g,h,i,j;
    cout<<"BEFORE BOOKING SLOT PLEASE GIVE THE FOLLOWING DETAILS: "<<endl;
    cout<<endl;
    cout<<"ENTER YOUR NAME: "<<endl;
    getline(cin,e);
      cout<<"ENTER YOUR EMAIL: "<<endl;
    getline(cin,f);
      cout<<"ENTER YOUR PHONE NO: "<<endl;
    getline(cin,g);

    check_exist(e,g,f);

    cout<<"ENTER THE DEPARTMENT YOU WANT TO BOOK FOR: "<<endl;
    getline(cin,h);

   slot: cout<<"ENTER TIME SLOT YOU WANT: "<<endl;
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
    cout<<"Enter the doctors UID to book your slot: "<<endl;
    getline(cin,j);
    booking_id=j+x+y;
    
    if (Queue.size()==0)
    {
        Queue.push_back(booking_id);
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
    }
}
int doctor_uid_checker(string doctor_UID,string UID)
{
  int c=0;
       for (int i = 0; i <=4; i++)
       {
           if (doctor_UID[i]==UID[i])
           {
               c=1;
           }
           else{
			      c=0;
		       }
       }
       return c;
}
void print_order_slot(vector <string> Queue,string doctor_UID,string day)
{
     queue <string> q;
     for (int i = 0; i < Queue.size(); i++)
     {
           if (doctor_uid_checker(Queue[i],doctor_UID)&&Queue[Queue[i].length()-1]==day)
           {
               q.push(Queue[i]);
           }
           
     }
     while (!q.empty())
     {
      cout<<q.front()<<endl;
      cout<<endl;
      q.pop();
     }
     
}


int main(int argc, char const *argv[])
{
  vector <string> whole_que;
    appointment(whole_que);
  return 0;
}
