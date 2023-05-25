# :spades: Crust :spades:


## a lightweight C-like programming language and compiler, with a user friendly GUI

<p align="center" width="100%">
    <img src="https://github.com/aymanreda56/CL_Project/blob/main/assets/img/3704947507_blue%20triangle%20logo,%20baby%20blue%20color,%20vectorized%20lo_xl-beta-v2-2-2.png?raw=true" width="450" height="450"> 
</p>

This project was implemented as our Compilers' course project.
It essentially implements the full compiler pipeline : Front-End  |  IR  | Back-End

<p align="center" width="100%">
    <img src="https://www.guru99.com/images/1/020819_1119_PhasesofCom1.png" width="700" height="200"> 
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

# Syntax 📄
you can find our Language rules here:
https://docs.google.com/document/d/1AywCNfDTK4mzxmF-IoVwgKzLli8sE6zEiFXHfqb00Ug/edit?usp=sharing



<h2> Watch our <a href="https://youtu.be/KR75qdKQD28"target="_blank">demo</a> ! 💫</h2>



https://github.com/aymanreda56/CL_Project/assets/58632281/85bdec56-78f4-4c70-b7b6-8e3194e7df04



![pasted image 0](https://github.com/aymanreda56/CL_Project/blob/main/assets/img/pasted%20image%200.png?raw=true)


# Symbol Table 📅
- Final symbol table of a program.

![image](https://github.com/aymanreda56/CRUST/assets/76243256/31f6bf51-e458-4f83-bab1-62e0ecb644c2)

- Symbol table logs after each change in the code.
- In the image below logs after the following statement: string t = "CRUST" ; 

![image](https://github.com/aymanreda56/CRUST/assets/76243256/e2ea6590-63d7-48b0-9b08-a1111db36c7e)


## Hot-Keys ✨
* `CTRL + N`              New file
* `CTRL + O`              Open file      
* `CTRL + S`              Save file
* `CTRL + Shift + S`      Save file as


## How to Use 🔍
### - Using Cauce ❓
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


