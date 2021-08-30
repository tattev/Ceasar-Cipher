/// ceasar cipher
#include <iostream>
#include <string>
#include <fstream>

void encrypt_func(){

 char text[200];
 char ch;
 int i, key;
 std::cout << "Enter the text to encrypt: \n";
 std::cin >> text;
 std::cout << "Enter the key: \n";
 std::cin >> key;
  for(i = 0; text[i] != '\0'; ++i){
    ch = text[i];
     if(ch >= 'a' && ch <= 'z'){   //   lower case
      ch = ch + key;

      if(ch > 'z'){
          ch = ch - 'z' + 'a' - 1;
      }
          text[i] = ch;
     }
    else if(ch >= 'A' && ch <= 'Z'){    // upper case
        ch = ch + key;
      if(ch > 'Z'){
        ch = ch - 'Z' + 'A' -1;
       }
        text[i] = ch;
     }
  }
    std::cout << "Encrypted text is: " << text << std::endl;
}
void decrypt_func(){

 char text[200];
 int i, key;
 char ch;
 std::cout << "Enter the text to decrypt: \n";
 std::cin >> text;
 std::cout << "Enter the key: \n";
 std::cin >> key;
  for(i = 0; text[i] != '\0'; ++i){
    ch = text[i];
     if(ch >= 'a' && ch <= 'z'){   //   lower case
      ch = ch - key;

      if(ch < 'a'){
          ch = ch + 'z' - 'a' + 1;
      }
          text[i] = ch;
     }
    else if(ch >= 'A' && ch <= 'Z'){    // upper case
        ch = ch - key;
      if(ch < 'A'){
        ch = ch + 'Z' - 'A' +1;
      }
        text[i] = ch;
       }
  }
 std::cout << "Decrypted text is: " << text << std::endl;
}
int main()
{
    std::string plaintext, line;
   
    std::string filename = "myText.txt";                     //file name
    std::ifstream in(filename.c_str(), std::ios::in);        //open file  
    if (!in.is_open())                                       // checking if open
    {
        std::cout << "ERROR: opening filename- " << filename << std::endl;
        return 0;
    }
        while (!in.eof())
        {
            getline (in, line, '\n');    
        
if (in)
{
    plaintext = plaintext + line + "\n";                     // for preserve line char.
}
    }
    
    in.close ();                                              //closing the file

int choice;
std::cout << "You can encrypt the text by Ceasar Cipher or decrypt it․\n\n"; 
std::cout << "Let's try it and choose\n\n1- for encrypt the text" << std::endl << "2- for decrypt the text\n\n";
std::cin >> choice;
switch(choice)          //  menu for user
  {
    case 1: encrypt_func();
            break;
    case 2: decrypt_func();
            break;
    default: std::cout << "Enter a valid option!!\n";
            break;
  }

return 0;
}
