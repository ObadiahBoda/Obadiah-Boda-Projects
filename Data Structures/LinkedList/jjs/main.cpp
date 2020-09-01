#include <iostream>
#include <cstdlib>


//no doubles,   1 sub 10, 1 16+, 1 14+



using namespace std;

int roll()
{
    int t;
    int comp;
    int number1;
int number2;
int number3;
int number4;


    for(int j = 0; j < 7; j++)
    {

        number1 = rand()%6+1;
        number2 = rand()%6+1;
        number3 = rand()%6+1;
        number4 = rand()%6+1;
        //cout <<number<<endl;
       if(number1 <= number2 && number1 <= number3 && number1 <= number4)
       {
           comp = number2 +number3 + number4;
       }
       else if(number2 <= number1 && number2 <= number3 && number2 <= number4)
       {
           comp = number1 +number3 + number4;
       }
       else if(number3 <= number2 && number3 <= number1 && number3 <= number4)
       {
           comp = number2 +number1 + number4;
       }
       else if(number4 <= number2 && number4 <= number3 && number4 <= number1)
       {
           comp = number2 +number3 + number1;
       }
       t = comp;

        }


    return t;
}



int main()
{
    int values[6];  //0 is low 5 is high
    for(int i = 0; i < 6; i++) values[i] = 19; // initialize array to zero's

    int temp;


    for(int i = 0; i < 6; i++)
    {
        temp = roll();

        int k = 0;

        while(temp > values[k])
        {
            k++;

        }

        values[k] = temp;
    }

    for(int i = 0; i < 6; i++)
    {
        cout << values[i] << " ";
    }



    return 0;
}
