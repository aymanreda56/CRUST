int a;
int a = 5;
int a = 5 + 4;
string aymon = "12a3_";
int b = a;

a = b;
a = 5 + 5 * 2;
a = true;
(a) = 5;             //should be unaccepted, in cpp it is accepted though, but we will assume no parenthesis are put as an lval
b = (a + 6);

b = 6 > 3;

int AI = 4;   //constant declaration
AI = 1;         //unaccepted
int b = AI;    //accepted

if a > 3: {int b = 1 + 3; }

if a > 3: {int b = 1 + 3; } else {b = 1 * r ^2;}

enum newEnum {id1, id2, id3}
enum newEnum {id1=1, id2=2, id3=3}



switch var:
{
case 3:  {print('lol');}
case var>1: {var++;}
}


int funcName(int arg) {int lol = 5 * 4; }
int funcName(int arg1, int arg2, int arg3) {int lol = 5 * 4; }

while a + 4 > b * e : { t = 1; int g = 1 + 3; }

for (i; i > 1; i++;) { print("lol"); }
for (int i = 0; i > 1; i++;) { print("lol"); }
for (int i; i > 1; i= i+1;) { print("lol"); }
for (int i; i > 1; i= i+1;) { int k = 4; } 
for (int i; i + 1; print("hellooo");) { print("lol"); }
for (int i; i + 1; print("hellooo");) { print("lol"); }
for (; ;) {int j = 6; }         //still not handled, why tf would anyone write this in the first place ?!

do {for (i; i > 1; i++;) { print("lol"); if a > 3: {int b = 1 + 3; } else {b = 1 * r ^2;} enum newEnum {id1=1, id2=2, id3=3}}} while(a >= 0)


