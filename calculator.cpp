#include<iostream>
using namespace std;

int main(){

   char choice;
   float num1 , num2;

   cout<<"Enter the 1st number : ";
   cin>>num1;
   cout<<"\n";

   
   cout<<"Enter the 2nd number : ";
   cin>>num2;
   cout<<"\n";

   cout<<"Enter Operation to perform - 'A' for addition , 'S' for subtraction , 'M' for multiplication , 'D' for division : ";
   cin>>choice;

   
   if(choice=='A'|| choice=='S' || choice=='M'|| choice=='D'){
      cout<<"You selected "<<choice<<"\n";
   }
   else{
     cout<<"INVALID CHOICE !!!"<<"\n\n";
  }

   switch(choice){
      case'A': cout<<"The sum of "<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
	       break;

      case'S': cout<<"The subtraction of "<<num1<<" - "<<num2<<" = "<<num1-num2<<endl;
	       break;

      case'M': cout<<"The multiplication of "<<num1<<" * "<<num2<<" = "<<num1*num2<<endl;
	       break;

      case'D':  if(num2!=0){
		          cout<<"The division of "<<num1<<" / "<<num2<<" = "<<num1/num2<<endl;
		           break;
	            }
                else{
		          cout<<"Can't divide by zero \n";
		          break;
	            }

     default:  cout<<" PLEASE ENTER PROPER OPERATION CHOICE \n";
	     break;
   }
  return 0;
}