#pragma once
#ifndef FUNCTIONALITIES_H_
#define FUNCTIONALITIES_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>

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

#endif