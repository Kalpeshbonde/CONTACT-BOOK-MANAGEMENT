#include <iostream>
using namespace std;

// Node structure to represent a contact in the contact book
struct Node
{
    string name;
    long long int phone_number;
    Node *next;
    Node *prev;
};

// ContactBook class to manage contacts and operations
class ContactBook
{
    Node *head;
    string x;
    long long int y;

public:
    // Constructor to initialize the ContactBook
    ContactBook()
    {
        head = NULL;
        x = "";
        y = 0;
    }

    // Function to create a new contact node and add it to the contact book
    void CreateNode()
    {
        // Check if the contact book is empty
        if (head == NULL)
        {
            Node *newer = new Node;
            cout << " Name of Contact: ";
            cin >> x;
            newer->name = x;
            cout << " Phone Number: ";
            cin >> y;
            newer->phone_number = y;
            newer->next = NULL;
            head = newer;
            cout << " Contact Added" << endl;
        }
        else
        {
            Node *newer = new Node;
            cout << " Name of Contact: ";
            cin >> x;
            newer->name = x;
            cout << " Phone Number: ";
            cin >> y;
            newer->phone_number = y;
            newer->next = NULL;

            // Traverse to the end of the contact book and add the new contact
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newer;
            newer->prev = temp;
            cout << " Contact Added" << endl;
        }
    }

    // Function to display all contacts in the contact book
    void Display()
    {
        Node *temp = head;
        int count = 0;

        // Check if the contact book is empty
        if (temp == NULL)
        {
            cout << " No Contacts... Please Add Some Contacts" << endl;
        }
        else
        {
            // Sort contacts and display them
            BubbleSort();
            cout << " Name: "
                 << " Number: \n"
                 << endl;
            while (temp != NULL)
            {
                count++;
                cout << " " << temp->name;
                cout << " " << temp->phone_number << endl;
                temp = temp->next;
            }
            cout << " Total contacts: " << count << endl;
        }
    }

    // Function to search for a contact by name or number
    void Search()
    {
        bool check = false;
        Node *temp = head;
        cout << "***********" << endl;
        cout << " Press 1 for Search By Name." << endl;
        cout << " Press 2 for Search By Number." << endl;
        int choice;
        cout << " Enter the Choice: ";
        cin >> choice;

        if (choice == 1 && temp != NULL)
        {
            cout << " Enter the Name to Search: ";
            cin >> x;
            while (temp != NULL)
            {
                if (temp->name == x)
                {
                    cout << " Name: " << temp->name << endl;
                    cout << " Phone Number:" << temp->phone_number << endl;
                    check = true;
                    break;
                }
                temp = temp->next;
            }
            if (check == false)
            {
                cout << " Name Not Found" << endl;
            }
        }
        else if (choice == 2)
        {
            cout << " Enter the Number to Search: ";
            cin >> y;

            while (temp != NULL)
            {
                if (temp->phone_number == y)
                {
                    cout << " Name: " << temp->name << endl;
                    cout << " Phone Number: " << temp->phone_number << endl;
                    check = true;
                    break;
                }
                temp = temp->next;
            }
            if (check == false)
            {
                cout << " Number Not Found" << endl;
            }
        }
    }

    // Function to delete all contacts in the contact book
    void DeleteAllContacts()
    {
        Node *temp = head;
        Node *temp2;

        // Check if the contact book is already empty
        if (head == NULL)
        {
            cout << " Already Contact Book is Empty" << endl;
            cout << "***********" << endl;
        }
        else
        {
            // Delete each contact node
            while (temp != NULL)
            {
                temp2 = temp;
                temp = temp->next;
                delete temp2;
            }
            head = NULL;
            cout << " Successfully Deleted All Contacts" << endl;
            cout << "Thanks For Using " << endl;
        }
    }

    // Function to delete a contact by searching for its name or number
    void DeleteContactBySearch()
    {
        Node *temp = head;
        cout << " Press 1 for Search By name" << endl;
        cout << " Press 2 for Search By Number" << endl;
        int command;
        cout << " Enter the Command: ";
        cin >> command;

        if (command == 1)
        {
            bool Dcheck = false;
            cout << " Enter the Name to Delete: ";
            cin >> x;
            while (temp != NULL)
            {
                if (temp->name == x)
                {
                    cout << " Name: " << temp->name << endl;
                    cout << " Phone Number: " << temp->phone_number << endl;
                    Dcheck = true;
                    break;
                }
                temp = temp->next;
            }
            if (Dcheck == true)
            {
                int command;
                cout << " Press 1 to Delete the Contact: ";
                cin >> command;
                if ((command == 1) & (temp == head))
                {
                    Node *temp1;
                    temp1 = temp;
                    temp = temp->next;
                    delete temp1;

                    temp->prev = NULL;
                    head = temp;
                    cout << " Contact Deleted Success Fully" << endl;
                }
                else if ((command == 1) & (temp->next == NULL))
                {
                    temp->prev->next = NULL;
                    delete temp;
                    cout << " Contact Deleted Success Fully" << endl;
                }
                else if (command == 1)
                {
                    Node *temp1;
                    temp1 = temp;
                    temp->prev->next = temp1->next;
                    temp->next->prev = temp1->prev;
                    delete temp1;
                    cout << " Contact Deleted Success Fully" << endl;
                }
                else
                {
                    cout << " You Enter Wrong Command" << endl;
                }
            }
            else if (Dcheck == false)
            {
                cout << " Contact of This Name Not Found." << endl;
            }
        }
        else if (command == 2)
        {
            bool Dcheck = false;
            cout << " Enter the Number to Delete: ";
            cin >> y;
            while (temp != NULL)
            {
                if (temp->phone_number == y)
                {
                    cout << "name: " << temp->name << endl;
                    cout << "Phone Number: " << temp->phone_number << endl;
                    Dcheck = true;
                    break;
                }
                temp = temp->next;
            }
            if (Dcheck == true)
            {
                int command;
                cout << " Press 1 to Delete the Contact: ";
                cin >> command;
                if ((command == 1) & (temp == head))
                {
                    Node *temp1;
                    temp1 = temp;
                    temp = temp->next;
                    delete temp1;
                    temp->prev = NULL;
                    head = temp;
                    cout << " Contact Deleted Success Fully" << endl;
                }
                else if ((command == 1) & (temp->next == NULL))
                {
                    temp->prev->next = NULL;
                    delete temp;
                    cout << " Contact Deleted Success Fully" << endl;
                }
                else if (command == 1)
                {
                    Node *temp1;
                    temp1 = temp;
                    temp->prev->next = temp1->next;
                    temp->next->prev = temp1->prev;
                    delete temp1;
                    cout << " Contact Deleted Success Fully" << endl;
                }
                else
                {
                    cout << " You Enter Wrong Command" << endl;
                }
            }
            else if (Dcheck == false)
            {
                cout << " Contact of This Name Not Found." << endl;
            }
        }
        else
        {
            cout << " You Enter wrong Command" << endl;
        }
    }

    // Function to perform bubble sort on the contact book based on names
    void BubbleSort()
    {
        Node *temp = head;
        Node *i, *j;
        string n;
        long long int n2;
        // Check if the contact book is empty
        if (temp == NULL)
        {
            cout << " Empty contact Book" << endl;
        }
        else
        {
            // Perform bubble sort based on names
            for (i = head; i->next != NULL; i = i->next)
            {
                for (j = i->next; j != NULL; j = j->next)
                {
                    if (i->name > j->name)
                    {
                        // Swap names and phone numbers
                        n = i->name;
                        i->name = j->name;
                        j->name = n;

                        n2 = i->phone_number;
                        i->phone_number = j->phone_number;
                        j->phone_number = n2;
                    }
                }
            }
        }
    }

    // Function to edit a contact by searching for its name or number
    void EditContacts()
    {
        Node *temp = head;
        cout << " Press 1 for search By Name" << endl;
        cout << " Press 2 for search By Number" << endl;
        int Ecommand;
        cout << " Enter the Command: ";
        cin >> Ecommand;

        if (Ecommand == 1)
        {
            bool Echeck = false;
            cout << " Enter the Name to Edit: ";
            cin >> x;
            while (temp != NULL)
            {
                if (temp->name == x)
                {
                    cout << "***********" << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Phone Number: " << temp->phone_number << endl;
                    Echeck = true;
                    break;
                }
                temp = temp->next;
            }
            if (Echeck == true)
            {
                int command;
                cout << " Press 1 to Edit the Contact: ";
                cin >> command;
                if (command == 1)
                {
                    cout << " Enter New Name: ";
                    cin >> x;
                    cout << " Enter New Number: ";
                    cin >> y;
                    temp->name = x;
                    temp->phone_number = y;

                    cout << " Contact Edited Success Fully" << endl;
                }
                else
                {
                    cout << " You Enter Wrong Command ... Try Again" << endl;
                }
            }
            else if (Echeck == false)
            {
                cout << " Contact Not Found" << endl;
            }
        }
        else if (Ecommand == 2)
        {
            bool Echeck = false;
            cout << " Enter the Number to Edit: ";
            cin >> y;
            while (temp != NULL)
            {
                if (temp->phone_number == y)
                {
                    cout << "***********" << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Phone Number: " << temp->phone_number << endl;
                    Echeck = true;
                    break;
                }
                temp = temp->next;
            }
            if (Echeck == true)
            {
                int command;
                cout << " Press 1 to Edit the Contact: ";
                cin >> command;
                if (command == 1)
                {
                    cout << " Enter New Name: ";
                    cin >> x;
                    cout << " Enter New Number: ";
                    cin >> y;
                    temp->name = x;
                    temp->phone_number = y;

                    cout << " Contact Edited Success Fully" << endl;
                }
                else
                {
                    cout << " You Enter Wrong Command" << endl;
                }
            }
            else if (Echeck == false)
            {
                cout << " There is No Contact of this Number." << endl;
            }
        }
        else
        {
            cout << " You Enter Wrong Command Try Again" << endl;
        }
    }

    // Function to display the structure of the program and guide user through options
    void Structure()
    {
        cout << "\n------------" << endl;
        cout << " 1. Add Contact" << endl;
        cout << " 2. Edit the Contact" << endl;
        cout << " 3. Delete Contact" << endl;
        cout << " 4. Search Contact" << endl;
        cout << " 5. Display All Contacts" << endl;
        cout << " 6. Delete All Contacts" << endl;
        cout << "-------------" << endl;
        int Scommand;
        cout << "\n Enter the Command: ";
        cin >> Scommand;

        try
        {
            if (Scommand >= 1 && Scommand <= 6)
            {
                // Perform the corresponding operation based on user input
                if (Scommand == 1)
                {
                    CreateNode();
                    Structure();
                }
                else if (Scommand == 2)
                {
                    EditContacts();
                    Structure();
                }
                else if (Scommand == 3)
                {
                    DeleteContactBySearch();
                    Structure();
                }
                else if (Scommand == 4)
                {
                    Search();
                    Structure();
                }
                else if (Scommand == 5)
                {
                    Display();
                    Structure();
                }
                else if (Scommand == 6)
                {
                    DeleteAllContacts();
                    Structure();
                }
            }
            else
            {
                throw (Scommand);
            }
        }
        catch (int Scommand)
        {
            // Handle the exception if the user enters an invalid command
            cout << " You Enter wrong Command Run the Code Again" << endl;
            Structure();
        }
    }
};

// Main function
int main()
{
    ContactBook cb;
    string n;
    cout << " What is Your Name: ";
    cin >> n;
    cout << "\n DSA MINI PROJECT" << endl;
    cout << " \n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME " << n << " TO CONTACTBOOK  !!!!!!!!!!!!!!!!!!!! " << endl;
    cout << "\nThis thing makes our life easier" << endl;
    cb.Structure();
    return 0;
}