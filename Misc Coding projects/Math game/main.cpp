//Obadiah Boda
//Final project
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <windows.h>

using namespace std;


class math
{
   public:
 char operation;
 int i= -1;
 int f= -1;
 int variable;
 double time1, time2;
 double points = 0;

   math();
    void correct();
    void incorrect();
    void finish();
    void what_is_it();
};


math::math()
{
while(operation != '+' && operation != '-' && operation != '*' && operation != '/' )
{

cout << "What type of math operation would you like to preform? (+,-,*,/) "<<endl;
cin >> operation;
}

while(i < 0 || f < 0)
{

cout << endl << "What is the range of numbers you would like to practice?"<<endl<< "must be positive integers(10 20) uses numbers between 10 and 20"<<endl;
cin >> i>> f;
}
if (i > f){
    int temp = f;
    f = i;
    i = temp;
}

int rand1, rand2;

time1 = time(NULL);

if (operation == '+')   //addition
{

   for(int j =0; j <= 4 ;j++){
int temp = f - i+1;
srand(time(NULL));
rand1 = rand()%temp + i ;
rand2 = rand()%temp + i ;
variable = rand1 + rand2;
cout<<endl << rand1 << " + " << rand2 << " = ";
what_is_it();

   }
   finish();
}

else if(operation == '-')  // subtraction
{
    for(int j =0; j <= 4 ;j++){

int temp;
int temp1 = f - i+1;
srand(time(NULL));
rand1 = rand()%temp1 + i ;
rand2 = rand()%temp1 + i ;

if (rand1> rand2){
  temp = rand1;
  rand1 = rand2;
  rand2 = temp;
}
variable =rand2 - rand1;
cout<<endl << rand2<<" - "<<rand1<< " = ";
what_is_it();
    }

   finish();

}

else if(operation == '/') // division
{
for(int j =0; j <= 4 ;j++){
int x,y;
int temp = f - i+1;
srand(time(NULL));
rand1 = rand()%temp + i ;
rand2 = rand()%temp + i ;

x = rand1*rand2;
y = rand2;

variable = x/y;
cout <<endl<< x << " / "<< y << " = ";
what_is_it();

}
finish();
}

else if(operation == '*')  // multiplication
{
   for(int j =0; j <= 4 ;j++){
int temp = f - i+1;
srand(time(NULL));
rand1 = rand()%temp + i;
rand2 = rand()%temp + i ;
variable = rand1*rand2;
cout<<endl <<rand1 <<" * " <<rand2<< " = ";
what_is_it();

}
finish();
}

}

void math::correct()
{
    system("CLS");
points = points +1;
system("color A5");
cout << "                                                points "<< points <<endl;
}

void math::incorrect()
{
points--;
system("color C5");
cout << "                                                points "<< points<< endl<< "the correct answer was " << variable<<endl;
system("pause");
system("color B2");
}

void math::finish()
{
    double a, b, c;
    string repeat, d,e,g,name;
system("CLS");
    time2 = time(NULL);
cout<<"this is your score ->" << (points/ (time2 - time1))*1000<<endl;
double score =(points/ (time2 - time1))*1000;

ifstream file;
if(operation == '+'){
file.open("highscore+.txt");
if(file.fail()){

        file.close();

ofstream newfile;
newfile.open("highscore+.txt");
newfile<< "0000 0000 0000"<<endl<<"AAA" << "AAA" << "AAA" ;
a=0;
b=0;
c=0;
d="AAA";
e="AAA";
g="AAA";
newfile.close();

}
    else{
    file >> a >> b >> c >> d >> e >> g;
        file.close();
    }
if(score>c){
    cout << "Congratulations you made a highscore. please enter your name"<<endl;
    cin >> name;
}

 ofstream newfile;
    newfile.open("highscore+.txt");
if(score > a){
   newfile<< score<< " "<< a<<" "<< b<<endl<< name << " " << d << " " << e;
}

else if(score > b){
    newfile<< a<< " "<< score <<" "<< b<<endl<< d <<" "<< name <<" "<< e;
}

else if(score > c){
    newfile<< a<< " "<< b<<" "<< score<<endl<< d <<" "<< e <<" "<< name;
}


newfile.close();

}
else if(operation == '-'){
    file.open("highscore-.txt");
if(file.fail()){
        file.close();

ofstream newfile;
newfile.open("highscore-.txt");
newfile<< "0000 0000 0000"<<endl<<"AAA" << "AAA" << "AAA" ;
a=0;
b=0;
c=0;
d="AAA";
e="AAA";
g="AAA";
newfile.close();
}

    else{
      file >> a >> b >> c >> d >> e >> g;
        file.close();
    }
if(score>c){
    cout << "Congratulations you made a highscore. please enter your name"<<endl;
    cin >> name;
}

 ofstream newfile;
    newfile.open("highscore-.txt");
if(score > a){
   newfile<< score<< " "<< a<<" "<< b<<endl<< name << " " << d << " " << e;
}

else if(score > b){
    newfile<< a<< " "<< score <<" "<< b<<endl<< d <<" "<< name <<" "<< e;
}

else if(score > c){
    newfile<< a<< " "<< b<<" "<< score<<endl<< d <<" "<< e <<" "<< name;
}

newfile.close();
}

else if (operation == '/'){
    file.open("highscoredivision.txt");
    if(file.fail()){
        file.close();

ofstream newfile;
newfile.open("highscoredivision.txt");
newfile<< "0000 0000 0000"<<endl<<"AAA" << "AAA" << "AAA" ;
a=0;
b=0;
c=0;
d="AAA";
e="AAA";
g="AAA";
newfile.close();
}

    else{
file >> a >> b >> c >> d >> e >> g;
        file.close();
    }

if(score>c){
    cout << "Congratulations you made a highscore. please enter your name"<<endl;
    cin >> name;
}

 ofstream newfile;
    newfile.open("highscoredivision.txt");
if(score > a){
   newfile<< score<< " "<< a<<" "<< b<<endl<< name << " " << d << " " << e;
}

else if(score > b){
    newfile<< a<< " "<< score <<" "<< b<<endl<< d <<" "<< name <<" "<< e;
}

else if(score > c){
    newfile<< a<< " "<< b<<" "<< score<<endl<< d <<" "<< e <<" "<< name;
}

newfile.close();
}

else{
    file.open("highscorem.txt");
    if(file.fail()){
        file.close();

ofstream newfile;
newfile.open("highscorem.txt");
newfile<< "0000 0000 0000"<<endl<<"AAA" << "AAA"<< "AAA" ;
a=0;
b=0;
c=0;
d="AAA";
e="AAA";
g="AAA";
newfile.close();
}

    else{
file >> a >> b >> c >> d >> e >> g;
        file.close();
    }

if(score>c){
    cout << "Congratulations you made a highscore. please enter your name"<<endl;
    cin >> name;
}

 ofstream newfile;
    newfile.open("highscorem.txt");
if(score > a){
   newfile<< score<< " "<< a<<" "<< b<<endl<< name << " " << d << " " << e;
}

else if(score > b){
    newfile<< a<< " "<< score <<" "<< b<<endl<< d <<" "<< name <<" "<< e;
}

else if(score > c){
    newfile<< a<< " "<< b<<" "<< score<<endl<< d <<" "<< e <<" "<< name;
}

newfile.close();
}

system("CLS");
cout<< "scoreboard" <<endl<<"score, name"<<endl;
if(score > a){
   cout<<fixed<<setprecision(1)<<setw(6)<< score<< ", " << name <<endl<< a << ", "<< d << endl << b  <<", "<< e;
}

else if(score > b){
    cout<<fixed<<setprecision(1)<<setw(6)<< a<< ", " << d <<endl<<score << ", "<< name << endl << b  <<", "<< e;
}

else if(score > c){
    cout<<fixed<<setprecision(1)<<setw(6)<< a<< ", " << d <<endl<< b << ", "<< e << endl << score  <<", "<< name;
}

Sleep(5000);
system("CLS");


cout <<endl << "would you like to rerun the program? (yes) "<< endl;
cin >> repeat;

if(repeat == "yes"){
   system("CLS");
    math();
}
}


void math::what_is_it(){
int solution;
cin >> solution;
if (solution == variable){
    correct();
}

else{
    incorrect();
}
}


int main()
{
    math game;
    return 0;
}


