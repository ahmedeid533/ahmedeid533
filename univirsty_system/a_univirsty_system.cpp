#include <iostream>

#include <string>

#include <fstream>

#include <time.h>

using namespace std;

int main()
{
    while (1){
      
    time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  cout << asctime(timeinfo);
  cout <<"welcome to university management system\n";
    struct birth_date{
    int day;
    int month;
    int year;
    };
    struct student_data {
        string name ;
        int id ;
        birth_date birth;
        int attendance ;
    };
    struct reg {
        int id ;
        string sub[6];
        int year;
        int semester;
        int hours;
        int credit;
    };
  student_data student [1000]={};
  reg reg [1000]={};
  fstream student_data;
  fstream regist;
  student_data.open("student data.csv");
  int id=1;
  while (!student_data.eof()){
  getline (student_data,student[id].name,';');
  student_data>>student[id].id;
  student_data.ignore(1);
  reg[id].id=student[id].id;
  student_data>>student[id].birth.day;
  student_data.ignore(1);
  student_data>>student[id].birth.month;
  student_data.ignore(1);
  student_data>>student[id].birth.year;
  student_data.ignore(1);
  student_data>>student[id].attendance;
  student_data.ignore(1);
  id++;
  };
  regist.open("registration.csv");
  int m =id;
  id=1;
  while (id<2){
    for (int s=0;s<6;s++)
  getline (regist,reg[id].sub[s],';');
  regist>>reg[id].id;
  regist.ignore(1);
  regist>>reg[id].year;
  regist.ignore(1);
  regist>>reg[id].semester;
  regist.ignore(1);
  regist>>reg[id].hours;
  regist.ignore(1);
  regist>>reg[id].credit;
  student_data.ignore(1);
  id++;
  };
  while (id<m){
    regist.ignore(1);
    for (int s=0;s<6;s++)
  getline (regist,reg[id].sub[s],';');
  regist>>reg[id].id;
  regist.ignore(1);
  regist>>reg[id].year;
  regist.ignore(1);
  regist>>reg[id].semester;
  regist.ignore(1);
  regist>>reg[id].hours;
  regist.ignore(1);
  regist>>reg[id].credit;
  student_data.ignore(1);
  id++;
  };
  student_data.seekg(0);
  regist.seekg(0);
  cout << "\nif you are student your password is your id";
  cout << "\nif you are admin enter bin password\n";
  cout << "\nto finish the program enter -1\n";
  int x;
  while (1){
  cout <<"enter your password : ";
 while (1 ){
   if (cin.fail())
      return 0;
        cin >> x;
        if ( x>20000 && x<20000+m)
            break;
        if (x==1111 )
            break;
        if (x==-1 )
            break;
     cout << "please try again \n";
     cout <<"enter your password : ";
  };
  if (x==-1 )
        break;
  if (x==1111){
 cout << "to add new student enter new \nto edit the data of student or pay the credit enter edit \n";
 cout << "to enter the attendance of student enter attendance\n";
 string func1;
 do{
  cin >> func1;
 if (func1!="new"&&func1!="edit"&&func1!="attendance")
  cout <<"please enter valid operation \n";
 }while (func1!="new"&&func1!="edit"&&func1!="attendance");
 if (func1 == "new"){
    student[id].id=m+20000;
    cout << "please enter student name\n";
    cin.ignore();
    getline( cin , student[id].name);
    cout << "pleae enter his birth date\n";
    cout << "year : ";
    cin >> student[id].birth.year;
    cout << "month : ";
    cin >> student[id].birth.month;
    cout << "day : ";
    cin >> student[id].birth.day;
    cout << "please enter subjects he will regist in \n";
    cout << "if there is no subject enter nosub \n";
    int s;
    for (s=0;s<6;s++){
    cout << "subject " << s+1 << ": ";
    cin >> reg[id].sub[s];
     if (reg[id].sub[s]=="nosub")
     continue;
       reg[id].hours+=3;
   };
    reg[id].credit=(reg[id].hours*1000);
   cout << "please enter studying year : ";
   cin >> reg[id].year;
   cout << "please enter semester in form 1 for first and 2 for second : ";
   cin >> reg[id].semester;
   cout << "the ID :"<< m+20000 <<endl<<endl;
   m++;
     break;
}
else if (func1=="edit"){
    int i;
    do {
     cout << "pleas enter student id \n";
     cout << "should be in system data \n";
     cin >>i ;
     i-=20000;
    }while (i>id);
    id=i;
    cout << "what u want to do change in student data like birth day enter 1 \n";
    cout << "change in regist data like subjects enter 2 \n";
    int operate;
    do {
    cout << "what u want to do change in student data like birth day enter 1 \n";
    cout << "change in regist data like subjects enter 2 \n";
    cout << "to pay the credit enter 3 \n";
    cin >> operate;
    if ( operate == 1){
    cout << "and now enter every thing to the student with the new data\n";
    cout << "please enter student name\n";
    cin.ignore();
    getline( cin , student[id].name);
    cout << "pleae enter his birth date\n";
    cout << "year : ";
    cin >> student[id].birth.year;
    cout << "month : ";
    cin >> student[id].birth.month;
    cout << "day : ";
    cin >> student[id].birth.day;
    }
    else if (operate == 2){
        reg[id].hours=0;
    cout << "if there is no subject enter nosub \n";
    for (int s=0;s<6;s++){
        cout << "subject " << s+1 << ": ";
        cin >> reg[id].sub[s];
        if (reg[id].sub[s]=="nosub")
     continue;
       reg[id].hours+=3;
    };
    reg[id].credit=(reg[id].hours*1000);
    cout << "please enter studying year : ";
    cin >> reg[id].year;
    cout << "\nenter semester : ";
    cin >> reg[id].semester;
    }
    else if (operate == 3 ){
        cout << "the credit = "<< reg[id].credit;
    cout <<"\nenter (pay) to pay the credit else to pay it later : ";
    string pay ;
    cin >> pay ;
    if (pay == "pay")
        reg[id].credit=0;
    cout << "the credit = "<< reg[id].credit<< endl;
    };
    }while (operate <1 || operate >3 );
    break;
 }
 else if (func1=="attendance"){
    cout <<"please enter id of the student\n";
    int x;
    cin >> x;
    id=x-20000;
    cout <<"please enter the number of days he come this week\n";
    int app;
    cin >> app;
    student[id].attendance+=app;
    break;
 };
 }
    else if (x>20000&&x<21000)  {
        id = x-20000;
        cout << "the studint name : "<< student[id].name;
        cout << "\nthe birth date : " << student[id].birth.year <<"\\";
        cout << student[id].birth.month<<"\\"<<student[id].birth.day;
        cout << "\nthe studying year :"<< reg[id].year;
        cout << "\nthe semester :"<< reg[id].semester;
        cout << "\nregisted subjects";
     for (int s=0;s<6;s++){
         cout << "\nsubject "<<s+1<<": ";
         cout <<reg[id].sub[s];
        };
    cout << "\nthe registed hours :"<< reg[id].hours;
    cout << "\nthe credit :"<<reg[id].credit<<endl;
    break;
    };};
    /*
    here we rewrite the hole data after we change what we want to change
    the program works by copying data ,change it or write new data
    and write them again in the same file
    */
    id=1;
    student_data.close();
    student_data.open("student data.csv",ios::trunc);
    student_data.close();
    student_data.open("student data.csv");
    while (id<m){
  student_data<<student[id].name;
  student_data<<";";
  student_data<<student[id].id;
  student_data<<";";
  student_data<<student[id].birth.day;
  student_data<<";";
  student_data<<student[id].birth.month;
  student_data<<";";
  student_data<<student[id].birth.year;
  student_data<<";";
  student_data<<student[id].attendance;
  id++;
  if (id != m)
  student_data<<"\n";
  };
  id=1;
    regist.close();
    regist.open("registration.csv",ios::trunc);
    regist.close();
    regist.open("registration.csv");
  while (id<m){
  for (int s=0;s<6;s++){
  regist<<reg[id].sub[s];
  regist<<";";
  };
  regist<<reg[id].id;
  regist<<";";
  regist<<reg[id].year;
  regist<<";";
  regist<<reg[id].semester;
  regist<<";";
  regist<<reg[id].hours;
  regist<<";";
  regist <<reg[id].credit;
  id++;
  if (id<m)
  regist<<"\n";
  };
  student_data.close();
  regist.close();
  if (x==-1 )
            break;
};
    return 0;
}
