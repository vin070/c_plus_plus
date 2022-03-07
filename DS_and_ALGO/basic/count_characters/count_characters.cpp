#include<ios>
#include<limits>
#include<string>
#include<iostream>

int main(){

//METHOD 1
//   int characters = 0, digits = 0, spaces = 0;
//   char mix_characters = NULL;

//   while(mix_characters != '$')
//   {
//       mix_characters = std::cin.get();
//       if(mix_characters >= 'a' && mix_characters <= 'z')
//             ++characters;
//       else if(mix_characters >='0' && mix_characters <= '9')
//             ++digits;
//       else if (mix_characters ==' '|| mix_characters == '\n'||mix_characters == '\t')
//              ++spaces;
//   }

//   std::cout<<characters<<" "<<digits<<" "<<spaces;

   //METHOD 2
   int characters = 0, digits = 0, spaces = 0;
   std::string mix_characters;
   std::getline(std::cin, mix_characters, '$');
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'$');

   for(int i = 0; i < mix_characters.length(); i++){
       if(mix_characters[i] >= 'a' && mix_characters[i] <= 'z')
           ++characters;
       else if(mix_characters[i] >= '0' && mix_characters[i] <= '9')
           ++digits;
      else if(mix_characters[i] == ' ' || mix_characters[i] == '\n' || mix_characters[i] == '\t')
          ++spaces;
   }
   
   std::cout<<characters<<" "<<digits<<" "<<spaces;

}
