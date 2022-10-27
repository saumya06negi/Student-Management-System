                             
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void getdata(int i);
void addstudent();
void search_student(int search_id);
void editstudent(int id_no);
void delete_student(int searchkey);
void showdata(int search_id);
int total_students;

struct student
{
  int roll_no;
  string name;
  string father_name;
  string ph_no;
  string dob;
  string address;
};

student record[50];
int main()
{
  int ch;
  int id_no;
  int search_id;

  cout << endl;
  cout << endl;
  while (true)
  {
    cout << endl;
    cout << "Options:" << endl;
    cout << endl;
    cout << "1-Add student" << endl;
    cout << "2-Edit student" << endl;
    cout << "3-Search student" << endl;
    cout << "4-Show Data" << endl;
    cout << "5-Delete student" << endl;
    cout << "6-Exit Program" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cout << endl;

    cin >> ch;
    switch (ch)
    {
    case 1:
      addstudent();
      break;
    case 2:
      if (record[0].roll_no == 0)
      {
        cout << "Add a student " << endl;

        main();
      }
      else
      {
        cout << endl;
        cout << "--------Student record Table--------" << endl;

        for (int i = 0; i <= total_students; i++)
        {
          showdata(i);
        }

        cout << "Edit using ID number: ";

        cin >> id_no;
        id_no -= 1;
        if (id_no > total_students || id_no < 0)
        {
          cout << "\n ID Number does not exist" << endl;
        }
        else
        {
          editstudent(id_no);
        }
      }
      break;

    case 3:
      if (record[0].roll_no == 0)
      {
        cout << " Add a student " << endl;

        main();
      }
      else
      {
        cout << endl;
        cout << "Enter roll_no of student you want to search: ";
        cin >> search_id;
        search_student(search_id);
      }
      break;
    case 4:
      cout << "--------Student Record---------" << endl;

      for (int i = 0; i < total_students; i++)
      {
        if (record[i].roll_no == -1)
        {
          continue;
        }
        showdata(i);
      }
      cout << "--------------END---------------" << endl;

      main();
      break;
    case 5:
      if (record[0].roll_no == 0)
      {
        cout << " Add a student " << endl;

        main();
      }
      else
      {
        cout << endl;
        cout << "Enter roll_no of student you want to delete: ";
        cin >> search_id;
        delete_student(search_id);
      }
      break;

    case 6:
      exit(0);
      break;
    default:
      cout << "Invalid number" << endl;

      main();
    }
    total_students--;
  }
  return 0;
}

void getdata(int i)
{
  cout << "Enter student roll number: ";
  cin >> record[i].roll_no;
  cout << "Enter student name: ";
  cin >> record[i].name;
  cout << "Enter phone number: ";
  cin >> record[i].ph_no;
  cout << "Enter dob: ";
  cin >> record[i].dob;
  cout << "Enter father's name: ";
  cin >> record[i].father_name;
  cout << "Enter address: ";
  cin >> record[i].address;
}

void showdata(int search_id)
{
  int i = search_id;
  if (i == -1)
  {
    return;
  }

  cout << "*Student " << i + 1 << " Data*" << endl;
  cout << endl;
  cout << "Roll: " << record[i].roll_no << endl;
  cout << "Student Name: " << record[i].name << endl;
  cout << "Date of Birth: " << record[i].dob << endl;
  cout << "Phone Number: " << record[i].ph_no << endl;
  cout << "Father's Name: " << record[i].father_name << endl;
  cout << "Address: " << record[i].address << endl;
  cout << "------------------------------" << endl;
  cout << endl;
}

void search_student(int searchkey)
{
  for (int i = 0; i < total_students; i++)
  {
    if (record[i].roll_no == searchkey)
    {
      showdata(i);
    }
  }
  main();
}

void addstudent()
{
  int total;
  cout << "Enter total number of students to be added:";
  cin >> total;
  total_students+=total;

  for (int i = 0; i < total_students; i++)
  {
    getdata(i);
  }

  cout << endl;
  cout << "--------Student Record---------" << endl;

  for (int i = 0; i < total_students; i++)
  {
    showdata(i);
  }
  cout << "--------------END---------------" << endl;

  main();
}

void delete_student(int searchkey)
{
  if(total_students==0){
    cout << "\n\nNo record found!" << endl;
    return;
  }
  for (int i = 0; i < total_students; i++)
  {
    if (record[i].roll_no == searchkey)
    {
      record[i].roll_no = -1;
      cout << "\n\nRecord sucessfully deleted" << endl;
      cout << endl;
      break;
    }
  }
  total_students--;
  main();
}

void editstudent(int id_no)
{
  for (int i = 0; i < total_students; i++)
  {
    if (id_no == i)
    {
      cout << "\n** Previous record **:\n\n";
      showdata(i);
      cout << "\nEnter new data: \n\n";
      getdata(i);
      cout << "\n\nRecord sucessfully updated" << endl;

      main();
    }
  }
}
