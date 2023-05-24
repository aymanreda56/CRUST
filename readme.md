# :spades: Crust :spades:

## a lightweight C-like programming language and compiler, with a user friendly GUI


This project was implemented as our Compilers' course project.
It essentially implements the full compiler pipeline : Front-End  |  IR  | Back-End
* "We used C to make C", this project was entirely written in C. Such speed, less space. 
* Uses Flex and Bison's implementation for Lex and Yacc.
* Friendly Syntax
* Not Strictly typed
* Predictive and informative error handling
* Produces stack machine assembly. Aiming for compatibility with different CPU architectures.
* Cauce -pronounced as "Sauce"- is our minimalistic GUI using TKinter.
* Supports advanced programming schemes like Recursions, Nest-oriented programming, structs, Polymorphism, etc.
* Debugger [Future plans]


you can find our Language rules here. //todo, add a link to our proposal which contains our syntax rules
also you can find the BNF diagram for our language here. //todo, add BNF diagrams (so that graph theory students can see our repo).

## Watch our <a href="https://youtu.be/KR75qdKQD28"target="_blank">demo</a> !
<a href="https://youtu.be/KR75qdKQD28"
target="_blank">
<img src="https://github.com/aymanreda56/CL_Project/blob/main/assets/img/pasted%20image%200.png" alt="Crust demo using Cauce" width=240 height=180 border="10"/>
</a>

#### Hot-Keys
* `CTRL + N`              New file
* `CTRL + O`              Open file      
* `CTRL + S`              Save file
* `CTRL + Shift + S`      Save file as


## How to Use
### using Cauce
1. Open CMD in the GUI directory, type ```python ctk.py```
2. Write your Code inside
3. Hit Compile!


### Headless
1. ```flex lexer.l```
2. ```bison -d parser.y```
3. ```cc *.c -o out.exe```
4. write your Code inside a file, for example myCode.txt
5. ```.\out.exe myCode.txt```


### Outputs
* `stackassembly.txt` our assembly stack machine program
* `symboltable.txt` the final symbol table after complete compilation
* `symboltablelogs.txt` log file containing the symbol table step by step (very useful for debugging)
* `ParsingErrors.txt` containing all indeces of lines with Syntax errors
* `SemanticErrors.txt` contains all indeces of lines if any semantic warning gets raised

## Prerequisites
* GCC or G++ or CC
* GNU's Flex or Lex
* GNU's Bison or Yacc
* Python >= 3.8
* TKinter and Custom TKinter    ```pip install tkinter customtkinter```


## Build it yourself!
you can find our guide on how to install lex and bison on windows and linux from here:
https://docs.google.com/document/d/1MAyArnxpMbBoU88uCNGYJ-3RBwjH-wLrotDa0c85Uew/edit?usp=sharing

then just clone the repo and use it as mentioned above :)



## Future plans
* Cudo | Crust's friendly debugger
* Better UI Features
* Linking multiple code files, Imports and externs
* An actual VM instead of using an external assembler to execute our stack-machine code


## Credits
This repo was made by our sweat and tears, a duty to mention them for credits:
@Marim1611
@mariemzayn18
@abeerhbadr
@aymanreda56

⣿⣿⣿⣿⣿⣿⠿⢋⣥⣴⣶⣶⣶⣬⣙⠻⠟⣋⣭⣭⣭⣭⡙⠻⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡿⢋⣴⣿⣿⠿⢟⣛⣛⣛⠿⢷⡹⣿⣿⣿⣿⣿⣿⣆⠹⣿⣿⣿⣿
⣿⣿⣿⡿⢁⣾⣿⣿⣴⣿⣿⣿⣿⠿⠿⠷⠥⠱⣶⣶⣶⣶⡶⠮⠤⣌⡙⢿⣿
⣿⡿⢛⡁⣾⣿⣿⣿⡿⢟⡫⢕⣪⡭⠥⢭⣭⣉⡂⣉⡒⣤⡭⡉⠩⣥⣰⠂⠹
⡟⢠⣿⣱⣿⣿⣿⣏⣛⢲⣾⣿⠃⠄⠐⠈⣿⣿⣿⣿⣿⣿⠄⠁⠃⢸⣿⣿⡧
⢠⣿⣿⣿⣿⣿⣿⣿⣿⣇⣊⠙⠳⠤⠤⠾⣟⠛⠍⣹⣛⣛⣢⣀⣠⣛⡯⢉⣰
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡶⠶⢒⣠⣼⣿⣿⣛⠻⠛⢛⣛⠉⣴⣿⣿
⣿⣿⣿⣿⣿⣿⣿⡿⢛⡛⢿⣿⣿⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡈⢿⣿
⣿⣿⣿⣿⣿⣿⣿⠸⣿⡻⢷⣍⣛⠻⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢇⡘⣿
⣿⣿⣿⣿⣿⣿⣿⣷⣝⠻⠶⣬⣍⣛⣛⠓⠶⠶⠶⠤⠬⠭⠤⠶⠶⠞⠛⣡⣿
⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣬⣭⣍⣙⣛⣛⣛⠛⠛⠛⠿⠿⠿⠛⣠⣿⣿
⣦⣈⠉⢛⠻⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⣁⣴⣾⣿⣿⣿⣿
⣿⣿⣿⣶⣮⣭⣁⣒⣒⣒⠂⠠⠬⠭⠭⠭⢀⣀⣠⣄⡘⠿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡈⢿⣿⣿⣿⣿⣿