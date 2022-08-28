#include <iostream>
#include <cmath>
#include <string.h>


int main(int argc, char* argv[])
{

    int cosine_print = -1;

    // We first check whether the user is passing 3 arguments (without including the name of the program itself)
    if (argc < 3) {
        std::cout<< "You must type at least 2 arguments.\n";
        exit(-1);
    }

    // If 3 arguments were passed, we must check that first two arguments are numbers
    for (int i = 1; i < 3; i++) {
        if ( ! isdigit(*argv[i]) ) {
            std::cout<< "Arguments must be numbers.\n";
            exit(-1);
        }
    }

    if( argc == 4) {
        cosine_print = strcmp(argv[3], "c");
    }

    int num_of_sample = std::stoi(argv[1]);
    int num_bits      = std::stoi(argv[2]);

    int range = pow(2, (num_bits-1)) - 1;

    for (int i=0; i<num_of_sample; i++)
    {
        double val =  (2 * i * M_PI) / num_of_sample;

        if (!cosine_print){
            std::cout<<  "  " << round( sin(val)*range ) << " " << (round( cos(val)*range )) + 0.0 << "\n";
        }
        else{
            std::cout<<  "  " << round( sin(val)*range ) << " " << "\n";
        }
        
    }
    
    return 0;    
}