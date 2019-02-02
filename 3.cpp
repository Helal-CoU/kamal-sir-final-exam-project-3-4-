#include<iostream>
using namespace std;
class Person
{
    string name,birthday;
public:
    int id, age;

public:
    Person(){};
    Person(string name,string birthday, int age)
    {
        this->name=name;
        this->birthday=birthday;
        this->age=age;
    }
    void viewPerson()
    {
        cout<<"Name : "<<this->name<<endl;
        cout<<"Birthday : "<<this->birthday<<endl;
        cout<<"Age : "<<this->age<<endl;
    }
};

class Department
{
    string department_name;
public:
    Department(){};
    Department(string department_name)
    {
        this->department_name=department_name;
    }
    void view_Department()
    {
        cout<<"Department : "<<this->department_name<<endl;
    }

};

class Student : public Person
{
    int id1;
    Department department;
public:
    Student(){};
    Student(string name,string birthday,int id1,Department dpt) : Person(name,birthday,id1)
    {
        this->id1=id1;
        department=dpt;
    }
    void viewStudent()
    {
        viewPerson();
        department.view_Department();
        cout<<"id1 : "<<this->id1<<endl;
    }
};

class Teacher : public Person
{
    int teacher_id;
    Department department;
public:
    Teacher(){};
    Teacher(string name,string birthday,int teacher_id,Department dpt) : Person(name,birthday,id)
    {
        this->teacher_id=teacher_id;
         department=dpt;
    }

};

class Society_member : public Student
{
    string designation;
public:
    Society_member(){};
    Society_member(string name,string birthday,int id1,Department department,string deisgnation): Student(name,birthday,id1,department)
    {
        this->designation=designation;
    }
    void view_memberInfo()
    {
        cout<<"Society Member Info: "<<endl;
        viewStudent();
        cout<<"Designation : "<<this->designation<<endl;
    }
};

int main()
{
    Department department("CSE");

    Teacher *teachers[5]=
    {
        new Teacher("Partha Chakraborty","14-12-1985",1,department),
        new Teacher("Hasan Hafizur Rahman","12-11-1988",2,department),
        new Teacher("Faisal Bin Abdul Aziz","11-10-1981",3,department),
        new Teacher("Kamal Hossain Chowdhury","20-02-1975",4,department),
        new Teacher("Khairun Nahar","11-11-1993",5,department)
    };

    Student *students[5]=
    {
        new Student("Asikhur Rahman","11-11-1996",11708001,department),
        new Student("Helal Ahmed","12-12-1995",11708002,department),
        new Student("Saiful Islam","11-11-1996",11708003,department),
        new Student("Rakibul Islam","12-10-1995",11708004,department),
        new Student("Sinthiya Khan","01-08-1997",11708005,department)


    };

    Society_member *members[3]=
    {
        new Society_member("Kaysar Ahmed","12-12-1994",11608020,department,"Member"),
        new Society_member("Dipto B. Das","07-10-1993",11708030,department,"VP")
    };
    int teacherScores[3][2]={(2,3),(3,3),(2,4)};
    int studentMarks[3][2]={(2,2),(3,2),(3,3)};
    int finalScore[2];
    for(int i=0;i<2;i++)
    {
        int sum=0;
        for(int j=0;j<3;j++)
        {
           sum+=teacherScores[j][i]+studentMarks[j][i];
        }
        finalScore[i]=sum;
    }
    cout<<"DISPLAY BOARD"<<endl;
    for(int i=0;i<2;i++)
    {
        members[i]->viewStudent();
    }
}
