# :spades: Crust :spades:


## a lightweight C-like programming language and compiler, with a user friendly GUI

<p align="center" width="100%">
    <img src="https://github.com/aymanreda56/CL_Project/assets/58632281/676bca67-c107-462c-a8f5-31598cf0506d" width="450" height="450"> 
</p>

This project was implemented as our Compilers' course project.
It essentially implements the full compiler pipeline : Front-End  |  IR  | Back-End


<p align="center" width="100%">
    <img src="https://github.com/aymanreda56/CL_Project/assets/58632281/ab1e8fa8-01c8-4ee7-b847-8862ed66ed72" width="450" height="150"> 
</p>


* "We used C to make C", this project was entirely written in C. Such speed, less space. 
* Uses Flex and Bison's implementation for Lex and Yacc.
* Friendly Syntax
* Not Strictly typed
* Predictive and informative error handling
* Produces stack machine assembly. Aiming for compatibility with different CPU architectures.
* Cauce -pronounced as "Sauce"- is our minimalistic GUI using TKinter.
* Supports advanced programming schemes like Recursions, Nest-oriented programming, structs, Polymorphism, etc.
* Debugger [Future plans]

# Document Link 📄

# //TODO, add BNF diagrams (so that graph theory students can see our repo).
you can find our Language rules here. 
also you can find the BNF diagram for our language here. 

<h2> Watch our <a href="https://youtu.be/KR75qdKQD28"target="_blank">demo</a> !</h2>




https://github.com/aymanreda56/CL_Project/assets/58632281/6eb28bbd-8e76-40b4-a42e-9b1588303063




![pasted image 0](https://github.com/aymanreda56/CL_Project/assets/58632281/7a899a3e-bde9-4e1a-b8a1-619864c043f2)



## Hot-Keys ✨
* `CTRL + N`              New file
* `CTRL + O`              Open file      
* `CTRL + S`              Save file
* `CTRL + Shift + S`      Save file as


## How to Use 🔍
### - using Cauce ❓
1. Open CMD in the GUI directory, type ```python ctk.py```
2. Write your Code inside
3. Hit Compile!


### - Headless 💫
1. ```flex lexer.l```
2. ```bison -d parser.y```
3. ```cc *.c -o out.exe```
4. write your Code inside a file, for example myCode.txt
5. ```.\out.exe myCode.txt```


### - Outputs ⚡
* `stackassembly.txt` our assembly stack machine program
* `symboltable.txt` the final symbol table after complete compilation
* `symboltablelogs.txt` log file containing the symbol table step by step (very useful for debugging)
* `ParsingErrors.txt` containing all indeces of lines with Syntax errors
* `SemanticErrors.txt` contains all indeces of lines if any semantic warning gets raised

## Prerequisites ⚙️
* GCC or G++ or CC
* GNU's Flex or Lex
* GNU's Bison or Yacc
* Python >= 3.8
* TKinter and Custom TKinter    ```pip install tkinter customtkinter```


## Build it yourself! 💡
you can find our guide on how to install lex and bison on windows and linux from here:
https://docs.google.com/document/d/1MAyArnxpMbBoU88uCNGYJ-3RBwjH-wLrotDa0c85Uew/edit?usp=sharing

then just clone the repo and use it as mentioned above :)



## Future plans :rocket: 
* Cudo | Crust's friendly debugger
* Better UI Features
* Linking multiple code files, Imports and externs
* An actual VM instead of using an external assembler to execute our stack-machine code


## Credits 👨‍💻 👩‍💻 👩‍💻 👩‍💻
> "Appreciation has the amazing habit of bringing more reasons to be grateful for."
### Special thanks to:
<table align="center">
  <tr>
     <td align="center">
    <a href="https://github.com/aymanreda56" target="_black">
    <img src="https://avatars.githubusercontent.com/u/58632281?v=4" width="100px;" alt="Ammar Mohamed"/>
    <br />
    <sub><b>Ayman Reda</b></sub></a>
    </td>
    <td align="center">
    <a href="https://github.com/Marim1611" target="_black">
    <img src="https://avatars.githubusercontent.com/u/76243256?s=120&v=4" width="100px;" alt="Marim Naser"/>
    <br />
    <sub><b>Marim Naser</b></sub></a>
    </td>
    <td align="center">
    <a href="https://github.com/mariemzayn18" target="_black">
    <img src="https://avatars.githubusercontent.com/u/76264155?s=120&v=4" width="100px;" alt="Mariem Muhammed"/>
    <br />
    <sub><b> Mariem Muhammed</b></sub></a>
    </td>
     <td align="center">
    <a href="https://github.com/abeerhbadr" target="_black">
    <img src="https://avatars.githubusercontent.com/u/56753821?v=4" width="100px;" alt="Abeer Hussein"/>
    <br />
    <sub><b>Abeer Hussein</b></sub></a>
    </td>
  </tr>
 </table>
</br>
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


