# Text_Editor


This project aims to develop a ‘Text Editor’ in C language that uses the concepts of the data structure Stacks.
The text editor application is a simplified version of notepad application. 

It provides various controls to the user for editing words.
It includes various features like – 

•	Inserting a character

•	Deleting a character using DEL

•	Deleting a character using Backspace

•	Moving the cursor to the left

•	Moving the cursor to the right

•	Replacing a character

•	Inserting a word

The application is designed using two stacks. The cursor position is used as a ‘divider’ and two stacks are then maintained on either side to hold the characters. 
All characters to the left of cursor are pushed on the ‘left’ stack. All characters to its right, are pushed on the ‘right’ stack.
