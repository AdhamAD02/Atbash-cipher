#include <iostream>
#include <string>
using namespace std;
void cipher();
void decipher();
//-------------------------------------
int main() {
    int choose;
    cout<<"1-Cipher \n";
    cout<<"2-Decipher \n";
    cout<<"Choose 1 or 2: ";
    cin>>choose;
    cin.ignore();
    if(choose==1){
        cout<<"Cipher \n";
        cipher();
    }
    else if (choose==2){
        cout<<"Decipher \n";
        decipher();
    } else{
        cout<<"Enter valid number \n";
    }
    return 0;
}
//----------------------------------
void cipher(){               //Function to cipher a text
    string message;
    cout<<"Enter a message: ";
    getline(cin,message);
    cin.ignore();
    for (int i=0; i<=message.length(); i++) {
        if(islower(message[i])) {
            message[i] = toupper(message[i]);        //to make characters in upper case
        }
    }
    string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ", reversed="";
    for(int i= alpha.length()-1; i>-1; i--){       //To reverse the alphabet
        reversed+=alpha[i];
    }
    string ciphertext = "";
    for (int i=0;i<=message.length();i++){
        if(message[i]==32){    //32=space in ASCII
            ciphertext+=" ";       //if user input a space, it should be a space in the output
        } else{
            for (int x=0;x<=alpha.length(); x++){
                if(message[i]==alpha[x]){
                    ciphertext+=reversed[x];  //every character turns to the reversed form in the output  A>>Z
                    break;
                }
            }
        }
    }
    cout << "cipher is: " << ciphertext;   //print the ciphered text
}
//-------------------------------------------------
void decipher() {  //Function to decipher a text
    string message;
    cout << "Enter a message: ";
    getline(cin, message);
    cin.ignore();
    for (int i = 0; i <= message.length(); i++) {
        if (islower(message[i])) {
            message[i] = toupper(message[i]);  //to make characters in upper case
        }
    }
    string reversed = "ZYXWVUTSRQPONMLKJIHGFEDCBA", alpha = "";
    for (int i = reversed.length() - 1; i > -1; i--) {
        alpha += reversed[i];  //To reverse the reversed alphabet
    }
    string deciphertext = "";
    for (int i = 0; i <= message.length(); i++) {
        if (message[i] == 32) {  //32=space in ASCII
            deciphertext += " "; //if user input a space, it should be a space in the output
        } else {
            for (int x = 0; x <= reversed.length(); x++) {
                if (message[i] == reversed[x]) {
                    deciphertext += alpha[x]; //every reversed character turns to the original form in the output  Z>>A
                    break;
                }
            }
        }
    }
    cout << "cipher is: " << deciphertext;  //print the deciphered text
}