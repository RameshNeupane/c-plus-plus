#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

vector <string> products;
vector <double> prices;


void LoadValues()
{
   string temp{};
   double tval{0.0};

   ifstream productInfo;
   productInfo.open("products.dat");

   if(productInfo.is_open()) {
      while(!productInfo.eof()) {
         productInfo >> temp;
         products.push_back(temp);

         productInfo >> temp;
         tval = atof(temp.c_str());
         prices.push_back(tval);
      }
   }
   else {
      cout << endl << "Loading file error." << endl;
   }
}

void NewClient()
{
   cout << endl << "*** New Client/Sale ***" << endl;
   int id{0};
   int qty{0};
   int itemqty{0};
   double sum{0.0};

   cout << endl << "Instruction:" << endl;
   cout << "Enter the id of the product. After this, enter the quantity and press enter" << endl;
   cout << "If you have finished, enter -1 on product id to exit the operation." << endl;

   while(true) {
      cout << endl << "Enter product id: ";
      cin >> id;
      if(id == -1)
         break;
      cout << "Enter quantity: ";
      cin >> qty;

      double value = prices[id] * qty;
      sum += value;
      ++itemqty;
      cout << endl;
   }
   double tax = sum * 0.0825;
   double total = sum + tax;

   cout << endl << "You have bought " << itemqty << " items." << endl;
   cout << "Subtotal: " << sum << endl;
   cout << "Tax: " << tax << endl;
   cout << "Total: " << total << endl;

   double money{0.0};
   while(true) {
      cout << endl << "Money: " ;
      cin >> money;
      if(money >= total) {
         cout << "Your change is: " << money - total << endl;
         cout << endl << "Thanks for shopping!!!" << endl;
         break;
      }
      else {
         cout << "Not enough money, re-enter money." << endl;
      }
   }
   ofstream sale;
   sale.open("sales.dat", ios::app);
   if(sale.is_open()) {
      sale << itemqty << "\t" << total << endl;
      sale.close();
   }
   else{
      cout << endl << "Sales file not found, no data saved." << endl;
   }
}

void ViewCatalog()
{
   cout << endl << "*** Product Catalog ***" << endl << endl;
   cout << setw(5) << "ID";
   cout << setw(15) << "PRODUCT";
   cout << setw(10) << "PRICE" << endl;
   cout << "------------------------------" << endl;
   for(int i = 0; i != products.size(); i++) {
      cout << setw(5) << i ;
      cout << setw(15) << products[i];
      cout << setw(10) << prices[i];
      cout << endl;
   }
   cout << endl;
}

void ViewSales()
{
   cout << endl << "*** Supermarket Sales ***" << endl;
   cout << endl << "Stats" << endl;

   string temp;
   int salesCount{0};
   int itemCount{0};
   double sumCount{0.0};
   double tval{0.0};

   ifstream salesFile;
   salesFile.open("sales.dat");
   if(salesFile.is_open()) {
      while(!salesFile.eof()) {
         salesFile >> temp;
         ++salesCount;
         tval = atof(temp.c_str());
         itemCount += tval;

         salesFile >> temp;
         tval = atof(temp.c_str());
         sumCount += tval;
      }
      salesFile.close();
   }
   else {
      cout << endl << "Sales File not found !!! Data can not be generated." << endl;
      return;
   }
   cout << "Total of sales: " << salesCount << endl;
   cout << "Total of items sold: " << itemCount << endl;
   cout << "Total earnings: " << sumCount << endl << endl;
}

int main()
{
   LoadValues();
   int sel = 0;
   bool flag = true;

   while(flag) {
      cout << endl << "----------SUPERMARKET SYSTEM----------" << endl;
      cout << endl << "[1] New Client" << endl;
      cout << "[2] View Catalog" << endl;
      cout << "[3] View Sales" << endl;
      cout << "[4] Exit" << endl;

      cout << endl << "Select an option: ";
      cin >> sel;

      switch(sel)
      {
      case 1:
         NewClient();
         break;
      case 2:
         ViewCatalog();
         break;
      case 3:
         ViewSales();
         break;
      case 4:
         flag = false;
         break;
      default:
         cout << endl << "Error: Invalid Option." << endl;
      }
   }
   return 0;
}
