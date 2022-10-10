#include<iostream>
#define NUL 0
using namespace std;

class Llist
{
    private : struct node
                {
                    int data;
                    struct node *next;
                }*start;
    public :
        Llist();
        void create_append(int);
        void add_at_begin(int);
        void insert_node(int,int);
        void delete_node(int,int);
        void display();
        void counter();
        ~ Llist();
};
Llist :: Llist()
{
    start = NUL;
}
void Llist :: create_append(int num)
{
    struct node *temp,*k;
    if(start == NUL)
    {
        temp = new struct node;
        if(temp == NUL)
        {
            cout<<"node creation failed\n";
            exit(0);
        }
        temp->data = num;
        temp->next = NUL;
        start = temp;
    }
    else
    {
        k = new struct node;
        if(k == NUL)
        {
            cout<<"node creation failed\n";
            exit(0);
        }
        while(temp->next != NUL)
        {
            temp  = temp->next;
        }
        temp->next=k;
        k->data = num;
        k->next = NUL;
    }

}
void Llist::add_at_begin(int num)
{
    struct node *temp;
    temp = new struct node;
    if(temp==NUL)
    {
            cout<<"node creation failed\n";
            exit(0);
    }
    temp->data = num;
    temp->next = start;
    start = temp;

}

void Llist::display()
{
    struct node *temp;
    temp = start;
    while(temp!=NUL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
void Llist::counter()
{
    struct node *temp;
    int countn=0;
    temp = start;
    while(temp!=NUL)
    {
        countn++;
        temp = temp->next;
    }
    cout<<"There are "<<countn<<" number of nodes\n";
}
void Llist::insert_node(int num,int pos)
 {
     struct node *enas,*hosad;
     enas = start;
     for(int i = 0;i<pos;i++)
     {
        enas = enas->next;
         if(enas==NUL)
         {

            cout<<"Insufficient number of nodes\n";
            exit(0);
         }

     }
     hosad = new struct node;
     hosad->data = num;
     hosad->next = enas->next;
     enas->next = hosad;

 }
void Llist::delete_node(int num,int pos)
{
    struct node *old,*temp;
    temp = start;
    while(temp!=NUL)
    {
        if(temp->data == num)
        {
            if(temp == start)
            {
                start = temp->next;
            }
            else
            {
                old->next = temp->next;
                delete temp;
            }
        }
        else
        {
            old = temp;
            temp = temp->next;
        }
    }
}
Llist::~Llist()
{
    struct node *temp;
    temp = start;
    while(start!=NUL)
    {
        start = start->next;
        delete temp;
        temp = start;
    }
}

int main()
{
    Llist l;
    int num,choice,pos;
    while(1)
    {
        cout<<"Enter the choice\n";
        cout<<"1 create/append\n";
        cout<<"2 add at beginning\n";
        cout<<"3 insert\n";
        cout<<"4 delete\n";
        cout<<"5 display the elements of each node\n";
        cout<<"6 count the number of nodes\n";
        cout<<"7 exit\n";
        cin>> choice;

        switch(choice)
        {
        case 1: cout<<"Enter the element\n";
                cin>>num;
                l.create_append(num);
                break;
        case 2: cout<<"Enter the element\n";
                cin>>num;
                l.add_at_begin(num);
                break;
        case 3: cout<<"Enter the element\n";
                cin>>num;
                cout<<"Enter the position\n";
                cin>>pos;
                l.insert_node(num,pos);
                break;
        case 4: cout<<"Enter the element\n";
                cin>>num;
                cout<<"Enter the position\n";
                cin>>pos;
                l.delete_node(num,pos);
                break;
        case 5: l.display();
                break;
        case 6: l.counter();
                break;
        case 7: cout<<"Exiting now...\n";
                exit(0);
        default :cout<<"Wrong input plz try again\n";
        }
    }
}
