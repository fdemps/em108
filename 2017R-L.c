//This code will read the files from two different files and add the togehther into a single array
 /*Declare the libraries */
#include <stdio.h>
#include <stdlib.h>

//Structure used
typedef struct item_type_tag
{
char name[20];
char brand[20];
char hobby_name[20];
float price;
float discount;
float price_final;
}  item_type;


/* Declaration of the void */
/* function that reads data from a file, stores it in an array and returns the number of records read*/
int read_records(char*file_name, item_type items[]);
/*scan for the name of the item and display the result. Also ask if it will go to swimming and movie if it is the case */
void scan(item_type items[],char brand[],char hobby[], int norecs);

void scan_shop(item_type items[],int shop,char hobby[], int norecs,int norecs_1);

/*write the file, using the name given by user*/
void write_items (char* file_name,item_type items[], int norecs, int norecs_1);

void scan_hobby(item_type items[],char hobby[], int norecs);


/*Insert and exacute the void via a manu */
int main()
{

/* 1-dimensional array that stores dog-related data for all dogs in the store*/
item_type items[1000];


/* no current registered dogs (no records) */
int norecs = 0,norecs_1, answer;
int i, records=0,shop;
/* file name */
char brand[20], hobby[20];
char letter[20];
char file[20];



/* welcome message */
	printf("Welcome to the X-MAX 5000!\n");

	do
   {
	printf("MENU\n");
	printf("Read Files and display their inputs     {1}\n");
	printf("Scan for hobby and brand                {2}\n");
	printf("Scan for hobby in shop 1 or shop 2      {3}\n");
	printf("Write the files                         {4}\n");
	printf("Find all items with the same hobby      {5}\n");
	printf("Exit the program                        {6}\n");

    scanf("%d", &answer);

	switch(answer)
{

case 1:
    if(records <1)
    //it will not allow the files to be read more than one time
        {
            printf("They are the files data \n");
            /*if this part is taken out the code will not work*/

            //Declare the files to be read
            //Record the first file
            norecs_1 = read_records("items1.txt", items);
            //Record the second file
            norecs= read_records("items2.txt", items);

            //Print the records
            for(i=0;i<norecs;i++)
            {
                //Prints shop1 for each data entry in items1.txt
                if(i<norecs_1)
                {
                    printf("|shop1|");
                }
                //Prints shop2 for each data entry in items2.txt
                else
                {
                    printf("|shop2|");
                }
                //Print the records
                printf("%s %s %s %.1f %.1f\n", items[i].name, items[i].brand,
                items[i].hobby_name, items[i].price,items[i].discount);
            }
            //increase the number of reads
            records++;
            break;
    }
    //Stop the user to read the files more than one time
    else
        {
            //Error message
            printf("The files are already read!\n\n");/*Error message*/
        };

    break;

case 2:
/*search for the mane */
printf("\nEnter the brand\n");
scanf("%s", brand);/*introduce the brand form the keyboard */
/* print results */
printf("\nEnter the hobby\n");
scanf("%s", hobby);/*introduce the hobby form the keyboard */
/* print results */
scan(items, brand,hobby, norecs);

	break;
case 3:

printf("\nEnter the hobby\n");
scanf("%s", hobby);/*introduce the hobby form the keyboard */
/* print results */
/*search for the mane */
printf("\nEnter the shop\n");
scanf("%d", &shop);/*introduce the shop form the keyboard */
/* print results */
scan_shop(items, shop,hobby, norecs,norecs_1);

	break;

case 4:
        /*write the files  */
    printf("Enter the input file name:\n");
scanf("%s", file);/*introduce the name of file form the keyboard */
/* read records */
write_items(file, items,norecs,norecs_1);
	break;

case 5:
printf("\nEnter the hobby\n");
scanf("%s", hobby);/*introduce the hobby form the keyboard */
/* print results */
scan_hobby(items,hobby, norecs);

break;

case 6:
printf("bye"); //Exit
break;


}
    } /*While the answer is no biger than 1 */
      while (answer != 6);

return (EXIT_SUCCESS);
}



/*Define the void */

//Define read_records void
int read_records (char*file_name, item_type items[])
{
	FILE* fp;
	int norecs;
    char ch;
	//open file
	fp = fopen(file_name, "r");

	//while to read until you reach the end of the file
	while(!feof(fp))
    {
    //read these records from file
        fscanf(fp, "%s%c%s%c%s%c%f%c%f%c",
            items[norecs].name, &ch,
            items[norecs].brand, &ch,
            items[norecs].hobby_name, &ch,
            &items[norecs].price, &ch,
            &items[norecs].discount, &ch);
    //increase the number of records read
            norecs++;
    }
    //Close file
    fclose(fp);
    return norecs;
}



void scan(item_type items[],char brand[], char hobby[], int norecs)
{
    int i;
    /*Head of the table */
    for (i = 0; i < norecs; i++)
    {
	if (strcmpi(items[i].brand, brand)==0 && strcmpi(items[i].hobby_name, hobby )==0 )/*check each name for a match */

{
    items[i].price_final=items[i].price-(items[i].price*(items[i].discount/100));
    printf("\n| name | brand | hobby | price | discount | total \n");
    /*print the results*/
      printf("%s %s %s %.1f %.1f, %.1f\n", items[i].name, items[i].brand,
                items[i].hobby_name, items[i].price,items[i].discount, items[i].price_final);
break;
    }
    }

        /*Error message if a name is not in the base date */
         if (strcmpi(items[i].brand, brand)!=0 || strcmpi(items[i].hobby_name, hobby )!=0 )/*check each name for a match */
        printf("\nThe name is not found\n ");
        }



void scan_shop(item_type items[],int shop,char hobby[], int norecs, int norecs_1){
      int i,counter=0;
      float temporary_price;
    /*Head of the table */
    if(shop==1){
    for (i = 0; i < norecs_1; i++)
    {
	if (strcmpi(items[i].hobby_name, hobby )==0 ){/*check each name for a match */

    temporary_price=items[i].price-(items[i].price*((items[i].discount+20)/100));

    printf("\n| name | brand | hobby | price | discount | total \n");
    /*print the results*/
      printf("%s %s %s %.1f %.1f, %.1f\n", items[i].name, items[i].brand,
                items[i].hobby_name, items[i].price,items[i].discount, temporary_price);
    }
    {
    if (strcmpi(items[i].hobby_name, hobby )!=0 )
        printf("The hobby can not be found\n");

    }}}


     if(shop==2){
    for (i = norecs_1; i < norecs; i++)
    {
	if (strcmpi(items[i].hobby_name, hobby )==0 ){/*check each name for a match */

    temporary_price=items[i].price-(items[i].price*((items[i].discount+20)/100));

    printf("\n| name | brand | hobby | price | discount | total \n");
    /*print the results*/
      printf("%s %s %s %.1f %.1f, %.1f\n", items[i].name, items[i].brand,
                items[i].hobby_name, items[i].price,items[i].discount, temporary_price);
    }
    if (strcmpi(items[i].hobby_name, hobby )!=0 ){
        printf("The hobby can not be found\n");
    }

    }}
    if(shop!=1&&shop!=2){
        printf("The shop can not be found\n");
    }
    }



void write_items (char* file_name, item_type items[], int norecs, int norecs_1)
{
	FILE* fp;
    int i;

	/* open file */
	fp = fopen(file_name, "w");

fprintf(fp,"|shop no| name | brand | hobby | price | discount | cost \n");

	for (i = 0; i < norecs; i++){
	/* read on record from file */
for(i=0;i<norecs;i++){
/*if i is smaller than the norecs_g will display the gender*/
if(i<norecs_1)
    {
    fprintf(fp,"| 1 |");
    }
else/*when the i is biger than norece_g, change the hander to boys*/
    {
    fprintf(fp,"| 2 |");
    }

fprintf(fp,"%s %s %s %.1f %.1f\n",
        items[i].name, items[i].brand,
                items[i].hobby_name,
                 items[i].price,
                 items[i].discount);
                    }
/* flush content into file */
fflush(fp);

/* close file */
fclose(fp);
}
}

void scan_hobby(item_type items[],char hobby[], int norecs)
{
    int i;
    /*Head of the table */
    for (i = 0; i < norecs; i++)
    {
	if ( strcmpi(items[i].hobby_name, hobby )==0 )/*check each name for a match */

{

    printf("\n| name | brand | hobby | price | discount | total \n");
    /*print the results*/
      printf("%s %s %s %.1f %.1f\n", items[i].name, items[i].brand,
                items[i].hobby_name, items[i].price,items[i].discount);

    }
    }
}


