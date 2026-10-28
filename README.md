# Student Management System

A file-based student record management application built with C++17.

The application provides a menu-driven interface for managing student information, with local file storage to preserve records between program executions.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Technology Stack](#technology-stack)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Data Storage](#data-storage)
- [Testing](#testing)
- [Limitations](#limitations)
- [Future Enhancements](#future-enhancements)

## Overview

Student Management System is a command-line application designed to simplify basic student record management. It supports creating, retrieving, modifying, and deleting records through a simple interactive menu.

The application uses `std::vector` to manage student records in memory and C++ file streams to load and save data locally. This allows changes to remain available after the application closes and starts again.

Each student record contains the following fields:

- Student ID
- Name
- Age
- Course
- Marks

## Features

| Feature | Description |
|---|---|
| Add student | Create a record containing student details. |
| Display students | View the stored records in a formatted table. |
| Search student | Find a record using its student ID. |
| Update student | Modify the details of an existing record. |
| Delete student | Remove a record from the collection. |
| File persistence | Load saved records at startup and save changes to local storage. |

## Technology Stack

- **Language:** C++
- **Language standard:** C++17
- **Data structures:** `std::vector`
- **File handling:** `std::ifstream`, `std::ofstream`
- **Record parsing and formatting:** `std::quoted`
- **Development environment:** Ubuntu Linux and Visual Studio Code

## Project Structure

```text
StudentManagementSystem/
├── main.cpp       # Application source code
├── README.md      # Project documentation
├── .gitignore     # Files excluded from version control
└── students.txt   # Local data file, created or used at runtime
```

The compiled executable is generated during compilation and is not required as a source file.

## Getting Started

### Prerequisites

- Ubuntu Linux or a compatible environment
- GNU C++ compiler with C++17 support
- Terminal access

Install the compiler on Ubuntu if necessary:

```bash
sudo apt update
sudo apt install g++
```

### Build

Clone the repository after it has been published:

```bash
git clone <repository-url>
cd StudentManagementSystem
```

Compile the application:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o StudentManagementSystem
```

### Run

```bash
./StudentManagementSystem
```

## Usage

After launching the application, use the menu to select an operation.

| Option | Operation |
|---:|---|
| `1` | Add Student |
| `2` | Display All Students |
| `3` | Search Student |
| `4` | Update Student |
| `5` | Delete Student |
| `0` | Exit |

Follow the prompts to enter the required student details or select the record to modify.

## Data Storage

Student records are stored locally in `students.txt`.

The application reads existing records when it starts and writes the updated collection to the file when record-management operations save changes.

This approach provides basic persistence without requiring an external database or server.

The data file is intended for local application use. Do not commit real student information to a public repository.

## Testing

Manual functional testing has been performed for the core operations.

| Test | Status |
|---|---|
| Add and display a student record | Passed |
| Search for a student | Passed |
| Update student details | Passed |
| Persist updated details after restarting | Passed |
| Delete a student record | Passed |
| Persist deletion after restarting | Passed |

These results are based on manual tests; an automated test suite has not yet been implemented.

## Limitations

- Data is stored in a local text file rather than a database.
- The application uses a command-line interface.
- Automated testing and comprehensive input validation are not yet implemented.
- Local records are not designed for concurrent access by multiple users.

## Future Enhancements

- Add stronger input validation and duplicate-ID checks.
- Introduce automated unit and integration tests.
- Add sorting and filtering capabilities.
- Support CSV import and export.
- Introduce database-backed storage.
- Develop a graphical user interface.

