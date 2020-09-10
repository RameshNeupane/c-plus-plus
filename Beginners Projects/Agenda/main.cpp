#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> Names;
vector <string> Phones;

void NewContact()
{
   string name{}, phone{};
   char yn{};

   cout <<endl <<  "*** NEW CONTACT ***" << endl;
   do{
      cout << endl << "Enter name for new contact: ";
      cin >> name;
      cout << "Enter phone no. for this contact: ";
      cin >> phone;
      cout << "Contact added. " << endl << "Contact ID is: " << Names.size() << endl;

      Names.push_back(name);
      Phones.push_back(phone);

      cout << endl << "Want to add new contact?[y/n]: ";
      cin >> yn;
   }while(yn != 'N' && yn != 'n');

}

void SearchByID()
{
   int val{};
   char yn{};

   cout << endl << "*** SEARCH BY ID ***" << endl;
   do{
      cout << endl << "Enter ID of the contact: ";
      cin >> val;

      if(val >= Names.size()) {
         cout << endl << "ID does not exist" << endl;
      }
      else{
         cout << endl << "-----Detail for ID " << val << "-----" << endl;
         cout << "Name: " << Names[val] << endl;
         cout << "Phone: " << Phones[val] << endl;
         return;
      }
      cout << endl << "Want to continue searching?[y/n]: ";
      cin >> yn;
   }while(yn != 'N' && yn != 'n');
}

void SearchByName()
{
   string name{};
   char yn{};

   cout << endl << "*** SEARCH BY NAME ***" << endl;
   do{
      cout << endl << "Enter name of the contact: ";
      cin >> name;

      int count{0};
      for(int i = 0; i != Names.size(); i++) {
         if(name == Names[i]) {
            cout << endl << "---Contact Found---" << endl;
            cout << "Name: " << Names[i] << endl;
            cout << "Phone: " << Phones[i] << endl;
            ++count;
         }
      }
      if(count == 0)
         cout << "Sorry, Contact Not Found" << endl;
      else
         cout << "Total contact found: " << count << endl;
      cout << endl << "Want to continue searching?[y/n]: ";
      cin >> yn;
   }while(yn != 'N' && yn != 'n');
}

int main()
{
   int sel{0};
   bool flag{true};

   while(flag) {
      cout << endl << "----------MY AGENDA----------" << endl;
      cout << endl << "*** OPTIONS ***" << endl;
      cout << "[1] New Contact" << endl;
      cout << "[2] Search By ID" << endl;
      cout << "[3] Search By Name" << endl;
      cout << "[4] Exit" << endl;

      cout << endl << "Choose an option: ";
      cin >> sel;

      switch(sel)
      {
      case 1:
         NewContact();
         break;
      case 2:
         SearchByID();
         break;
      case 3:
         SearchByName();
         break;
      case 4:
         flag = false;
         break;
      default:
         cout << endl << "Error: Invalid Option" << endl;
      }
   }
   return 0;
}
