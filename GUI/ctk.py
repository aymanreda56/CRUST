import tkinter as tk
from tkinter import filedialog
from tkinter import font
import re
import subprocess
import os
import customtkinter as ct

def removeFiles():
    if(os.path.isfile('./ParsingErrors.txt')):
        os.remove('./ParsingErrors.txt')
    if(os.path.isfile('./SemanticErrors.txt')):
        os.remove('./SemanticErrors.txt')

removeFiles()

global opened_file_name,TerminalOutput, Assembly, success, digitsS, digitsP
opened_file_name = False
TerminalOutput = False
Assembly=False
success = False
digitsS = None
digitsP = None

def lexyacccompile():
    global digitsS, digitsP
    removeFiles()
    if(digitsS):
        for i in digitsS:
            text.tag_remove(i, f"{i}.0", "end")
    if(digitsP):
        for i in digitsP:
            text.tag_remove(i, f"{i}.0", "end")
    save_as_file(TempName=True)
    status_bar.configure(text="Compiling... ", font=("Helvetica",16), fg_color="green")
    compiler = ".\out.exe temp.txt"
    in_stream = [compiler, "temp.txt"]
    data, temp = os.pipe()
    #os.write(temp, bytes("temp.txt\n", "utf-8"));
    #os.close(temp)
    process = subprocess.check_output(compiler,stdin=data, creationflags=0x08000000, shell=True)
    
    print(process.decode("utf-8"))
    global TerminalOutput
    TerminalOutput = process.decode("utf-8")
    split_window()
    show_assembly()
    highLightParseError()
    highLightSemanticError()
    global success
    if(success == 1):
        status_bar.configure(text="SYNTAX ERROR... ", font=("Helvetica",16), fg_color="#BF1363")
    elif(success == 2):
        status_bar.configure(text="Semantic Warning... ", font=("Helvetica",16), fg_color="#F39237")
    else:
        status_bar.configure(text="Compiled !", font=("Helvetica",16), fg_color="green")
 




def dummy():
    removeFiles()
    global digitsS, digitsP
    if(digitsS):
        for i in digitsS:
            text.tag_remove(i, f"{i}.0", "end")
    if(digitsP):
        for i in digitsP:
            text.tag_remove(i, f"{i}.0", "end")
    save_as_file(TempName=True)
    status_bar.configure(text="Compiling... ", font=("Helvetica",16), fg_color="green")
    global TerminalOutput
    TerminalOutput = "HEEEEEELOOOOOOOOOOOOOO\n HEEELooo"

    split_window()
    show_assembly()
    highLightParseError()
    highLightSemanticError()
    global success
    if(success == 1):
        status_bar.configure(text="SYNTAX ERROR... ", font=("Helvetica",16), fg_color="#BF1363")
    elif(success == 2):
        status_bar.configure(text="Semantic Warning... ", font=("Helvetica",16), fg_color="#F39237")
    else:
        status_bar.configure(text="Compiled !", font=("Helvetica",16), fg_color="green")
 





def split_window():
    otherFrame.pack(side = ct.LEFT)
    global TerminalOutput
    TerminalPanel.pack(expand=True,fill=ct.X, side=ct.LEFT, ipady=30, ipadx=30)
    TerminalPanel.configure(text=TerminalOutput)

def show_assembly():
    otherFrame2.pack(side=ct.RIGHT)
    global Assembly
    AssemblyPanel.pack(expand=True,fill=ct.X, side=ct.RIGHT, ipady=30, ipadx=30)
    with open('stackassembly.txt') as f:
        contents = f.read()
        Assembly = contents
    
    AssemblyPanel.configure(text=Assembly)
   


def highLightParseError():
    global digitsP
    digitsP = None
    if(os.path.exists('./ParsingErrors.txt')):
        with open('ParsingErrors.txt') as f:
            contents = f.read()
            digitsP = re.findall('\d+', contents)
    
    if(digitsP):
        global success
        success = 1
        for i in digitsP:
            text.tag_add(str(i), f"{i}.5 linestart",f"{i}.5 lineend")
            text.tag_config(str(i), background= "red", foreground= "#FAF33E")


def highLightSemanticError():
    global digitsS, success
    digitsS = None
    if(os.path.exists('./SemanticErrors.txt')):
        with open('SemanticErrors.txt') as f:
            contents = f.read()
            digitsS = re.findall('\d+', contents)

    
    if(digitsS):
        if(not success):
            success = 2
        for i in digitsS:
            text.tag_add(str(i), f"{i}.5 linestart",f"{i}.5 lineend")
            text.tag_config(str(i), background= "yellow", foreground= "#A4243B")



#self.tag_remove('currentLine', 1.0, "end")
#self.tag_add('currentLine', 'insert linestart', 'insert lineend+1c')



def open_file(dummy = False):
    global digitsS, digitsP, success
    success = False
    removeFiles()
    if(digitsS):
        for i in digitsS:
            text.tag_remove(i, f"{i}.0", "end")
    if(digitsP):
        for i in digitsP:
            text.tag_remove(i, f"{i}.0", "end")
    TerminalPanel.pack_forget()
    AssemblyPanel.pack_forget()
    otherFrame.pack_forget()
    otherFrame2.pack_forget()
    status_bar.configure(font=("TkDefaultFont",11), fg_color="grey")
    file = filedialog.askopenfilename(filetypes=[("Text Files", "*.txt"), ("Python", "*.py"), ("cpp", "*.cpp"),("C", "*.c"),("All Files", "*.*")])
    name = file
    if file:
        global opened_file_name
        opened_file_name = name
        text.delete("1.0", ct.END)
        with open(file, "r") as file:
            text.insert(ct.END, file.read())
    name = re.split('/',name)[-1]
    status_bar.configure(text=f"{name}   ")


def new_file(dummy = False):
    global digitsS, digitsP, success
    success = False
    removeFiles()
    if(digitsS):
        for i in digitsS:
            text.tag_remove(i, f"{i}.0", "end")
    if(digitsP):
        for i in digitsP:
            text.tag_remove(i, f"{i}.0", "end")
    TerminalPanel.pack_forget()
    AssemblyPanel.pack_forget()
    otherFrame.pack_forget()
    otherFrame2.pack_forget()
    status_bar.configure(font=("TkDefaultFont",11), fg_color="grey")
    text.delete("1.0", ct.END)
    root.title("New File !")
    status_bar.configure(text="New File Created !    ")
    global opened_file_name
    opened_file_name = False




def save_as_file(TempName = False):
    global digitsS, digitsP, success
    success = False
    removeFiles()
    if(digitsS):
        for i in digitsS:
            text.tag_remove(i, f"{i}.0", "end")
    if(digitsP):
        for i in digitsP:
            text.tag_remove(i, f"{i}.0", "end")
    TerminalPanel.pack_forget()
    AssemblyPanel.pack_forget()
    otherFrame.pack_forget()
    otherFrame2.pack_forget()
    status_bar.configure(font=("TkDefaultFont",11), fg_color="grey")
    global opened_file_name
    if(not TempName):
        file = filedialog.asksaveasfilename(defaultextension="*.txt", filetypes=[("Text Files", "*.txt"), ("Python", "*.py"), ("cpp", "*.cpp"),("C", "*.c"),("All Files", "*.*")])
        name = file
        if file:
            with open(file, "w") as file:
                file.write(text.get("1.0", ct.END))
            global opened_file_name
            opened_file_name = name
            name = re.split('/',name)[-1]
            status_bar.configure(text=f"File {name} saved !    ")
    else:
        file = "./temp.txt"
        name = file
        with open(file, "w") as file:
                file.write(text.get("1.0", ct.END))
        
        opened_file_name = name
        name = re.split('/',name)[-1]
        status_bar.configure(text=f"File {name} saved !    ")

def save_file(clicked=False):
    global digitsS, digitsP, success
    success = False
    removeFiles()
    if(digitsS):
        for i in digitsS:
            text.tag_remove(i, f"{i}.0", "end")
    if(digitsP):
        for i in digitsP:
            text.tag_remove(i, f"{i}.0", "end")
    TerminalPanel.pack_forget()
    AssemblyPanel.pack_forget()
    otherFrame.pack_forget()
    otherFrame2.pack_forget()
    status_bar.configure(font=("TkDefaultFont",11), fg_color="grey")
    global opened_file_name
    if opened_file_name:
        with open(opened_file_name, "w") as file:
            file.write(text.get("1.0", ct.END))
    else:
        save_as_file()
    
    status_bar.configure(text=f"File {opened_file_name} saved !    ")

root = ct.CTk()
root.title("Simple Code Editor")
root.geometry("1200x600")
root.bind('<Control-Shift-s>', save_as_file)
root.bind('<Control-Key-s>', save_file)
root.bind('<Control-Key-n>', new_file)
root.bind('<Control-Key-o>', open_file)


main_frame = ct.CTkFrame(root)



text = ct.CTkTextbox(root, font=("Helvetica", 25), activate_scrollbars=True ,undo = True)
text.pack(expand=True, fill=ct.BOTH, padx=20)


'''
menu = ct.CTkOptionMenu(root)
root.config(menu=menu)

file_menu = ct.CTkOptionMenu(menu, tearoff=False, hover=True)
menu.add_cascade(label="File", menu=file_menu)
file_menu.add_command(label="New", command=new_file)
file_menu.add_command(label="Open", command=open_file)
file_menu.add_command(label="Save", command=save_file)
file_menu.add_command(label="Save As", command=save_as_file)
file_menu.add_separator()
file_menu.add_command(label="Exit", command=root.quit)

'''



compilerButton = ct.CTkButton(root, text="Compile !",border_spacing=10, command=lexyacccompile, font=("Arial",20), hover=True)
compilerButton.pack(side=ct.RIGHT, pady=5)

status_bar = ct.CTkButton(root, text="ready   ", anchor=ct.E, fg_color='grey')
status_bar.pack(fill=ct.X, side=ct.BOTTOM, pady=5)


#terminalFram = ct.CTkScrollableFrame(root)
#AssemblyFram = ct.CTkScrollableFrame(root)
otherFrame = ct.CTkScrollableFrame(root, width=600)

otherFrame2 = ct.CTkScrollableFrame(root, width=300)
TerminalPanel = ct.CTkLabel(otherFrame, text=TerminalOutput)#,yscrollcommand=Terminalscrollbar.set)#ct.CTkLabel(root, text=TerminalOutput, anchor=ct.W, justify='left')#,yscrollcommand=Terminalscrollbar.set)
AssemblyPanel = ct.CTkLabel(otherFrame2, text=Assembly,font=("Input", 20), bg_color="#333333", justify='left')#ct.CTkLabel(root, text=Assembly, anchor=ct.W, font=("Input", 15), bg_color="#333333", justify='left')


#Terminalscrollbar = ct.CTkScrollbar(TerminalPanel, command=TerminalPanel.yview)
#Terminalscrollbar.pack(side=tk.RIGHT, fill=tk.Y)
#TerminalPanel.configure(yscrollcommand=Terminalscrollbar.set)
#Terminalscrollbar.config(command=TerminalPanel.yview)




root.mainloop()