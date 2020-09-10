#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void AddStudent()
{
   string temp{};
   vector <string> Data;

   cout << "*** Add Student ***" << endl;
   cout << endl << "Enter student's first name: ";
   cin >> temp;
   Data.push_back(temp);

   cout << "Enter last name: ";
   cin >> temp;
   Data.push_back(temp);

   cout << "Enter phone no.: ";
   cin >> temp;
   Data.push_back(temp);

   cout << "Enter student's roll number: ";
   cin >> temp;
   Data.push_back(temp);

   string fileName = Data[3] + ".dat";
   ofstream file;
   file.open(fileName.c_str());
   for(auto data: Data) {
      file << data << endl;
   }
   file.close();
}

void AddNote()
{
   vector <string> Subject;
   vector <string> Note;
   string temp{};
   string student{};
   int z = 0;

   cout << endl << "*** Add Note ***" << endl;
   cout << endl << "Enter the student's roll number: ";
   cin >> student;

   while(true) {
      cout << endl << "Enter subject: ";
      cin >> temp;
      Subject.push_back(temp);

      cout << "Enter note: ";
      getline(cin, temp, '$');
      Note.push_back(temp);

      cout << endl << "Do you want to continue? [0] Yes [1] No: ";
      cin >> z;
      if(z != 0)
         break;
   }
   string fileName{student + ".cal"};
   ofstream file;
   file.open(fileName.c_str());
   for(int i = 0; i < Subject.size(); i++) {
      file << "*" + Subject[i] << endl;
      file << Note[i] << endl;
   }
   file.close();
}

void SearchStudent()
{
   string student{};
   cout << endl << "*** Search Student ***";
   cout << endl << "Enter student's roll number: ";
   cin >> student;

   string fileName;
   fileName = student + ".dat";
   ifstream file;
   file.open(fileName.c_str());

   vector <string> data;
   if(file.is_open()) {
      string in{};
      while(!file.eof()) {
         file >> in;
         data.push_back(in);
      }
      cout << "First Name: " << data[0] << endl;
      cout << "Last Name: " << data[1] << endl;
      cout << "Phone number: " << data[2] << endl;
      cout << "Student's roll number: " << data[3] << endl;
      file.close();
   }
   else
      cout << "student not found" << endl;

}

void ReadKardex()
{
   cout << endl << "*** Read kardex ***" << endl;
   string number{};
   cout << endl << "Insert student's roll number: ";
   cin >> number;

   string fileName;
   fileName = number + ".cal";
   ifstream file;
   file.open(fileName.c_str());
   vector <string> data;

   if(file.is_open()) {
      string in;
      while(!file.eof()) {
         file >> in;
         data.push_back(in);
      }
      file.close();
      for(int i = 0; i < data.size(); i++) {
         cout << data[i] << endl;
      }
   }
}

void PrintKardex()
{
   cout << endl << "*** Print Kardex ***" << endl;

   string number{};
   cout << endl << "Insert student's roll number: ";
   cin >> number;

   vector <string> data;
   vector <string> notes;

   string fileName1, fileName2;
   fileName1 = number +  ".dat";
   fileName2 = number + ".cal";

   ifstream dataFile, noteFile;
   dataFile.open(fileName1.c_str());
   noteFile.open(fileName2.c_str());
   string temp;

   if(dataFile.is_open()) {
      while(!dataFile.eof()) {
         dataFile >> temp;
         data.push_back(temp);
      }
      dataFile.close();
   }
   else {
      cout << endl << "Student not found." << endl;
      return ;
   }

   if(noteFile.is_open()) {
      while(!noteFile.eof()) {
         noteFile >> temp;
         notes.push_back(temp);
      }
      noteFile.close();
   }
   else {
      cout << endl << "Kardex not found." << endl;
      return ;
   }

   string fileName3;
   fileName3 = "Kardex" + number + ".txt";
   ofstream kardex;
   kardex.open(fileName3.c_str());
   kardex << "*** STUDENT KARDEX ***" << endl;
   kardex << "NAME: " << data[0] << " " << data[1] << endl;
   kardex << "PHONE: " << data[2] << endl;
   kardex << "ROLL NUMBER: " << data[3] << endl;
   kardex << endl << "NOTES" << endl;
   kardex << "--------------------" << endl;

   for(int i = 0; i < notes.size(); i++) {
      kardex << notes[i] << endl;
   }
   kardex.close();
}


int main()
{
   int sel{0};
   bool flag = true;

   cout << endl << "----------SCHOOL NOTE SYSTEM----------" << endl;
   while(flag) {
      cout << endl << "*** School Controls ***" << endl;
      cout << "[1] Add Student" << endl;
      cout << "[2] Add Notes" << endl;
      cout << "[3] Search Student" << endl;
      cout << "[4] Read Kardex" << endl;
      cout << "[5] Print Kardex" << endl;
      cout << "[6] Exit" << endl;

      cout << endl << "Choose an option: ";
      cin >> sel;

      switch(sel)
      {
      case 1:
         AddStudent();
         break;
      case 2:
         AddNote();
         break;
      case 3:
         SearchStudent();
         break;
      case 4:
         ReadKardex();
         break;
      case 5:
         PrintKardex();
         break;
      case 6:
         flag = false;
         break;
      default:
         cout << endl << "Error: Invalid Option" << endl;
      }
   }
   return 0;
}
