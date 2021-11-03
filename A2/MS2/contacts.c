//==============================================
// Name:           Bair Suimaliev
// Student Number: 159350198
// Email:          bsuimaliev@myseneca.ca
// Section:        IPC
// Date:           11.10.2020
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"


// getName:
void getName(struct Name* name)
{
    int yesNo;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    yesNo = yes(); //yes funtction instead of using scanf for reading input

    if (yesNo == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
    }
    else {
        *name->middleInitial = '\0';
    }
    clearKeyboard();

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    int yesNo;

    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();
    while (address->streetNumber < 0) { //the loop for prompting the user a valid input if the entered int was negative
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
    }
    

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
        while (address->apartmentNumber < 0) { //the loop for prompting the user a valid input if the entered int was                                                                                                      negative
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }

    else {
        address->apartmentNumber = 0;
    }
    
    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    int yesNo;

    printf("Please enter the contact's cell phone number: ");
    scanf("%20[^\n]%*c", numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", numbers->home);
    }
    else {
        *numbers->home = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", numbers->business);
    }
    else {
        *numbers->business = '\0';
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 2 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contact) {
    struct Contact contactf;
    getName(&contactf.name);
    getAddress(&contactf.address);
    getNumbers(&contactf.numbers);

    *contact = contactf;
}