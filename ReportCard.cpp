#include<conio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class student
{
	int rollno;
	char name[50];
	int p_marks, c_marks, m_marks, e_marks, cs_marks;
	double per;
	char grade;
	void calculate();
public:
	void getdata();
	void showdata() const;
	void show_tabular() const;
	int retrollno() const;
};
void student::calculate()
{
	per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
	if(per>=60)
		grade='A';
	else if(per>=50)
		grade='B';
	else if(per>=33)
		grade='C';
	else
		grade='F';
}

void student::getdata()
{
	cout<<"\nEnter The USN of student ";
	cin>>rollno;
	cout<<"\nEnter The Name of student ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n  Enter The marks in OOPS out of 100 : ";
	cin>>p_marks;
	cout<<"\n  Enter The marks in MICROPROCESSOR out of 100 : ";
	cin>>c_marks;
	cout<<"\n  Enter The marks in MATHEMATICS out of 100 : ";
	cin>>m_marks;
	cout<<"\n  Enter The marks in COMPUTER ORGANISATION out of 100 : ";
	cin>>e_marks;
	cout<<"\n  Enter The marks in SOFTSKILLS out of 100 : ";
	cin>>cs_marks;
	calculate();
}

void student::showdata() const
{
	cout<<"\nUSN of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nMarks in OOPS : "<<p_marks;
	cout<<"\nMarks in MICROPROCESSOR : "<<c_marks;
	cout<<"\nMarks in MATHEMATICS : "<<m_marks;
	cout<<"\nMarks in COMPUTER ORGANISATION : "<<e_marks;
	cout<<"\nMarks in SOFTSKILLS :"<<cs_marks;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"<<grade;
}

void student::show_tabular() const
{
	cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)
		<<e_marks<<setw(4)<<cs_marks<<setw(8)<<per<<setw(6)<<grade<<endl;
}

int  student::retrollno() const
{
	return rollno;
}

void write_student();
void display_all();
void display_sp(int);
void modify_student(int);
void delete_student(int);
void class_result();
void result();
void intro();
void entry_menu();

int main()
{
	char ch,a;
	string uname;
	string pass;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2);
	intro();
	do
	{
		system("cls");

		cout<<"\n\n\n\tLogin as:-"<<endl;
		cout<<"\n\n\t1.Teacher";
		cout<<"\n\n\t2.Student";
		cout<<"\n\n\t3.Exit";
		cout<<"\n\n\tSelect your Category(1-3):";
		cin>>a;
		switch(a)
        {
            case '1':
                cout<<"\n\n\n\tEnter your Username:-";
                cin>>uname;
		cout<<"\n\tEnter the Password:-";
		    cin>>pass;
		    if(uname=="abhi" && pass=="abcd")
            {
                cout<<"\n\n\tYou are successfully logged in....";


                cout<<"\n\n\n\tMAIN MENU";
		    cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		switch(ch)
		{
		case '1':
            result();
        break;
        case '2':
            entry_menu();
            break;
        case '3':break;
        default:cout<<"\a";
        }
            }
            else

             {
                cout<<"\n\n\tIncorrect password";
                getch();
             }
            break;



		    case '2':  cout<<"\n\n\tEnter your Username:-";
                cin>>uname;
		cout<<"\n\tEnter the Password:-";
		    cin>>pass;
		    if(uname=="ranjan" && pass=="abc")
            {
                cout<<"You are successfully logged in...";
		    cout<<"\n\n\t RESULT MENU";
		    result();
            }
            else
            {
                cout<<"\n\n\tIncorrect username and password";
                getch();
            }
            break;

	}
	}
		      while(a!='3');
	return 0;

		}



void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}

void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}


void display_sp(int n)

{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}


void modify_student(int n)
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
    	while(!File.eof() && found==false)
	{

		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    	int pos=(-1)*static_cast<int>(sizeof(st));
		    	File.seekp(pos,ios::cur);
		    	File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    	cout<<"\n\n\t Record Updated";
		    	found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();
}


void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}

void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"==========================================================\n";
	cout<<"USN    NAME        OOPS   MP   MAT   CO   SS   %age   Grade"<<endl;
	cout<<"==========================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}

void result()
{
	char ch;
	int rno;
	system("cls");
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Marks Card";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2/3)? ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1' :	class_result(); break;
	case '2' :	cout<<"\n\n\tEnter USN Of Student : "; cin>>rno;
				display_sp(rno); break;
	case '3' :	break;
	default:	cout<<"\a";
	}
}

void intro()
{
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
	cout<<"\n\t\t\t\t\t;;;;;;;EXAM MARKS PORTAL;;;;;;;;";
	cout<<"\n\t\t\t\t\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
	cin.get();
}



void entry_menu()
{
	char ch;
	int num;
	system("cls");
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The USN "; cin>>num;
			display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease Enter The USN "; cin>>num;
			modify_student(num);break;
	case '5':	cout<<"\n\n\tPlease Enter The USN "; cin>>num;
			delete_student(num);break;
	case '6':	break;
	default:	cout<<"\a"; entry_menu();
	}
}
