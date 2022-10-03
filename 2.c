#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLENGTH 20
/*
* Author : Param Bhatia
* Date Created : 28/12/2021
*File Name : 2.c
* -----------------------------------------------------------------------------------------------------------------------------
* The purpose of the file is to allow users to conduct different file operations.
* The program will prompt the user to select an option from a variety of file operations.
* The user input will then be validated, to ensure that the input is a valid number from 0-11
* The program will then prompt user to enter the filename, and verify that such a file exists.
* Then the program will call the relevant function in order to carry out the specified operation.
* After each operation, the changelog function is called to add the operation to the log.
* The log stores file name, and the operation carried out, as well number of lines in the file.
*
* My additional features are as follows:
*
* 1)Searching through a file to see if a word exists in a file - which is useful if someone wants to know if a word is there in a file.
* 2)Word Counter - Checks for number of words in a file.
*/

void changeLog();       //declaring the changelog function at the top, in order to prevent implicit declaration in functions.

/*
* Function Name - checkExists
* -----------------------------------------------------------------------------------------------------------------------------
* Input Parameters:
*
* inputFileName - Memory address of char array with size defined by macro in the heading
* This will be the name of the file to be checked.
* -----------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Function declares a file pointer, then attempts to read a file with the value from the parameter
* If the pointer value is not NULL, then print to the user that the file exists.
* Return 0 if the file exists, since 0 is the C standard for representing success.
* If pointer value is NULL, output that the file does not exist, and return 1, since 1 is the C standard to represent failure.
* The program will then close the file if it previously existed.
* -----------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* The function will output either of two things
* It informs the user whether the file exists, or it doesn't
* -----------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* The return type of the function is integer.
* This is because the return value is used to represent to the other function whether a file exists or not.
*/
int checkExists(char inputFileName[MAXLENGTH]){
    FILE *fptr;     //creating a file pointer
    fptr = fopen(inputFileName, "r");       //simply opening file in 'read' mode will allow us to know if the file exists.
    if(fptr != NULL)
    {
        fclose(fptr);       //close file so it can be edited from other function too.
        printf("This files exists!\n");     //provide update to user regarding status of the program
        return 0;           //0 is the C standard to represent success.
    }
    else
    {
        printf("File does not exist, please try again\n");  //provide update to user regarding status of the program
        printf("Maybe you have spelt the name incorrectly, or the file does not exist!");   //provide user with error reasoning
        return 1;           //1 is the C standard to represent fail
    }
}

/*
* Function Name - inputFile
* -----------------------------------------------------------------------------------------------------------------------------
* Input Parameters:
*
* inp - memory address of char array with defined size of macro value.
* This array contains the file name input from the user, to be validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Function will declare a char array with value ".txt"
* Function will loop until input file name has been validated
* Will prompt user to enter file name
* Using scanf() to read input ensures there are no spaces in file name.
* Having spaces in file name can be dangerous to use in other software, such as shell scripts, and can cause problems.
* The program is made for users, so the user is informed that they should not enter spaces in file names.
* Concatenate the input string in order to attach .txt file format to the end of the input file name.
* Call the checkExists() function to ensure that the file exists.
* If the file exists, the return value of checkExists() will be 0, and program will leave the loop.
* If the file does not exist, the program stays in the loop until valid file is input.
* Additional Feature: If user does not want to enter a name, or forgets that file does not exist, then they can leave loop by typing exit.
* This will improve user accessibility and makes it easier to use for the user.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Function will print instructions to user about how to enter a valid filename
* Function will also allow user to exit the program if they enter "exit"
* Function will also print the concatenated file name entered by user.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* Function has a int return type.
* The int return is used to signify whether the input filename has been validated successfully or not.
*/

int inputFile(char (inp)[MAXLENGTH]){
  int validInput = 1;        //int type to check whether input file has been entered properly, or if program should stay in loop.
    char text[] = ".txt";       //used to concatenate file name with .txt since the program is meant for text files.
    while (validInput == 1)
    {
        //the following print statements explain to the user how to input a file name.
        printf("Enter file to be checked\n");
        printf("Please note: File Names cannot have spaces. If the name has multiple words, separate using hyphens\n");
        printf("Please note: Do not add .txt to the end of the file name\n");
        printf("Please note: If you choose to leave program, please type exit\n");
        scanf("%s", inp);       //input as only one word, as spaces in file names can cause errors in external software, eg shell scripts.
        if (strcmp("exit", inp) == 0)       //checks if user input value is the same as "exit"
        {
            //this statement checks whether the user has entered exit, in order to leave the program from the loop.
            return 1;
        }
        printf("The file name is %s\n", strcat(inp,text));  //provide user with update on what is happening
        validInput = checkExists(inp);   //calls function to check if input file exits
    }
    return 0;   //C standard for success, since the program will only get to here if the file name is validated.
}


/*
* Function Name - addFile
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameter
*
* inp - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Function creates a file pointer, and asks user to provide a name for the file to be created
* Uses scanf() to read user input, for the same reason as mentioned in the function inputFile, since spaces in files can cause problems.
* If user input is equal to the string "exit" then exit program with value 1, since 1 represents fail in C standard.
* Concatenate user input with .txt since the program is made for text files.
* Open file in write mode to create the file, the close the file so that other functions can edit the file.
* Exit with value 0, since it is the success value in C standard, and the program will only reach this statement if the filename is valid.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Function will print instructions to user about how to enter a valid filename
* Function will also allow user to exit the program if they enter "exit"
* Function will also print the concatenated file name entered by user.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* Function has a int return type.
* The int return is used to signify whether the input filename has been validated successfully or not.
*/

int addFile(char (inp)[MAXLENGTH]){
    FILE *fptr;

    char text[] = ".txt";       //used to concatenate file name with .txt since the program is meant for text files.

    //the following print statements explain to the user how to input a file name.
    printf("Enter file to be created\n");
    printf("Please note: File Names cannot have spaces. If the name has multiple words, separate using hyphens\n");
    printf("Please note: Do not add .txt to the end of the file name\n");
    printf("Please note: If you choose to leave program, please type exit\n");

    scanf("%s", inp);   //input as only one word, as spaces in file names can cause errors in external software, eg shell scripts.

    if (strcmp("exit", inp) == 0)   //checks if user input value is the same as "exit"
    {
        //this statement checks whether the user has entered exit, in order to leave the program from the loop.
        return 1;
    }
    printf("The file name is %s\n", strcat(inp,text));  //provide user with update on what is happening in the program

    fptr = fopen(inp, "w");         //use write mode to create file
    fclose(fptr);                   //close file so other functions can edit
    return 0;                       //return with success value of 0
}


/*
* Function Name - deleteFile
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameter
*
* inp - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation
*
* The function simply takes in the user input file name, and then uses the remove() function to delete the file.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output
*
* Function returns to user that the file has been deleted.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type
*
* The function has a void return type, since there is no reason to conduct any validation, since the file name has already been validated.
*/

void deleteFile(char (inputName)[MAXLENGTH]){
    remove(inputName);
    printf("The file has been deleted\n");  //Updates user with what is happening.
}

/*
* Function Name - copyAndCreateFile
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameter:
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Function declares two file pointers, one for the file to be copied, and another to copy the contents into.
* File pointer 1 opens the file name specified by the user, which has been validated already.
* The first file is opened in read mode, because there is no need to write to the first file.
* Program then goes through file 1 letter-by-letter and prints the letters to the user, in order to let user know what the file contains.
* Then the user is prompted to enter the name of a new file, which will be created, and concatenated with .txt.
* This new file is then opened in write mode in order to create the file, and add copied text.
* The program then goes through file 1 letter by letter, and for each letter, it is placed in the 2nd file.
* After all content has been copied, close both files.
* Call the changelog() function in order to update file 2 in the log.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Function will output the contents of the first file to the user, so that the user knows what is being copied.
* Function will then output how user should input file name for the second file.
* Function will output that the content has been copied.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* Function has a void return type, since there is no need to verify the function, as there is no way to fail the program.
*/

void copyAndCreateFile(char (inputName)[MAXLENGTH]){
    FILE *fptr1, *fptr2;        //declaring two file pointers, one for each file.
    char text[] = ".txt";
    char input2[MAXLENGTH], letter, temp;

    fptr1 = fopen(inputName, "r");      //opens first file in read mode

    printf("The content of this file is as follows:\n");    //update user with the progress of operation.

    temp = getc(fptr1);     //temporary char variable to print out contents of file.

    //this loop will print contents of file 1, using while loop until the end of file is reached.
    while (temp != EOF)
    {
        putchar(temp);      //used to print char type to stdout
        temp = getc(fptr1); //getc is used instead of fgetc because it is much more efficient
    }
    rewind(fptr1);          //sets the file stream of file 1 to the beginning.


    //the following print statements explain to the user how to input a file name.
    printf("Enter the name of the file which should be copied to.\n");
    printf("Please note: File Names cannot have spaces. If the name has multiple words, separate using hyphens\n");
    printf("Please note: Do not add .txt to the end of the file name\n");

    scanf("%s", input2);        //input as only one word, as spaces in file names can cause errors in external software, eg shell scripts.
    strcat(input2,text);

    fptr2 = fopen(input2, "w"); //open file in write mode, in order to create the file first, and also write to it.

    letter = getc(fptr1);
    while (letter != EOF)
    {
        //takes content of file 1 letter by letter, and puts it in file 2.
        putc(letter, fptr2);
        letter = getc(fptr1);
    }

    printf("The content has been copied\n");        //update user with progress of operation

    fclose(fptr1);
    fclose(fptr2);
    changeLog(input2, "created with content from file listed above");   //update change log
}

/*
* Function Name - showFile
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameter
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation
*
* Function declares file pointer, and opens in read mode in order to print it to the user
* Uses a char variable called letter, and iterates through the file letter-by-letter, and prints the letter to stdout using putchar()
* Close the file after it has been read
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Function will print out what is going to follow with the file content.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* Function has a void return type, since there is no need to verify the function, as there is no way to fail the program.
*/

void showFile(char (inputName)[MAXLENGTH]){
    FILE *fptr;     //declare file pointer
    char letter;

    printf("The contents of the file are as follows:\n");       //update user with what is going to be printed
    fptr = fopen(inputName, "r");       //opening the file in read mode, because there is no reason to edit it here.
    letter = getc(fptr);                //using getc is more efficient than fgetc
    while (letter != EOF)
    {
        //takes content of file letter by letter, and puts it in stdout for user to read
        putchar(letter);
        letter = getc(fptr);    //will iterate to the next letter
    }

    fclose(fptr);   //close the file so it can be edited elsewhere in the program.
}

/*
* Function Name - appendLine
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameter:
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Program declares the file pointer, as well as a char array of defined size.
* The function uses fgets to read user input, instead of scanf() since fgets will be able to input multiple words.
* Fgets is used since it does not stop reading at a whitespace character like scanf.
* Since scanf was used previously while validating the file name, there is a trailing newline left in the buffer.
* This is why the function uses getchar(), in order to remove the trailing new line, otherwise fgets will not read user input.
* The file will then be opened in append mode, in order to open the file to add to the current contents.
* Fprintf will be used in order to print to the file.
* File will then be closed.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Function will prompt user to enter the text to be appended.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* It has a void return type, since there is no need to verify the function, as there is no way to fail the program.
*/

void appendLine(char (inputName)[MAXLENGTH]){
    FILE *fptr;     //declaring file pointer
    char letter;
    char addMessage[60] = "";   //initialise char array to be appended

    getchar();      //use to remove trailing new line character(\n) from buffer
    printf("Enter message to be appended\n");
    fgets(addMessage, 60, stdin);   //using fgets allows user to enter data with spaces into the text file
    fptr = fopen(inputName, "a");   //open the file in append mode, in order to add to the existing data

    fprintf(fptr, "%s", addMessage);        //use  fprintf as a printf function, but printing to the file stream.
    fclose(fptr);
}


/*
* Function Name - deleteLine
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameters:
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Declare two file pointers and an integer measuring current line number.
* Open first file in read mode, and use getc function to iterate through the file character-by-character.
* Print out all the characters in stdout, so that the user can see the contents of the file.
* Ask user to enter which line to delete, and store this in integer varaible.
* Open a temporary file in write mode, in order to create the file.
* Iterate through the first file character by character.
* If the character is a new line character, then increment line number variable.
* If the line number is not the line to be deleted, then put all the characters in the line from original file into temporary file.
* If the line number is equal to the delete line number, then do not copy contents of that line from original file to temporary file.
* Close both these files, and delete the original file.
* Rename the temporary file to the name of the original file.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Output contents of the original file to the user, to show the original contents.
* Prompt user to enter the line number to delete.
* Output that the line has been deleted.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* It has a void return type, since there is no need to verify the function, as there is no way to fail the program.
*/

void deleteLine(char (inputName)[MAXLENGTH]){
    FILE *fptr1, *fptr2;    //declare two file pointers, there will be an original file and second file which does not contain deleted line.
    int lineNumber = 1;     //set starting value of line number to 1, as there is no line 0 in a text file.
    int deleteLineNumber;
    char c;

    fptr1 = fopen(inputName, "r");  //open file in read mode, since it is not being edited
    c = getc(fptr1);

    while (c != EOF)
    {
        //use this loop to print out the contents of the file to the user, so they can decide which line to delete.
        printf("%c", c);
        c = getc(fptr1);
    }

    rewind(fptr1);          //set the file position to the start of the file, as program will iterate through it again.

    printf("Which line to delete?\n");
    scanf("%d", &deleteLineNumber);         //scanf() is used because a number does not have spaces in between it, so no need for fgets().

    fptr2 = fopen("temp.txt", "w");         //open new file in write mode to create and edit the file.

    c = getc(fptr1);
    while (c != EOF)
    {
        //Loop through the original file character-by-character again

        if (c == '\n')
        lineNumber++;       //if the current character is a trailing newline, increment line count as newline creates a new line.

        if (lineNumber != deleteLineNumber)
        {
            //as long as current line is not the line to be deleted, copy characters from original into temporary
            putc(c, fptr2);
        }
        c = getc(fptr1);
        //if current line is line to delete, simply dont do anything to that line, and it will not be copied.
    }
    printf("Line has been deleted\n");        //update user with program progress.
    fclose(fptr1);
    fclose(fptr2);

    remove(inputName);      //Delete original file
    rename("temp.txt", inputName);  //rename the temporary file to original file, so that the name of the original file is preserved.
}

/*
* Function Name - insertLine
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameter:
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Declare two file pointers and an integer measuring current line number.
* Open first file in read mode, and use getc function to iterate through the file character-by-character.
* Print out all the characters in stdout, so that the user can see the contents of the file.
* Ask user to enter which line to insert, and store this in integer varaible.
* Ask user what text to input, and read using fgets()
* Open a temporary file in write mode, in order to create the file.
* Iterate through the first file character by character, until End Of File is reached.
* If the character is a new line character, then increment line number variable.
* If the current line is not the line to be inserted in, use putc to insert all the characters in the line into the temporary file.
* If the current line is line to be inserted, use fprintf to print the whole char array into the line at once, and increment line number
* Close both files, delete original file, and rename temporary file to the original file.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Output contents of the original file to the user, to show the original contents.
* Prompt user to enter the line number to insert at.
* Prompt user to enter text to be inserted, and read it using fgets()
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* It has a void return type, since there is no need to verify the function, as there is no way to fail the program.
*/

void insertLine(char (inputName)[MAXLENGTH]){
    FILE *fptr1, *fptr2;    //declare two file pointers, there will be an original file and second file which contains deleted line.
    int lineNumber = 1;     //set starting value of line number to 1, as there is no line 0 in a text file.
    int insertLineNumber;
    char c;
    char addMessage[60] = "";

    fptr1 = fopen(inputName, "r");      //open file in read mode, since it is not being edited
    c = getc(fptr1);

    while (c != EOF)
    {
        //use this loop to print out the contents of the file to the user, so they can decide which position to insert line.
        printf("%c", c);
        c = getc(fptr1);
    }

    rewind(fptr1);      //set the file position to the start of the file, as program will iterate through it again.
    printf("Which line to insert?\n");
    scanf("%d", &insertLineNumber);     //scanf() is used because a number does not have spaces in between it, so no need for fgets().

    getchar();      //Will be using fgets() and have previously used scanf(), which left a trailing newline in the buffer.
    //getchar will absorb this newline otherwise the fgets will be unable to read user input.

    printf("Enter message\n");      //prompt user to enter their message
    fgets(addMessage, 60, stdin);   //store user input text in the addMessage char array from stdin

    fptr2 = fopen("temp.txt", "w");     //open new file in write mode to create and edit the file.

    c = getc(fptr1);
    while (c != EOF)
    {

        if (lineNumber != insertLineNumber)
        {
            //as long as current line is not the line to be deleted, copy characters from original into temporary
            putc(c, fptr2);
        }
        if (lineNumber == insertLineNumber)
        {
            fprintf(fptr2, "%s", addMessage);   //use fprintf to print user text into the temporary file
            lineNumber++;
            putc(c, fptr2);
        }

        if (c == '\n')
        lineNumber++;       //if the current character is a trailing newline, increment line count as newline creates a new line.

        c = getc(fptr1);    //This is used to increment to the next character in the original file.
    }
    fclose(fptr1);
    fclose(fptr2);

    remove(inputName);      //delete original text file
    rename("temp.txt", inputName);      //rename the temporary file to original file, so that the name of the original file is preserved.
}


/*
* Function Name - showLine
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameters:
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Declare file pointer and integer value containing current line number.
* Ask user which line to display, and save the input in a variable of type integer.
* Open file in read mode, and iterate through file character-by-character.
* If current character is newline, increment line number.
* If line number is the same as user input, until the current character is a newline, print all characters to the stdout for user to read.
* Put a new line character after printing, so that it will be easy for the user to read.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Prompt user to enter which line they want to see
* Print the desired line to user, character-by-character until a newline character is reached, symbolizing end of line.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* It has a void return type, since there is no need to verify the function, as there is no way to fail the program.
*/
void showLine(char (inputName)[MAXLENGTH]){
    FILE *fptr;         //declare file pointer
    int lineNumber;
    int currentLine = 1;        //current line starts at 1, since there is no line 0 in text files.
    char letter;
    printf("Which line to read?\n");    //prompt user to enter desired line.
    scanf("%d", &lineNumber);           

    fptr = fopen(inputName, "r");       //open file in read mode, since there is no need to edit it.
    letter = getc(fptr);
    while (letter != EOF)
    {
        //use this loop to iterate through the contents of the file, so the program can locate the line to be edited.
        if (currentLine == lineNumber)
        {
            //if the current line is the line to printed, print all the characters until the current character is a newline character.
            while (letter != '\n')
            {
                putchar(letter);
                letter = getc(fptr);
            }
            break;  //if the line is found and printed to user, leave the function.
        }
        if (letter == '\n')
        {
            //for each character that is a newline character, increment current line number.
            currentLine++;
        }
        letter = getc(fptr);
    }
    putchar('\n');
    fclose(fptr);
}

/*
* Function - numberOfLines
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameters:
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* shouldOutput - integer variable which decided whether the function should print the number of lines to the user.
* This is important because the changelog function also calls this function, but printing to user is not neccessary then.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Function declares a file pointer and a integer variable counting the number of lines.
* Open the file from the parameter in read mode, since there is no reason to edit it.
* Iterate through the file character-by-character until EOF, and for every newline character increment line count.
* Close the file
* If the integer parameter is 0, print out the number of lines, else do not print the count.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Only output the line count if the integer parameter is 0, which is the C standard for success.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* Function has an integer return type, since it will return the total line number.
*/

int numberOfLines(char (inputName)[MAXLENGTH], int shouldOutput){
    FILE *fptr;     //declare file pointer
    char letter;    //used for iteration
    int totalLineNumber = 0;        //used as an integer count for the line number
    
    fptr = fopen(inputName, "r");   //open file in read mode
    letter = getc(fptr);
    while (letter != EOF)
    {
        //use this loop to iterate through the contents of the file
        if (letter == '\n')
        {
            //for each character that is a newline character, increment current line number
            totalLineNumber++;
        }
        letter = getc(fptr);//This is used to increment to the next character in the file.
    }
    fclose(fptr);

    if (shouldOutput == 0) {
        //This is used because changelog will also refer to this function, and that is when the line number does not need to be printed.
      printf("There are %d lines in this file\n", totalLineNumber);
    }

    return totalLineNumber; //used to return value to the changelog, which is the only function calling this function with int argument '1'.
}

/*
* Function Name - checkWordInFile
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameter:
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Declare file pointer and integer value which decides whether the input word is found.
* Open file in read mode, and prompt user to enter the word to be searched.
* Use scanf() to read user input since it is just a word, with no spaces involved.
* Iterate through the file line-by-line by using fgets() with the file stream being the file open for reading.
* Use a char pointer and strstr() function to check if the word exists in any line.
* If the word doesnt exist, the pointer will be null, and if the word does exist, inform user that the word is found.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Prompt user to enter the word to be searched.
* Print whether the word was found in the text file in the input file or not.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* It has a void return type, since there is no need to verify the function, as there is no way to fail the program.
*/

void checkWordInFile(char (inputName)[MAXLENGTH]){
    int maxLineSize = 50;
    int isFound = 1;
    char line[maxLineSize];
    FILE *fptr;     //declare file pointer

    fptr = fopen(inputName, "r");   //open file in read mode
    char searchWord[10];        //max size of word to be searched is 10

    printf("Enter word to be searched\n");  //prompt user to enter word
    scanf("%s", searchWord);
    getchar();  //since scanf is used and fgets is used next, there is a trailing new line left in the buffer, so getchar() absorbs the '\n'.

    while (fgets(line, maxLineSize, fptr) != NULL)
    {
        //iterate through the text file line-by-line
      char *pointer = strstr(line,searchWord);      ///using strstr() allows the program to compare strings
      if (pointer != NULL)
      {
          //strtstr return a pointer, and if the word does not exist the pointer is null.
          isFound = 0;      //0 represents success by C standards
          printf("This word does exist in the file\n");     //inform user about update with operation
          break;        //exit the loop once the word is found, in order to make the program time-efficient
      }
    }
    if (isFound == 1) {
      printf("Your word was not found in the file\n");  //inform user about update with operation
    }
    fclose(fptr);

}

/*
* Function Name - wordCounter
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameter:
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Declare file pointer and open the file in read mode, since there is no need to edit it.
* Declare and initiate word variable of type integer with value of 0, since there are 0 words before iterating through the file.
* Use getc() to iterate through the file character-by-character.
* During the iteration, if the character is equal to a newline character or a whitspace or a tab character, then increment word variable.
* This is because mathematically, a word is defined as a set of characters separated by a space, newline, or tab.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Print the counter of the number of words in the file to the user.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* It has a void return type, since there is no need to verify the function, as there is no way to fail the program.
*/

void wordCounter(char (inputName)[MAXLENGTH]){
    int words = 0;      //count is initialised as 0
    char letter;
    FILE *fptr;         //declare file pointer
    fptr = fopen(inputName, "r");   //open file in read mode
    
    
    letter = getc(fptr);    //iterate through file character by character
    while (letter != EOF) {
    //repeat until the character reaches end-of-file 
      if (letter == ' ' || letter == '\n' || letter == '\t') {
        //all set of characters separated by the characters above are defined as words, so increment the words variable.
        words++;
      }
      letter = getc(fptr);  //This will take in the next character.
    }
    printf("The total number of words in this file is %d\n", words);        //output the number of words to the user
    fclose(fptr);
}

/*
* Function Name - changeLog
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameters:
*
* inputName - memory address of char array with defined size of macro value.
* This array contains the file name input from the user which has been validated.
*
* operation - memory address of char array with defined size.
* This array contains the operation being done to the file.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Declare lines variable of type integer.
* Call the numberOfLines() function with arguments as the input fileName and binary '1'.
* This will prevent the lines function from printing the number of lines, because that is not needed when updating the change log.
* Set the value of lines to the value of the numberOfLines function.
* Declare file pointer and open in append mode.
* Append to file using fprintf function. The parameters are the input filename, the operation, and the number of lines in the file.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* The function will have no output, as the purpose is to update log, not to print to user.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* It has a void return type, since there is no need to verify the function, as there is no way to fail the program.
*/

void changeLog(char (inputName)[MAXLENGTH], char operation[30]){
  int lines = numberOfLines(inputName, 1);  //using function without printing the lines.
  FILE *fptr;
  fptr = fopen("changeLog.txt", "a");   //use append mode to add text, not overwrite.
  fprintf(fptr,"File :%s %s. This file has %d lines\n", inputName, operation, lines);   //prints to log using the input parameters & lines.
  fclose(fptr);
}

/*
* Function Name - validateInput
* -------------------------------------------------------------------------------------------------------------------------------
* Input Parameters:
* 
* There are no input parameters in this function because this function asks the user for input.
* There are no variables that exist before this function to be passed in as parameters.
* -------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Ask user which operation they would like to carry out.
* Firstly check if the input value is a number.
* To check for number, store the input as a string (character array), then iterate through each element of the array.
* Check if each element is a digit by using the isdigit() function.
* If a character is a digit, increment value of variable digits, ie the number of valid input characters.
* After the whole input is iterated through, it will check if the number of digits is equal to the length of input.
* This will show whether the whole input is is a number or not. If not, the program will loop back and ask user for input again.
* Secondly, the program will check whether the input, which is verified as a number, is between 0 and 11 inclusive.
* If both these requirements are met, the program will return this value, after converting the string into integer using atoi().
* Otherwise, the program will loop back and ask user for another input.
* This will continue to happen until user will input a valid number.
* -------------------------------------------------------------------------------------------------------------------------------
* Function Output:
*
* Function will prompt user to enter a valid input.
* If there is an error, program will also prompt user to correct their error by entering another input.
* If there is an error, program will also print the error, and why it is an error.
* -------------------------------------------------------------------------------------------------------------------------------
* Function Return Type:
*
* Function has an integer return type, in order to return the validated integer size of user input array.
*/

int validateInput(){
    int checkInput = 1;             //Use '1' for fail as per C standards, and a success is represented as a '0'.
    int digits = 0;                 //Number of digits in the user input.
    int numInput;                   //The validated input to be returned.
    char strInput[5] = "";          //User's Input for the operation no.
    
    while (checkInput == 1)
    {
        //This while loop will continuously loop until the input is a number AND the number is between 0 and 11.
        printf("Which of the above operations would you like to do?\n");
        scanf("%s", strInput);      //use scanf() as the input does not need to be multiple words.
        int length = strlen(strInput);
        for (int i = 0; i < length; i++)
        {
            //This will loop through all the characters in the users input, and check if all are digits or not.
            if (!isdigit(strInput[i]))
            {
                printf("The input is not a valid number\n");
                digits =0;
                break;      //Will exit this for loop and loop back to the start of the while loop to prompt user to enter again.
            }
            else digits++;  //Will increment if the current character is a digit.
        }
        
        if (digits == length)       //This will check if the number of digits in the input is the same as the length of the input.
        {
            //checks if input is a number
            numInput = atoi(strInput);      //Converts the validated char array into 'int' type.
            
        }
        else continue;                      //If the input contains non-digits, skip this iteration, prompt user to enter again.
        printf("You have chosen operation number: %d\n", numInput);

        if (numInput > 11 || numInput < 0)  //Checks if the number is between 0 and 11 inclusive, as that is the limit.
        {
            printf("Number must be less than or equal to 11\n");
            checkInput = 1;                 //1 is the C value for failure, so the check has been failed.
        } else checkInput = 0;              //If both requirements have been satisfied, set check to success, i.e. '0'.
        digits =0;                          //Will reset the count of digits, if needed to repeat the while loop
    }
    return numInput;                        //Will return the value of the validated user input.
}

/*
* Function Name - main
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Parameter:
*
* There are no parameters in the main function, because this program does not input any command line arguments.
* This is because it would impossible for the user to know what to enter without running the program first.
* Having no command line arguments improves the efficiency of the program, as it will not search the command line for any values.
* All the user input is collected in this function, as well as in the validation function.
* -----------------------------------------------------------------------------------------------------------------------------------------
* Function Operation:
*
* Print the list of operations that can be called.
* Declare variable option of type int, and call validateInput function
* Return value of validateInput is set to option.
* Declare char array 'input' with a size of macro defined at header.
* Call InputFile function, in order to prompt and validate user input filename.
* If the InputFile function has been returned successfully, call the function corresponding to the option choice.
* Call changeLog after operation has been executed.
*/

int main(){
    int repeater = 0;
    while (repeater == 0)
    {
        char repeatProgram;
        

        printf("Welcome Here!\n");
        printf("0 - Show Change Log\n");
        printf("1 - Add A New File\n");
        printf("2 - Delete File\n");
        printf("3 - Create New File And Copy Existing File\n");
        printf("4 - Show Contents Of File\n");
        printf("5 - Append New Line to End Of File\n");
        printf("6 - Delete a specific line from a specified file\n");
        printf("7 - Insert Text At Specified Line Of File\n");
        printf("8 - Show Text Of Specific Line In File\n");
        printf("9 - Show Number Of Lines In File\n");
        printf("10 - Search for word in a file\n");
        printf("11 - Word Counter in a File\n");
        
        int option;
        option = validateInput();   //call function to validate input and store user choice

        char input[MAXLENGTH];      //declare char arry of fileName



        if (option == 0)
        {
            showFile("changeLog.txt");
            changeLog("changeLog.txt", "was printed to user");
        }


        if (option == 1)
        {
            if (addFile(input) == 0)    //check to see if method was completed successfully, since 0 represents sucess.
            {
                //addFile does not need name validation
                changeLog(input, "has been created");
            }
            
        }
        else if (option == 2)
        {
            if (inputFile(input) == 0)
            {
                //will delete the file
                changeLog(input, "has been deleted");
                deleteFile(input);

            }
        }
        else if (option == 3)
        {
            if (inputFile(input) == 0)
            {
                //will create a new file, and copy contents of input file into new file
                changeLog(input, "has been copied");
                copyAndCreateFile(input);

            }
        }
        else if (option == 4)
        {
            if (inputFile(input) == 0)
            {
                //display the file contents
                showFile(input);
                changeLog(input, "was printed to user");
            }
        }
        else if (option == 5)
        {
            if (inputFile(input) == 0)
            {
                //appends line to a file.
                appendLine(input);
                changeLog(input, "has been appended");
            }
        }
        else if (option == 6)
        {
            if (inputFile(input) == 0)
            {
                //deletes specific line from a file
                deleteLine(input);
                changeLog(input, "has had one line deleted");
            }
        }
        else if (option == 7)
        {
            if (inputFile(input) == 0)
            {
                //inserts a line at a specific position
                insertLine(input);
                changeLog(input, "has inserted specific line");
            }

        }
        else if (option == 8)
        {
            if (inputFile(input) == 0)
            {
                //shows a specific line of a file
                showLine(input);
                changeLog(input, "printed specific line to user");
            }

        }
        else if (option == 9)
        {
            if (inputFile(input) == 0)
            {
                //displays number of lines
                numberOfLines(input, 0);        //0 will print the number of lines
                changeLog(input, "printed count of lines to user");
            }

        }
        else if (option == 10)
        {
            if (inputFile(input) == 0)
            {
                //checks if a word exists in a file.
                checkWordInFile(input);
                changeLog(input, "has searched for specific word");
            }
        }
        else if (option == 11)
        {
            if (inputFile(input) == 0)
            {
                //Counts the number of words in a file.
                wordCounter(input);
                changeLog(input, "has number of words counted");
            }
        }

        printf("Would you like to do an operation again? (y/n)\n");
        scanf("%s", &repeatProgram);
        if (repeatProgram == 'y' || repeatProgram == 'Y')
        {
            //check to see if input begins with 'y', and if it does, then set flag to 0, which means success by C standards.
            repeater = 0;
        }
        else 
        {
            repeater = 1; //if user does not want to repeat, then exit the while loop}
        }   
    }
}