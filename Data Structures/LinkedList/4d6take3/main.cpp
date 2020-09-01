#include <iostream>
#include <cstdlib>


//no doubles,   1 sub 10, 1 16+, 1 14+



using namespace std;

int main()
{
int number1;
int number2;
int number3;
int number4;



int comp;
long int i = 100000;
int hits[19];
for (int k = 3; k <20; k++)
{
    hits[k]=0;
}

int ary[i];

double rep = 0;
double total = 0;
    for(int k = 0; k < i; k++)
    {
        number1 = rand()%6+1;
        number2 = rand()%6+1;
        number3 = rand()%6+1;
        number4 = rand()%6+1;
        //cout <<number<<endl;
       if(number1 <= number2 && number1 <= number3 && number1 <= number4)
       {
           comp = number2 +number3 + number4;
           total+= comp;
           hits[comp]++;
           ary[k] = number2 + number3 + number4;
       }
       else if(number2 <= number1 && number2 <= number3 && number2 <= number4)
       {
           comp = number1 +number3 + number4;
           total+= comp;
           hits[comp]++;
           ary[k] = number1 + number3 + number4;
       }
       else if(number3 <= number2 && number3 <= number1 && number3 <= number4)
       {
           comp = number2 +number1 + number4;
           total+= comp;
           hits[comp]++;
           ary[k] = number2 + number1 + number4;
       }
       else if(number4 <= number2 && number4 <= number3 && number4 <= number1)
       {
           comp = number2 +number3 + number1;
           total+= comp;
           hits[comp]++;
           ary[k] = number2 + number3 + number1;
       }

        rep++;
    }

double num = total/rep;
    cout << num << endl;

    for(int k = 0; k < i; k++)
    {
        if(ary[k] < 10)
        {
            cout << " " <<ary[k] << " ";
        }
        else cout <<ary[k] <<" ";

        if (k%35 == 0)
        {
            cout <<endl;
        }
    }

int select;
    int on = 1;
    while (on == 1)
    {
        cout << endl << "What number would you like to analyze?" <<endl;
        cin >> select;
        cout << endl << "There are " << hits[select] << " " << select << "'s out of " << rep << " trials." << endl;
        cout << hits[select]/rep<< endl;
        //cout << "Would you like to analyze another number?(1 == yes)";
       // cin >> on;
    }




    return 0;
}
