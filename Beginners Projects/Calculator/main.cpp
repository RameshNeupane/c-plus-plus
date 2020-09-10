#include <iostream>
#include <cmath>

using namespace std;

void arithmetic();
void trigonometric();
void exponential();
void logarithmic();

int main()
{
   int sel{0};
   char yn{};

   do{
      cout <<endl <<  "------ADVANCED CALCULATOR------" << endl;
      cout << endl << "ENTER TYPE OF OPERATION YOU WANT TO CALCULATE" << endl;
      cout << "[1] Arithmetic" << endl;
      cout << "[2] Trigonometric" << endl;
      cout << "[3] Exponentials" << endl;
      cout << "[4] Logarithmic" << endl;
      cout << endl << "Enter your choice: ";
      cin >> sel;

      switch(sel)
      {
      case 1:
         arithmetic();
         break;
      case 2:
         trigonometric();
         break;
      case 3:
         exponential();
         break;
      case 4:
         logarithmic();
         break;
      default:
         cout << "Error: Invalid Operation Type" << endl;
      }

      cout << endl << "Exit Calculator?[y/n]: ";
      cin >> yn;
      cout << endl;
   }while(yn != 'Y' && yn != 'y');
   return 0;
}

void arithmetic()
{
   int op{0};
   double a{0.0}, b{0.0};

   char yn{};
   do{
      cout << endl << "***** ARITHMETIC *****" << endl;
      cout << "-----Select operation-----" << endl;
      cout << "[1] Addition" << endl;
      cout << "[2] Subtraction" << endl;
      cout << "[3] Multiplication" << endl;
      cout << "[4] Division" << endl;
      cout << endl << "Your choice: ";
      cin >> op;

      cout << "Enter first number: ";
      cin >> a;

      cout << "Enter second number: ";
      cin >> b;

      cout << "Result: ";
      switch(op)
      {
      case 1:
         cout << (a + b) << endl;
         break;
      case 2:
         cout << (a - b) << endl;
         break;
      case 3:
         cout << (a * b) << endl;
         break;
      case 4:
         cout << (a / b) << endl;
         break;
      default:
         cout << endl << "Error: wrong choice" << endl;
      }

      cout << endl << "Continue Arithmetic?[y/n]: ";
      cin >> yn;

   }while(yn != 'N' && yn != 'n');
}

void trigonometric()
{
   int op{0};
   double val{0.0};
   char yn{};

   do{
      cout << endl << "***** TRIGONOMETRIC *****" << endl;
      cout << "-----Select Operation-----" << endl;
      cout << "[1] Sine" << endl;
      cout << "[2] Cosine" << endl;
      cout << "[3] Tangent" << endl;
      cout << endl << "Your choice: ";
      cin >> op;

      cout << "Enter value: ";
      cin >> val;

      cout << "Result: ";
      if(op == 1) {
         cout << sin(val) << endl;
      }
      else if(op == 2) {
         cout << cos(val) << endl;
      }
      else if(op == 3) {
         cout << tan(val) << endl;
      }
      else{
         cout << endl << "Error: wrong choice" << endl;
      }

      cout << endl << "Continue Trigonometric?[y/n]: ";
      cin >> yn;
   }while(yn != 'N' && yn != 'n');
}

void exponential()
{
   double base{0.0}, eee{0.0};
   char yn{};

   do{
      cout << endl << "***** EXPONENTIAL *****" << endl;
      cout << "Enter the base(a): ";
      cin >> base;
      cout << "Enter the exponent(n): ";
      cin >> eee;
      cout << "Result(a^n): " << pow(base, eee) << endl;

      cout << endl << "Continue Exponential?[y/n]: ";
      cin >> yn;
   }while(yn != 'N' && yn != 'n');
}

void logarithmic()
{
   double val{0.0};
   char yn{};

   do{
      cout << endl << "***** LOGARITHMIC *****" << endl;
      cout << "Enter the value to calculate log(e): ";
      cin >> val;
      cout << "Result: " << log(val) << endl;

      cout << endl << "Continue Logarithmic?[y/n]: ";
      cin >> yn;
   }while(yn != 'N' && yn != 'n');
}
