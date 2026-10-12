#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct head
{
    int count;
    node* first;
};

class HashSearch
{
    public:
    head** hasht;
    int size;

    int hash(int key)
    {
        return key % size;
    }

    void createHashTable(int size_t)
    {
        size = size_t;
        hasht = new head*[size];

        int i = 0;
        for(i=0; i<size; i++)
        {
            hasht[i] = new head;
            hasht[i]->count = 0;
            hasht[i]->first == NULL;
        }
        
    }

    node* createNode(int data)
    {
        node* newnode = new node;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }

    bool insetToHashTable(int key)
    {
        int index = hash(key);
        if(index>=size) return false;
        node* t = createNode(key);
        t->next = hasht[index]->first;
        hasht[index]->first = t;
        hasht[index]->count++;
        return true;
    }

    bool searchHashTable(int key)
    {
        int index = hash(key);
        if(index>=size) return false;
        node* searchnode = hasht[index]->first;
        while(searchnode!=NULL)
        {
            if(searchnode->data == key)
            {
                return true;
            }
            searchnode = searchnode->next;
        }
        return false;
    }

    void displayHashTable()
    {
        node* temp;
        for(int i=0; i<size; i++)
        {
            temp = hasht[i]->first;
            cout<<"Index "<<i<<" : ";
            while(temp!=NULL)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }


    
}

int main()
{
    int size, ch;
    HashTable h;
    cout<<"Enter size of Hash Table: ";
    cin>>size;
    h.createHashTable(size);

    while(true)
    {
        cout<<"1. Insert\n2. Search\n3. Display\n4. Exit\nEnter your choice: ";
        cin>>ch;   

        switch(ch)
        {
            case 1:
                int key;
                cout<<"Enter key to insert: ";
                cin>>key;
                if(h.insetToHashTable(key))
                    cout<<"Key inserted successfully!"<<endl;
                else
                    cout<<"Failed to insert key!"<<endl;
                break;

            case 2:
                cout<<"Enter key to search: ";
                cin>>key;
                if(h.searchHashTable(key))
                    cout<<"Key found!"<<endl;
                else
                    cout<<"Key not found!"<<endl;
                break;

            case 3:
                h.displayHashTable();
                break;

            case 4:
            cout<<"Exiting program."<<endl;
                exit(0);

            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    }

}