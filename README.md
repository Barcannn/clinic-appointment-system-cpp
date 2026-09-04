# Clinic Appointment System(C++)

A console-based clinic appointment management system developed in C++ as an object-oriented programming project.

## Features

- Create appointments using patient name, doctor, date and time
- Display available time slots for a selected doctor and date
- Prevent double booking for the same doctor, date, and time
- List all registered appointments
- Display doctors' appointment schedules
- List general appointment hours
- List doctors and their medical specialties
- Return to the main menu after each operation

## Doctors

- DR.AHMET - Ear, Nose and Throat

- DR.AYSE - Neurology

- DR.FEDAI - Chest Diseases

- DR.GONUL - Dentistry

- DR.CAKI - Urology

## Available Hours 

- 09:00
- 10:00
- 11:00
- 14:00
- 15:00

## Concepts Used 
- Objects-oriented programming
- Classes and objects 
- Encapsulation
- Constructors 
- `std::vector`
- Loops and conditional statements 
- Functions 
- References and `const`
- Console input and output 

## Build and Run

Compile:

```bash
clang++ -std=c++14 main.cpp -o main
```

Run: 

```bash 
./main
```

## Date Format

Enter appointment dates using the following format:

```text
DD-MM-YYYY
```

## Future Improvements 

- Input and date validation
- Saving appointments to a file
- Appointment cancellation
- Automated tests 
- Graphical user interface








