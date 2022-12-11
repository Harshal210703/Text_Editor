#include <stdio.h>
#include <stdlib.h>

#define size 50

    char left_stack[size];
    char right_stack[size];
    int left_top = -1, right_top = -1;

void examineTop()
{
    if (left_top <= -1)
    {
        printf("\nLeft Stack: Empty\n");
    }
    else
    {
        printf("\nLeft Stack: \nTOP- %d \nSIZE- %d\n",left_top, left_top+1);
    }

    if(right_top <= -1)
    {
        printf("\nRight Stack: Empty\n");
    }
    else
    {
        printf("\nRight Stack: \nTOP- %d \nSIZE- %d\n",right_top, right_top+1);
    }
}

void insertWord(char word[])
{
    if (left_top == size-1)
        {
            printf("Stack is OVER-FLOW! \n");
        }
        else
        {
            int i = 0;
            left_top++;
            left_stack[left_top] = " ";
            while(word[i] != '\0')
            {
                left_stack[left_top+1] = word[i];
                left_top++;
                i++;

            }
        }
}

void insertCharacter(char character)
{
    if (left_top == size-1)
        {
            printf("Stack is OVER-FLOW! \n");
        }
        else
        {
            left_top++;
            left_stack[left_top] = character;
        }
}

void deleteCharacter(int counter)
{
    while(counter--)
    {
        if (right_top <= -1)
        {
           printf("\nThere is nothing to delete. Move your cursor accordingly to delete the character");
        }
        else
        {
            right_top--;
        }
    }
}

void backSpaceCharacter(int counter)
{
    while(counter--)
    {
        if (left_top <= -1)
        {
            printf("\nThere is nothing to delete. Move your cursor accordingly to delete the character");
        }
        else
        {
            left_top--;
        }
    }
}

void moveLeft(int);
void moveRight(int);

void moveCursor(int position){

    int count;
    position = position-1;
    if (position < left_top)
    {
        moveLeft(position);
    }
    else
    {
        count = position - left_top;
        moveRight(count);
    }
}

void moveLeft(int pos)
{
    while(pos != left_top && left_top != -1)
    {
        right_top++;
        right_stack[right_top] = left_stack[left_top];
        left_top--;
    }
}

void moveRight(int post)
{
    int i=1;
    if (post > size){
        printf("Cannot move cursor, right, to the specified position");
    }
    else{
        while(i<=post){
        left_top++;
        left_stack[left_top] = right_stack[right_top];
        right_top--;
        i++;
        }
    }
}

void findAndReplaceChar(char findWhat, char replaceWith){

    int count=1, originalCursorPoistion = left_top;
    moveCursor(0); //Move characters from left stack to right stack
    while(right_top != -1)
    {
        if(right_stack[right_top] == findWhat)
        {
        deleteCharacter(1);
        insertCharacter(replaceWith);
        }
        else
        {
            moveCursor(count);
            count++;
        }
    }
    moveCursor(originalCursorPoistion+1); //Retain the original cursor position
}

void display()
{
    if(left_top>=0)
    {
        printf("\nThe current cursor position: \n");

         for(int i=0; i<=left_top; i++)
        {
            printf("%c",left_stack[i]);
        }

        char cursor = '|';

        printf("%c",cursor);

        for(int i=right_top; i>=0; i--)
        {
            printf("%c",right_stack[i]);
        }
    }

    else if (left_top == -1)
    {
        char cursor = '|';

        printf("\n%c",cursor);

        for(int i=right_top; i>=0; i--)
        {
            printf("%c",right_stack[i]);
        }
    }
    else
    {
        printf("Nothing to display!\n");
    }

}


int main()
{
    int choice = 1;
    char text[80];

    printf("Enter the word to be edited: ");
    gets(text);
    insertWord(text);

    printf("\n     === MENU === \n1.EXAMINE TOP \n2.MOVE CURSOR \n3.DELETE CHARACTER TO THE RIGHT \n4.BACKSPACE \n5.INSERT CHARACTER \n6.FIND AND REPLACE CHARACTER \n7.INSERT WORD \n8.DISPLAY \n9.EXIT \n");

    while(choice != 8)
    {
        printf("\nChoose an option: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                examineTop();
                break;
            }
            case 2:
            {
                int num;
                printf("Enter the position where you want the cursor: ");
                scanf("%d",&num);
                moveCursor(num);
                break;
            }
            case 3:
            {
                int count=1;
                printf("Enter the number of characters to be deleted: ");
                scanf("%d", &count);
                deleteCharacter(count);
                break;
            }
            case 4:
            {
                int count=1;
                printf("Enter the number of characters to be backspaced: ");
                scanf("%d", &count);
                backSpaceCharacter(count);
                break;
            }
            case 5:
            {
                char letter;
                printf("Enter the character to be inserted: ");
                scanf(" %c",&letter);
                insertCharacter(letter);
                break;
            }
            case 6:
            {
                char find, replace;
                printf("Find: ");
                scanf(" %c",&find);
                printf("Replace with: ");
                scanf(" %c",&replace);
                findAndReplaceChar(find, replace);
                break;
            }
            case 7:
            {
                char word1[15];
                printf("Enter the word: ");
                scanf("%s",word1);
                insertWord(word1);
                break;
            }
            case 8:
            {
                display();
                break;
            }
            case 9:
            {
                exit(0);
                break;
            }
            default:
            {
                printf ("Please enter a valid choice(1-9): ");
                break;
            }

            }
        }
return 0;
}
