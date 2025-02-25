#pragma once
#ifndef FUNCTIONALITIES_H_
#define FUNCTIONALITIES_H_

#include "utils.h"

// function for creating an account
void Create_account(char Filename[], char Owner[]);

// Function for viewing an account
void View_account(char Filename[]);

// Editing acounts
void Edit_account(char ColumnToEdit[], char Filename[]);

// Function for deleting an account
void deleteAccount(char Filename[]);

// Transaction between two accounts
void Transactions(char Filename1[], char Filename2[]);

// create a new account to an already existing .csv file with the same owned by the same person
void Create_new_account(char Filename[], char Owner[]);

#endif