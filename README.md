# 📒 ADDRESS BOOK MANAGEMENT SYSTEM

### Contact Management Application | C Programming | File Handling

<div align="center">

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=700&size=22&pause=1000&color=00E5A8&center=true&vCenter=true&width=800&lines=Managing+Contacts+Using+C;Structures+%7C+Pointers+%7C+File+Handling;CRUD+Operations+in+C;Building+Logic+Through+Programming" alt="Animated project heading"/>

<br/>

<img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c"/>
<img src="https://img.shields.io/badge/Concept-Data%20Structures-00A98F?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Storage-CSV-orange?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Platform-Linux-FCC624?style=for-the-badge&logo=linux"/>

**PURUSHOTHAMA K | EMBEDDED SOFTWARE ENGINEER ASPIRANT**

</div>

---

## `01 / PROJECT OVERVIEW`

### Building a Contact Management Application from Scratch

The Address Book Management System is a menu-driven application developed using C programming to manage contact information efficiently.

The application allows users to add, search, modify, delete and display contact records.

Contact details are organized using structures, while file handling provides persistent storage through a CSV file.

**Engineering objective:** Develop a structured C application that demonstrates data organization, memory handling, modular programming and file operations.

---

## `02 / KEY FEATURES`

| Feature | Description |
|---|---|
| Add Contact | Store new contact information |
| Search Contact | Find an existing contact |
| Modify Contact | Update stored contact details |
| Delete Contact | Remove a contact record |
| Display Contacts | List available contacts |
| File Storage | Save and retrieve contact information |

### Contact Information Structure

Each contact contains:

- Name
- Phone Number
- Email Address

---

## `03 / SYSTEM ARCHITECTURE`

### Application Workflow

```text
        ┌────────────────────┐
        │    APPLICATION     │
        │       START        │
        └──────────┬─────────┘
                   │
                   ▼
        ┌────────────────────┐
        │    DISPLAY MENU    │
        └──────────┬─────────┘
                   │
                   ▼
        ┌────────────────────┐
        │   USER SELECTION   │
        └──────────┬─────────┘
                   │
          ┌────────┼────────┐
          │        │        │
          ▼        ▼        ▼
        ADD     SEARCH    MODIFY
          │        │        │
          └────────┼────────┘
                   │
             ┌─────┴─────┐
             │           │
             ▼           ▼
           DELETE      DISPLAY
             │           │
             └─────┬─────┘
                   │
                   ▼
        ┌────────────────────┐
        │   CSV FILE STORAGE │
        └──────────┬─────────┘
                   │
                   ▼
             CONTINUE / EXIT
```

---

## `04 / HOW THE APPLICATION WORKS`

### STEP 01 — Application Initialization

The program starts by initializing the contact management application and loading existing records from the CSV file, according to the implemented file-handling logic.

### STEP 02 — Menu-Driven Interaction

The user selects an operation from the application menu.

### STEP 03 — Contact Data Management

The selected operation processes contact information using structures and functions.

### STEP 04 — Record Processing

The application performs the requested operation, such as searching for a contact or updating existing information.

### STEP 05 — File Persistence

The contact records are stored in a CSV file so they can be retrieved during subsequent executions.

### STEP 06 — Application Continuation

The menu continues until the user selects the exit option.

---

## `05 / DATA STRUCTURE DESIGN`

### Using Structures to Organize Contact Information

A C structure allows related information to be grouped under a single data type.

```c
struct contact
{
    char name[50];
    char phone[15];
    char email[50];
};
```

### Contact Management

The application uses structured contact records to manage information such as names, phone numbers and email addresses.

This makes it easier to pass and process contact details through different functions.

---

## `06 / FILE HANDLING AND DATA STORAGE`

### Persistent Storage Using CSV

The application uses file handling to maintain contact records.

Example CSV representation:

```text
contactCount
2
name,phone,email
Rahul,9876543210,rahul@example.com
Arun,9876501234,arun@example.com
```

*Illustrative data format. Replace it with the exact format produced by your program.*

### File Handling Concepts

| Function | Purpose |
|---|---|
| `fopen()` | Open a file |
| `fclose()` | Close a file |
| `fscanf()` | Read formatted data |
| `fprintf()` | Write formatted data |
| `fgets()` | Read a line |
| `fputs()` | Write a string |

---

## `07 / CORE C PROGRAMMING CONCEPTS`

| Concept | Application |
|---|---|
| Structures | Organizing contact information |
| Arrays | Managing contact records |
| Pointers | Passing and accessing data |
| Functions | Modular program design |
| Strings | Processing names and emails |
| File Handling | Persistent storage |
| Conditional Statements | Menu-based decision making |
| Loops | Repeated application execution |

---

## `08 / DEVELOPMENT ENVIRONMENT`

| Category | Technology |
|---|---|
| Language | C |
| Compiler | GCC |
| Platform | Linux / Windows compatible environment |
| Data Storage | CSV file |
| Programming Style | Modular and structured programming |

---

## `09 / PROJECT STRUCTURE`

```text
C-Address-Book/
│
├── src/
│   └── main.c
│
├── data/
│   └── contacts.csv
│
├── README.md
└── .gitignore
```

*Update this structure to match your actual uploaded source files.*

---

## `10 / BUILD AND EXECUTION`

### Compilation

```bash
gcc main.c -o addressbook
```

### Run on Linux

```bash
./addressbook
```

### Run on Windows

```bash
addressbook.exe
```

If your project has multiple source files, include all required `.c` files in the compilation command.

---

## `11 / ENGINEERING SKILLS DEVELOPED`

- C programming fundamentals.
- Structures and arrays.
- Pointer-based data handling.
- Modular programming.
- File input and output operations.
- String manipulation.
- Menu-driven application design.
- Persistent data management.

---

## `12 / FUTURE ENHANCEMENTS`

- [ ] Add dynamic memory allocation.
- [ ] Improve input validation.
- [ ] Implement duplicate contact detection.
- [ ] Add sorting functionality.
- [ ] Improve search efficiency.
- [ ] Introduce better error handling.

---

## `13 / ABOUT THE DEVELOPER`

<div align="center">

### PURUSHOTHAMA K

**C Programming | Embedded Systems | Software Development**

Electrical and Electronics Engineering Graduate

Interested in developing efficient software, understanding system-level programming and building practical embedded applications.

[![GitHub](https://img.shields.io/badge/GitHub-My%20Profile-181717?style=for-the-badge&logo=github)](https://github.com/kpurushothama446-droid)

</div>

---

<div align="center">

### WRITE CLEAN CODE. MANAGE DATA. BUILD REAL APPLICATIONS.

**DESIGN | DEVELOP | DEBUG**

</div>
