/*
  RMIT University Vietnam
  Course: EEET2448 Comp Eng/EEET2601 Eng Comp 1
  Semester: 2019C
  Assessment: Assessment 1
  Author: Tran Viet Quan
  ID: 3515271
  Created  date: 11/11/2019
  Last modified: 13/11/2019 (e.g. 05/04/2019)
  Acknowledgement: Use fresh2refresh.com C's library
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    while (1)
    {
        //Declare variables
        char prefix[7] = "", reg_group[7] = "", registrant[7] = "", public[7] = "", check[7] = "", isbn[13] = "";
        int validation = 0, number, last_hyphen = 0, component_number = 0, i = 0, digits = 0, hyphens = 0, cout_hyphen = 0;
        int digitandhyphen = 1; //Act like a bool
        // Get input
        char ISBN_num[20];
        printf("Enter ISBN number: ");
        scanf("%s", ISBN_num);

        if (strlen(ISBN_num) == 1 && ISBN_num[0] == '0') //Exit if input is 0
        {
            printf("Good day!");
            break;
        }
        digits = 0;
        hyphens = 0;
        for (int i = 0; i < strlen(ISBN_num); i++) //Get number of digits and hyphens
        {
            if (!isdigit((int)(ISBN_num[i])) && ISBN_num[i] != '-') //if contain anything besind digit and hyphen, return warning ask for new input
            {
                printf("Invalid ISBN. Input should only contain digits and hyphens.\n");
                digitandhyphen = 0;
                break;
            }
            if (ISBN_num[i] == '-') //Get nummber of digits
                hyphens++;
            if (isdigit(ISBN_num[i])) //Get nummber of hyphens
                digits++;
        }
        if (digitandhyphen == 0)
            continue;

        if (digits < 13)
        {
            printf("Invalid ISBN. Less than 13 digits.\n");
            continue;
        }
        else if(digits > 13)
        {
            printf("Invalid ISBN. More than 13 digits.\n");
            continue;
        }

        if (hyphens != 4 )
        {
            printf("Invalid ISBN. ISBN has 5 elements separated by hyphens.\n");
            continue;
        }

        //Break ISBN into components
        for (int i = 0; i < strlen(ISBN_num); i++)
        {
            int INDEX = 0;
            int ISBNINDEX = strlen(isbn);
            char component[7] = "";

            if (i == strlen(ISBN_num) - 1)
            {
                component_number = 5;
                for (int j = last_hyphen; j < strlen(ISBN_num); j++)
                {
                    component[INDEX + (j - last_hyphen)] = ISBN_num[j];
                    check[INDEX + (j - last_hyphen)] = ISBN_num[j];
                }
            }
            else if (ISBN_num[i] == '-' && i != strlen(ISBN_num) - 1)
            {
                if (cout_hyphen == 0)
                {
                    component_number = 1;
                    for (int j = 0; j < i; j++)
                    {
                        component[INDEX + j] = ISBN_num[j];
                    }
                    strcpy(prefix,component);
                    strcat(isbn, component);
                }
                else
                {
                    component_number++;
                    for (int j = last_hyphen; j < i; j++)
                    {
                        component[INDEX + (j - last_hyphen)] = ISBN_num[j];
                    }
                    if (component_number == 2)
                    {
                        strcpy(reg_group, component);
                        strcat(isbn, component);
                    }
                    else if (component_number == 3)
                    {
                        strcpy(registrant, component);
                        strcat(isbn, component);
                    }
                    else if (component_number == 4)
                    {
                        strcpy(public, component);
                        strcat(isbn, component);
                    }
                }
                cout_hyphen++;
                last_hyphen = i + 1;
            }

        }

        //Check ISBN's validation
        // Check Prefix's valid or not
        if (atoi(prefix) != 978)
        {
            if (atoi(prefix) != 979)
            {
                printf("Invalid ISBN. Prefix element must be either 978 or 979.\n");
                continue;
            }
        }

        // Check Registration Group's valid or not
        if (strlen(reg_group) < 1 || strlen(reg_group) > 5)
        {
            printf("Invalid ISBN. Registration group element must have 1 to 5 digits.\n");
            continue;
        }

        // Check Registration's valid or not
        if (strlen(registrant) < 1 || strlen(registrant) > 7)
        {
            printf("Invalid ISBN. Registrant element must have 1 to 7 digits.\n");
            continue;
        }

        // Check Publication's valid or not
        if (strlen(public) < 1 || strlen(public) > 6)
        {
            printf("Invalid ISBN. Publication element must have 1 to 6 digits.\n");
            continue;
        }

        // Check Check's valid or not
        if (strlen(check) != 1)
        {
            printf("Invalid ISBN. Check digit must have exactly 1 digit.\n");
            continue;
        }
        strcat(isbn, check);

        //Make validation's number
        for (int i = 0; i < strlen(isbn); i++)
        {
            if ((i + 1) % 2 == 0)
                validation += 3 * (isbn[i] - '0');
            else
                validation += (isbn[i] - '0');
        }

        if (validation % 10 != 0)
        {
            printf("Invalid ISBN. Failed validation test.\n");
            continue;
        }

        printf("Valid ISBN.\n");
    }

    return 0;
}
