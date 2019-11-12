#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool pre_check(char ISBN_num[50]);
bool valid_check(char ISBN_num[50]);

int main()
{
  char ISBN_num[50];

  while (true)
  {
    printf("Enter IBSN number: ");
    scanf("%s", ISBN_num);
    if (strlen(ISBN_num) == 1 && ISBN_num[0] == '0')
      {
        printf("Good day!");
        break;
      }
    if (pre_check(ISBN_num))
    {
      printf("Pre-Check: Good\n");
      if (valid_check(ISBN_num))
      {
        printf("Valid ISBN.\n");
      }
    }
  }

  return 0;
}

bool pre_check(char ISBN_num[50])
{
  int digits = 0;
  int hyphens = 0;
  for (int i = 0; i < strlen(ISBN_num); i++)
  {
    if (!isdigit((int)(ISBN_num[i])) && ISBN_num[i] != '-')
    {
      printf("Invalid ISBN. Input should only contain digits and hyphens.\n");
      return 0;
    }
    if (ISBN_num[i] == '-')
      hyphens++;
    if (isdigit(ISBN_num[i]))
      digits++;
  }
  if (digits < 13)
  {
    printf("Invalid ISBN. Less than 13 digits.\n");
    return 0;
  }
  else if(digits > 13)
  {
    printf("Invalid ISBN. More than 13 digits.\n");
    return 0;
  }
  if (hyphens != 4) //Check Valid Length (17: 13digits and 4 hyphens)
  {
    printf("Invalid ISBN. ISBN has 5 elements separated by hyphens.\n");
    return 0;
  }
  return 1;
}

bool valid_check(char ISBN_num[50])
{
  char Prefix, Reg_group, Registrant, Public, Check, ISBN_full;

  int validation, number;
  int i = 0;
  //Break ISBN into components
  char* component = strtok(ISBN_num,"-");


  while (component != 0 || i == 5)
  {
    switch (i)
    {
      case 0:
      //strcpy(Prefix, *component);
      Prefix = *component;
      strcat(ISBN_full, component);
      break;

      case 1:
      //strcpy(Reg_group, *component);
      Reg_group = *component;
      strcat(ISBN_full, *component);
      break;

      case 2:
      //strcpy(Registrant, *component);
      Registrant = *component;
      strcat(ISBN_full, *component);
      break;

      case 3:
      //strcpy(Public, *component);
      Public = *component;
      strcat(ISBN_full, *component);
      break;

      case 4:
      //strcpy(Check, *component);
      Check = *component;
      strcat(ISBN_full, *component);
      break;
    }
      component = strtok(NULL,"-");
      i++;
  }
  printf(ISBN);

  for (int i = 0; i < strlen(ISBN); i++)
  {
    if (i % 2)
      number = 3*(int)(ISBN[i]);
    else
      number = (int)(ISBN[i]);
    validation =+ number;
  }

  if (Prefix != "978" || Prefix != "979")
  {
    printf("Invalid ISBN. Prefix element must be either 978 or 979.\n");
    return 0;
  }
  if (strlen(Reg_group) < 1 || strlen(Reg_group) >5)
  {
    printf("Invalid ISBN. Registration group element must have 1 to 5 digits.\n");
    return 0;
  }
  if (strlen(Reg) < 1 || strlen(Reg) > 7)
  {
    printf("Invalid ISBN. Registrant element must have 1 to 7 digits.\n");
    return 0;
  }
  if (strlen(Public) < 1 || strlen(Public) > 6)
  {
    printf("Invalid ISBN. Publication element must have 1 to 6 digits.\n");
    return 0;
  }
  if (strlen(Check) != 1)
  {
    printf("Invalid ISBN. Check digit must have exactly 1 digit.\n");
    return 0;
  }
  if (validation !% 10)
  {
    printf("Invalid ISBN. Failed validation test.\n");
    return 0;
  }

}
