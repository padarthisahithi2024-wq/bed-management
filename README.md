# bed-management

🧑‍⚕️ Hospital Bed Management System (C Program)
A simple and efficient menu-driven Hospital Bed Management System written in C.
This program allows hospital staff to store, manage, update, and search bed–patient allocation details using structures and binary file storage.

👉 Abstract
The Hospital Bed Management System is a lightweight, console-based C application built to help healthcare facilities efficiently manage bed assignments. The program allows users to add new beds, allocate patients to beds, update bed status (Available/Occupied), search for a specific bed, view all bed records, and delete bed entries when necessary. All bed information—including bed ID, ward name, bed type, status, and patient details—is stored persistently in a binary .dat file, ensuring data remains saved even after the program terminates.
Designed with a simple menu-driven structure, the system is easy to use and suitable for small hospitals, clinics, or academic projects. It demonstrates fundamental C programming skills such as structures, file I/O operations, conditional logic, loops, and text-based navigation. This project provides a clear and practical solution for maintaining hospital bed information in a structured and efficient manner.

👉 Features of the Program

✔ Add New Hospital Bed

Enter bed ID

Enter ward name

Select bed type (ICU / General)

Set bed status (Available / Occupied)

Input patient name if bed is occupied

Save record to binary file


✔ View All Beds

Displays:

Bed ID

Ward

Type

Status (Available/Occupied)
Patient Name


✔ Search for a Bed

Search by bed ID


Shows complete details if found


Displays a warning if bed does not exist


✔ Update Bed Details

Change bed status


Update patient name


Automatically clears patient name if bed is set to "Available"


✔ Delete Bed

Remove a bed record from the system


Confirms deletion before removing


Rewrites updated bed list to binary file


✔ Persistent Data Storage

All records stored in beds.dat


Uses fwrite() and fread() for binary file handling


Automatically creates the data file if missing


✔ User-Friendly Menu
Easy navigation


Runs in a loop until user selects Exit


Simple terminal interface suitable for beginners



👉 Technical Requirements

1. System Requirements

Operating System: Windows / Linux / macOS


Terminal or command-line environment


Minimum RAM: 4 MB


Very small disk usage (only beds.dat)



2. Software Requirements

C Compiler: GCC / Clang / MinGW / MSVC


Any editor or IDE: VS Code, Code::Blocks, Dev-C++, Notepad++, Vim, etc.


Optional: Make tool (if using makefile)



3. Programming Requirements

Language: C


Supported Standards: C89 / C99 / C11


Standard Libraries Used
#include <stdio.h>     // Input/output and file operations
#include <stdlib.h>    // General utilities
#include <string.h>    // String functions (fgets, strcmp, etc.)


4. File Handling Requirements

Binary file: beds.dat


Each Bed record is stored using:
fwrite() → Write structure to file


fread() → Read structure from file


Program guarantees:
Creates beds.dat automatically if missing


Loads all beds into array when updating or deleting


Saves modified list back to the file



5. Compilation Requirements
Compile with recommended flags:
gcc bed_management.c -o bed_management -Wall -Wextra

Zero compilation errors expected.

👉 Functional Requirements
1. User Interface
Completely terminal-based


Displays simple and clean menu options


Validates user inputs where needed


Runs continuously until Exit option is selected



2. Bed Management Operations
✔ Add Bed
Input Bed ID


Prevent duplicate entries


Assign ward, bed type, status


Input patient name if Occupied


Save to binary file


✔ View All Beds
Displays list with:
Bed ID


Ward


Type


Status


Patient Name


Fetched directly using fread().

✔ Search Bed
Searches by Bed ID


Shows full details if found


Displays message if not found



✔ Update Bed
Loads all beds into an array


Allows editing status and patient name


Clears patient info when status becomes Available


Saves updated beds back to file



✔ Delete Bed
Loads all beds


Finds record and confirms removal


Deletes the bed entry


Writes updated list back to beds.dat



3. Data Management
All bed records stored persistently


Data survives after program exits


Handles missing file safely


Uses structure arrays while editing/deleting



4. Program Flow
Main menu loop


Repeats until user chooses Exit


Displays clear success/error messages


Smooth navigation between operations

5.screenshots : 
<img width="476" height="616" alt="Screenshot 2025-11-21 175741" src="https://github.com/user-attachments/assets/b7825910-e4e1-455a-8e3e-a9af3d556a5a" />
<img width="572" height="897" alt="Screenshot 2025-11-21 175706" src="https://github.com/user-attachments/assets/8c9357d0-db88-496e-9b8f-a7445ceb622a" />
<img width="872" height="367" alt="Screenshot 2025-11-21 175634" src="https://github.com/user-attachments/assets/1b2f26a8-2af2-403c-b522-2b6138813388" />
<img width="547" height="521" alt="Screenshot 2025-11-21 175608" src="https://github.com/user-attachments/assets/ca22da70-ab37-48d7-a09c-d1ef07e82ac3" />


👉 How to Run the Program
1. Compile
In terminal:
gcc bed_management.c -o bed_management

2. Run
Linux/macOS:
./bed_management

Windows:
bed_management.exe

3. Data File
Program auto-creates beds.dat


All records are stored and retrieved from this file

