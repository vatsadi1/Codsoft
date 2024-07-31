#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> 
using namespace std;
int main(){
    srand((unsigned int) time(NULL));
    int number = (rand()%100)+1;
    int guess = 0;
    do{
        cout<<"Guess the number between 1 and 100"<<endl;
    cin>>guess;
    
if(guess>number)
 cout<<"Too high ! guess lower"<<endl;
else if(guess<number)
cout<<"too loW ! GUESS HIGH "<<endl;
else
cout<<"RIGHT GUESS ! YOU WON"<<endl;
}
while(guess!=number);}