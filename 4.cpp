#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name,date_of_birth;
    Person() {};
    Person(string name,string date_of_birth)
    {
        this->name=name;
        this->date_of_birth=date_of_birth;
    };

    void viewPerson()
    {
        cout<<"Name : "<<this->name<<endl;
        cout<<"Birthday : "<<this->date_of_birth<<endl;
    }

};

class Department
{
public:
    string departmentName;
    Department() {};
    Department(string departmentName)
    {
        this->departmentName = departmentName;
    }
    void viewDepartment()
    {
        cout<<"Department : "<<this->departmentName<<endl;
    }
};

class Student : public Person
{
public:
    string typeOfCoder;
    Department department;
    int totalsolve,id;
    Student() {};
    Student(string name,string date_of_birth,Department department,int id,int totalsolve,string typeOfCoder) : Person(name,date_of_birth)
    {
        this->id=id;
        this->department=department;
        this->totalsolve=totalsolve;
        this->typeOfCoder=typeOfCoder;
    }
    void view_student_info()
    {
        cout<<"Student name: "<<this->name<<endl;
        department.viewDepartment();
        cout<<"Student ID: "<<this->id<<endl;
        cout<<"Students Birthday: "<<this->date_of_birth<<endl;
        cout<<"Students type: "<<this->typeOfCoder<<endl;
        cout<<"Students total solve: "<<this->totalsolve<<endl;

    }
};

class Faculty : public Person
{
public:
    string designation;
    Department department;
    Faculty() {};
    Faculty(string designation,string name,string date_of_birth, Department department):Person(name,date_of_birth)
    {
        this->designation=designation;
        this->department=department;
    }
    view_faculty()
    {
        cout<<"Name: "<<name<<endl;
        department.viewDepartment();
        cout<<"Designation: "<<this->designation<<endl;
    }

};

int main()
{
    Department *departments[5]=
    {
        new Department("CSE"),
        new Department("ICT"),
        new Department("MATHEMATICS"),
        new Department("MANAGEMENT"),
        new Department("PHYSICS")
    };

    Student *students[5]=
    {
        new Student("Ashik Mahmud","21-02-1996",*departments[0],11609021,233,"Regular Contestent"),
        new Student("Faysal Hossain","23-23-1995",*departments[1],11707025,10,"Not Regular"),
        new Student("Kibria Mahmud","31-1-1997",*departments[0],11508011,600,"WORLD FINALIST"),
        new Student("Asif iqbal","13-5-1998",*departments[0],11608003,200,"Regular Contestent"),
        new Student("Rehman saif","17-5-1996",*departments[4],11608016,0,"Not Regular")
    };
    cout<<"INFORMATION OF APPLICANTS: "<<endl<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"INFO OF STUDENT "<< i+1<<": "<<endl;
        students[i]->view_student_info();
        cout<<endl<<endl;
    }
    Faculty *faculty_member[3]=
    {
        new Faculty("Assistant Professor","Kamal Hossain Chowdhury","12-02-1982",*departments[0]),
        new Faculty("Assistant Professor","Mahmudul Hasan","23-02-1983",*departments[0]),
        new Faculty("Lecturer","Khairul Kabir","11-11-1989",*departments[3])
    };
    cout<<endl<<endl;
    cout<<"INFORMATION OF FACULTY: "<<endl<<endl;
    for(int i=0; i<3; i++)
    {
        cout<<"INFO OF FACULTY "<<i+1<<": "<<endl;
        faculty_member[i]->view_faculty();
        cout<<endl;
    }
    cout<<"Problem setters & selected number of problems"<<endl<<endl;
    for(int i=0;i<5;i++)
    {
        if(students[i]->typeOfCoder=="WORLD FINALIST" && students[i]->totalsolve>=400)
        {
            cout<<"No of Problems Selected : 2"<<endl;
            cout<<"Problem setter name : "<<students[i]->name<<endl;
        }
        else if(students[i]->totalsolve<400 && students[i]->totalsolve>=200)
        {
            cout<<"No of Problems Selected : 1"<<endl;
            cout<<"Problem setter name : "<<students[i]->name<<endl;
        }
        cout<<endl;
    }

    return 0;
}
