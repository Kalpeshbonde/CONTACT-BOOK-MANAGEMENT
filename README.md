
# CONTACT-BOOK-MANAGEMENT

A console-based Contact Book Management system in C++ that allows users to store, update, delete, and search for contacts. The project implements a doubly linked list to manage contact information such as names, phone numbers, and email addresses.

## Features

- **Add New Contact**: Insert new contact details (Name, Phone Number, and Gmail).
- **View Contacts**: Display all contacts in sorted order (by name).
- **Update Contact**: Update the name, phone number, or email of an existing contact.
- **Delete Contact**: Remove a contact from the contact book by name.
- **Search Contacts**: Search for contacts by name, phone number, or Gmail.
- **Remove Duplicate Contacts**: 
  - Delete contacts with the same name.
  - Delete contacts with the same phone number.
  - Delete contacts with the same Gmail.
- **Sort Contacts**: Automatically sort contacts by name after every insertion or update.

## Data Structure Used

The project uses a **Doubly Linked List** to store and manage contact details. This allows for efficient insertion, deletion, and traversal in both directions.

## How to Use

1. **Clone the Repository**  
   Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/CONTACT-BOOK-MANAGEMENT.git
   ```

2. **Compile and Run the Program**
   Compile the program using a C++ compiler, and run the executable:
   ```bash
   g++ contact_book.cpp -o contact_book
   ./contact_book
   ```

3. **Follow the On-Screen Instructions**
   After running the program, you will be prompted to:
   - Add contacts.
   - View or search for contacts.
   - Update or delete existing contacts.
   - Remove duplicate entries.

## Menu Options

- `1. Display Contacts`: View all contacts sorted by name.
- `2. Insert New Contact`: Add a new contact to the phone book.
- `3. Update Details on Existing Contact`: Modify the contact details for a specific person.
- `4. Delete Contact`: Remove a contact by name.
- `5. Delete Same Names in Phonebook`: Remove duplicate contacts with the same name.
- `6. Delete Same Numbers in Phonebook`: Remove duplicate contacts with the same phone number.
- `7. Search Contact`: Search for a contact by name, number, or Gmail.
- `8. Delete Same Gmails in Phonebook`: Remove duplicate contacts with the same Gmail.

## Project Structure

```bash
.
├── contact_book.cpp  # The main source file containing the code
├── README.md         # Project documentation
```

## Requirements

- C++ Compiler (e.g., g++)

## Contributing

Feel free to contribute to this project by forking the repository, making changes, and submitting a pull request.

1. Fork the repository.
2. Create a new feature branch.
3. Commit your changes.
4. Push to the branch.
5. Create a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
