 /* 'important instraction'
    the equation should look like : c1x^c2+c3
    c1 if there is no c1 it will be 1 by default and c1 could be +ve or -ve or float 
    c2 if there is no ^c2 it will be 1 by default and c2 could be +ve or -ve or float 
    you can add more than one full equation like c1x^c2+c3x^c4+c5 and so on
    c3 and c5 sholud be freely and in end of equation and if they not there it will be 0 by default 
    and they could be +ve or -ve or float 
    if the Trapezoidal value near to true value more than simpsons
    this mean the function is nearly linear 
 */
#include <iostream>
#include <sstream>///give us accsess to use strirng stream library that allow us to active with string like cin stream and turn string to int
#include <cmath>
using namespace std;
struct three ///**struct allow me to return 3 values from function**
{
    double tra ;
    double sim ;
    double tru ;
};
three integration(int n ,double b , double a ,double parx, double powx , double behx  );///prototybe of the function that do the integration with numerical methods
int main ()
{  
    while (1) {
    int index_num=0,index=0;
    double numbers[50];
    string eq;
    string num_in_str[50];
    cout << "please enter 'e' to end else to continue : ";
    string ask;
    cin >> ask;
    if (ask =="e")
    break;
    cout << "f(x)=";
    cin.ignore(1);
    getline(cin , eq );///take the whole equation in one line
    int cnt=eq.length();
    for ( index ; index<cnt;index++)///for loop to separate numbers that we will operate on from equation
    {
     if (eq[index]=='+' && eq[index+1]=='x' )
    {  
        index_num++;
        num_in_str[index_num]='1';
    }
    else if (eq[index]=='-' && eq[index+1]=='x' )
    {  
         if (index!=0)
            index_num++;
        num_in_str[index_num]="-1";
    }
    else if (eq[index]=='x')
    {
        if (index==0)
        num_in_str[0]='1';
        index_num++;
        if (eq[index+1]!='^'){
        num_in_str[index_num]='1';
        }
        else index++;
    }
    else if (eq[index]=='+' && eq[index+1]!='x' )
    index_num++;
    else if (eq[index]=='-' && eq[index+1]!='x' )
    {
        if (eq[index-1]=='^')
        num_in_str[index_num]='-';
        else
        {
            if (index!=0)
            index_num++;
            num_in_str[index_num]='-';
        }
    }
    else
     num_in_str[index_num]+=eq[index];
    };
    cout <<"the next lines is for notice only **\n";///show the numbers that taken from equation 
    for (int looper = 0 ;looper<=index_num;looper++)
    {
        stringstream geek (num_in_str[looper]);
        geek >> numbers[looper];
        cout <<"number "<<looper+1<<" : "<<numbers[looper]<<endl;
    };
    cout <<"end of notation---------------------\n";
    cout << "Enter integration limits\n";
    double    a = 0;///start
    cout << "from \na="; cin >> a;
    cout << "\n";
    double    b = 0;///end
    cout << "to \nb="; cin >> b; cout << "\n";
    int    n = 0;
    cout << "Enter n where n>2 and less than 10000 \n ";
    cin >> n; ///number of points
    if (cin.fail())
    break;
    while (n <= 2||n>9999)
    {
        cout<< "Enter n where n>2 and less than 10000 \n ";
        cin >> n;  
          
    };
    three tri ;
    three trip ;
    trip.sim=0;
    trip.tra=0;
    trip.tru=0;
    int nm = ++index_num;
    if ( index_num==3)///if its one function with free term
    {
        tri = integration( n , b , a , numbers[ index_num-3] , numbers[ index_num-2] ,numbers[ index_num-1]);
        trip.sim+=tri.sim;
        trip.tra+=tri.tra;
        trip.tru+=tri.tru;
    }else /// if more than one function as we know in integration we can separate the added functions 
    {
      if (nm%2==1) //if more than one function and there is free term
      {
      nm= index_num-3;
     };
    for (int k=0;k<nm;)///here we integrate and add the separated functions 
    {
    tri = integration( n , b , a , numbers[k] , numbers[k+1] , 0);
    trip.sim+=tri.sim;
    trip.tra+=tri.tra;
    trip.tru+=tri.tru;
    k+=2;
    };
    if ( index_num%2==1)       ///if we have a free term and more than 1 function last function with 
    {                          //the free term go in special case integtation function and added to the sum of all ingrated functions
    tri = integration( n , b , a , numbers[ index_num-3] , numbers[ index_num-2] ,numbers[ index_num-1]);
    trip.sim+=tri.sim;
    trip.tra+=tri.tra;
    trip.tru+=tri.tru;
    };
    };
    ///here show the last result
    cout << "Trapezoidal rule = "<<trip.tra<<endl;
    cout << "simpisons rule = "<<trip.sim<<endl;
    cout << "exact value = "<< trip.tru<<endl;
    };
    return 0;
};
///integration functions with numerical  methods
three integration(int n ,double b , double a ,double parx, double powx, double behx)
{
    
    cout << "The equation is\n";
    cout << parx << "X^" << powx;
    if (behx >= 0)
        cout << "+";
    cout << behx << "\n";
    double h = (double)(b - a) / (n - 1);
    double fa = parx * pow(a, powx) + behx;
    double fb = parx * pow(b, powx) + behx;
    double fx[9999];
    int i = 1;
    double fxsum = 0, fxeven = 0, fxodd = 0,fxsumt=0;
    while (i<=n-2)
    {
        fx[i]= parx * pow(a +i* h, powx) + behx;
        fxsum += fx[i];
        if (i % 2 == 0)
            fxeven += fx[i];
        else
            fxodd += fx[i];

        i++;
    }
    i=1;
    double htru = (double)(b - a) / (10000 - 1);
    while (i<=9998) ///to get the nearly true value we but n so big so it will look like no moves happens
    {
        fx[i]= parx * pow(a +i* htru, powx) + behx;
        fxsumt += fx[i];
        i++;
    };
    three thr;
    cout << "Trapezoidal rule\n";
    double o;
    double Itra = (h / 2) * (fa + fb +( 2 * fxsum));
    cout << "I=" << Itra << "\n\n";
    thr.tra=Itra;
    double Isimfour=0, Isimodd=0, Isimeve=0;
    double restodd = fxodd - (fx[1]+fx[3]);///here we sparate the points that we will use in first 4 points in simpsons 3/8 from summiton of odd numbers
    double resteven = fxeven - fx[2];///here we sparate the points that we will use in first 4 points in simpsons 3/8 from summiton of even numbers 
    cout << "Simpsons rule\n";
    if (n == 4)///if n = 4 we will use simpsons 3/8
    {
        Isimfour = (3 * h / 8) * (fa + fb + (3 * fxsum));
        cout << "I=" << Isimfour << "\n\n";
        thr.sim=Isimfour;
    }   
    else if (n % 2 != 0)///if n is odd we will use simpsons 1/3
    {
        Isimodd = (h / 3) * (fa + fb + (4 * fxodd) + (2 * fxeven));
        cout << "I=" << Isimodd << "\n\n";
        thr.sim=Isimodd;
    }
    else///if n is even and biger than 4 we will use both simpsons 1/3 and for first 4 we will use simpsons 3/8
     {
        Isimfour = (3 * h / 8) * (fa + fx[3] + (3 * (fx[1]+fx[2])));
        Isimodd = h / 3 * (fx[3] + fb+(4*resteven)+(2*restodd));
        Isimeve = Isimfour + Isimodd;
        cout << "I=" << Isimeve << "\n\n";
        thr.sim=Isimeve;
    }
    double Itru = (htru / 2) * (fa + fb +( 2 * fxsumt));
    thr.tru= Itru;
    return thr;
   }
  

