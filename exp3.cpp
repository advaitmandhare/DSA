#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char name[20];
    node *next;
    node *down;
    int flag;
};

class GLL
{
    char ch[20];
    int n, i;
    node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;

public:
    node *create();
    void insertBook();
    void insertChapter();
    void insertSection();
    void insertSubSection();
    void displayBook();
};

node *GLL::create()
{
    node *p = new node;
    p->next = NULL;
    p->down = NULL;
    p->flag = NULL;
    cout << "\nEnter the name: ";
    cin >> p->name;
    return p;
}

void GLL::insertBook()
{
    if (head == NULL)
    {
        t1 = create();
        head = t1;
    }
    else
    {
        cout << "\nBook exists!!" << endl;
    }
}

void GLL::insertChapter()
{
    if (head == NULL)
        cout << "\nbook does not exist!!" << endl;
    else
    {
        cout << "\nenter the no. of chapters to be inserted in the book: ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            t1 = create();

            if (head->flag == 0)
            {
                head->down = t1;
                head->flag = 1;
            }
            else
            {
                temp = head;
                temp = temp->down;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}

void GLL::insertSection()
{
    if (head == NULL)
        cout << "\nbook does not exist" << endl;
    else
    {
        cout << "enter name of chapter in which you want to insert section: ";
        cin >> ch;

        temp = head;

        if (temp->flag == 0)
            cout << "\nNo chapters in the boook!!" << endl;
        else
        {
            temp = temp->down;
            while (temp != NULL)
            {
                if (!strcmp(ch, temp->name))
                {
                    cout << "\nhow many sections do you want to insert? : ";
                    cin >> n;
                    for (i = 0; i < n; i++)
                    {
                        t1 = create();
                        if (temp->flag == 0)
                        {
                            temp->down = t1;
                            temp->flag = 1;
                            cout << "\n*******";
                            t2 = temp->down;
                        }
                        else
                        {
                            cout << "\n#######";
                            while (t2->next != NULL)
                            {
                                t2 = t2->next;
                            }
                            t2->next = t1;
                        }
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void GLL::insertSubSection()
{
    if (head == NULL)
        cout << "\nbook does not exist" << endl;
    else
    {
        cout << "enter name of chapter in which you want to insert section: ";
        cin >> ch;

        temp = head;

        if (temp->flag == 0)
            cout << "\nNo chapters in the boook!!" << endl;
        else
        {
            temp = temp->down;
            while (temp != NULL)
            {
                if (!strcmp(ch, temp->name))
                {
                    cout << "\nenter section in which you want to insert subsection: ";
                    cin >> ch;
                    if (temp->flag == 0)
                        cout << "no sections present!!" << endl;
                    else
                    {
                        temp = temp->down;
                        while (temp != NULL)
                        {
                            if (!strcmp(ch, temp->name))
                            {
                                cout << "\nhow many sub sections do you want to insert? : ";
                                cin >> n;
                                for (i = 0; i < n; i++)
                                {
                                    t1 = create();
                                    if (temp->flag == 0)
                                    {
                                        temp->down = t1;
                                        temp->flag = 1;
                                        cout << "\n*******";
                                        t2 = temp->down;
                                    }
                                    else
                                    {
                                        cout << "\n#######";
                                        while (t2->next != NULL)
                                        {
                                            t2 = t2->next;
                                        }
                                        t2->next = t1;
                                    }
                                }
                                break;
                            }
                            temp = temp->next;
                        }
                    }
                }
                temp = temp->next;
            }
        }
    }
}

void GLL::displayBook()
{
    if (head == NULL)
        cout << "\nbook does not exist!!" << endl;
    else
    {
        temp = head;
        cout << "name of book: " << temp->name;
        if (temp->flag == 1)
        {
            temp = temp->down;
            while (temp != NULL)
            {
                cout << "\n\tname of chapter: " << temp->name;
                t1 = temp;
                if (t1->flag == 1)
                {
                    t1 = t1->down;
                    while (t1 != NULL)
                    {
                        cout << "\n\t\tname of section: " << t1->name;
                        t2 = t1;
                        if (t2->flag == 1)
                        {
                            t2 = t2->down;
                            while (t2 != NULL)
                            {
                                cout << "\n\t\t\tname of sub section: " << t2->name;
                                t2 = t2->next;
                            }
                        }
                        t1 = t1->next;
                    }
                }
                temp = temp->next;
            }
        }
    }
}

int main()
{
    GLL g;
    int x;
    while (1)
    {
        cout << "\nMenu: " << endl;
        cout << "1. insert book" << endl;
        cout << "2. insert chapter" << endl;
        cout << "3. insert section" << endl;
        cout << "4. insert sub section" << endl;
        cout << "5. display book" << endl;
        cout << "6. exit" << endl;
        cout << "enter your choice: ";
        cin >> x;

        switch (x)
        {
        case 1:
            g.insertBook();
            break;
        case 2:
            g.insertChapter();
            break;
        case 3:
            g.insertSection();
            break;
        case 4:
            g.insertSubSection();
            break;
        case 5:
            g.displayBook();
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}