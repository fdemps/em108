#include <stdio.h>
#include <stdlib.h>


/* structured type definition */
typedef struct item_type_tag
{
char name[20];
char brand[20];
char hobby_name[20];
float price;
float discount;
float final_price;
}  item_type;


/* declarations */
/* function that reads data from a file, stores it in an array and returns the number of records read*/
int read_records (char*file_name, item_type items[]);

/*scan for the name and brand*/
void scan(item_type items[],char item_hobby[], char item_brand[], int norecs);

/*given hobby and brand, calculates their price and overall price*/
void apply_discount (item_type items[], int norecs);

/*write the file, using the name given by user*/
void write_items (char* file_name,item_type items[], int norecs);

/*check for all students which have the same first letter in name as the letter introduced form keyboard*/
//void char_letter(item_type items[],char letter[],int norecs, char answer_1[],char answer_2[]);
/*Convert the answers to "y" and " "*/
//void convert(item_type items[], int norecs, char letter[],char answer_1[],char answer_2[]);




/* main function */
int main()
{

/* 1-dimensional array that stores related data for all items in the store*/
item_type items[1000];


/* no current registered dogs (no records) */
int norecs = 0,norecs_b,norecs_g,change, answer;
int i, records=0,p,r;
char item_hobby[20],item_brand[20];
/* file name */
char file[20], name[20];
char letter[20];

/* welcome messhobby_name */
	printf("Welcome to the X-MAX 5000!\n");

	do
   {
	printf("MENU\n");
	printf("Read Files and display there inputs     {1}\n");
	printf("Search for name and brand               \n");
	printf("and calculate the price                 {2}\n");
	printf("Question3                               {3}\n");
	printf("Save the file                           {4}\n");
	printf("Exit the program                        {5}\n");
    printf("Enter your choice:\n");
    scanf("%d", &answer);

	switch(answer)
{
/* read the files*/
case 1:
    if(records <1)/*it will not allow to read the files more than one time */
        {
printf("Enter the input file name:\n");
norecs_g = read_records("items1.txt", items);/*record the first file*/
norecs= read_records("items2.txt", items);/*record the second file*/


/*print the inputs*/
for(i=0;i<norecs;i++){
if(i<norecs_g) /*if i is smaller than the norecs_g will display the gender*/
    {
    printf("|shop1|");
}
else/*when the i is biger than norece_g, change the hander to items2*/
{
    printf("|shop2|");
}
/*print the inputs*/
    printf("%s %s %s %.2f %.2f\n", items[i].name, items[i].brand,
items[i].hobby_name, items[i].price, items[i].discount);

}
records++;/*record the number of reads*/
	break;
    }
    else/*stops the user to read the files more than one time */
        {
        printf("The files are already read!\n\n");/*Error messhobby_name*/
    };

break;

case 2:
/*search for the hobby */
printf("Enter the hobby\n");
/*introduce the name from the keyboard */
scanf("%s", item_hobby);
/*search for the brand */
printf("Enter the brand\n");
/*introduce the name from the keyboard */
scanf("%s", item_brand);
/* print results */
scan(items, item_hobby,item_brand, norecs);

    break;
case 3:
/*Print all results with star with the same letter*/
  //  printf("Enter the letter\n");
  //  scanf("%s", letter);/*introduce the letter form the keyboard */
  //  char_letter(items,letter,norecs,answer_1,answer_2);
    break;
case 4:
    /*write the files  */
   printf("Enter the input file name:\n");
   scanf("%s", file);/*introduce the name of file from the keyboard */
/* read records */
    write_items(file, items,norecs);
	break;
//case 6:
    /*Exit program */
	printf("Goodbye!\n");
		break;
}
   }while (answer != 3); /*if it is introduce a number smaller than 6, repeat*/


return (EXIT_SUCCESS);
}

/* function definitions */

int read_records (char*file_name, item_type items[])
{
	FILE* fp;
	int norecs,p=0,r=0;
    char ch;
	/* open file */
	fp = fopen(file_name, "r");

	while(!feof(fp))/*read till you reach the end of the file  */
{
	/* read on record from file */
 	fscanf(fp, "%s%c%s%c%s%c%f%c%f",
items[norecs].name, &ch,
items[norecs].brand, &ch,
items[norecs].hobby_name, &ch,
&items[norecs].price, &ch,
&items[norecs].discount);
/* increase the number of records read */
norecs++;
}
/* close file */
fclose(fp);
return norecs;

}

//Search for a name and apply discount
void scan(item_type items[],char item_hobby[], char item_brand[], int norecs)
{
    int i;
    float price;

    for (i = 0; i < norecs; i++)
    {  if (strcmpi(items[i].brand, item_brand)==0 && strcmpi(items[i].hobby_name, item_hobby)==0 )
{
       apply_discount (items,norecs);
           //Print the results
    printf("\n| name | brand | hobby name | price | discount | final price | \n");

printf("%s %s %s %.1f %.1f %.1f\n", items[i].name, items[i].brand, items[i].hobby_name, items[i].price,items[i].discount, items[i].final_price);
break;
    }
    }
//Error message if a name is not in the database
    //Check each name for a match
    if ((strcmpi(items[i].hobby_name, item_hobby)!=0 || strcmpi(items[i].brand, item_brand)!=0) )
    {
    printf("\nThe name is not found\n ");

        }}



void apply_discount (item_type items[], int norecs)
{
    int i;
    for (i = 0; i < norecs; i++)
    {
        items[i].final_price= items[i].price-(items[i].price*(items[i].discount/100));
    }
}


/*Write the files, with the name inputed by user*/
void write_items (char* file_name,item_type items[], int norecs)
{
	FILE* fp;
int i;

	/* open file */
	fp = fopen(file_name, "w");

fprintf(fp,"| name | brand | hobby_name | price | discount |\n");

	for (i = 0; i < norecs; i++){
	/* read on record from file */

fprintf(fp,"%s %s %s %f %f %d\n", items[i].name, items[i].brand,
items[i].hobby_name, items[i].price, items[i].discount);

	}
/* flush content into file */
fflush(fp);

/* close file */
fclose(fp);
}

