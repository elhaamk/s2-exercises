#include <iostream>
#include <string>

struct inputs{
 int width {20};
 int height {10};
 char prime {'X'};
 char noprime {'-'};
};

bool prime_detect(int number_in)
{
    int val = number_in/2;
    if(number_in == 0 || number_in == 1)
    {
        return false;
    }
    for ( auto i {0}; i< val+1; i++)
    {
        if(number_in % i == 0)
        {
            return false;
        }
        else{
            return true;
        }       
    }
    
} 

int main(int argc, char* argv[])
{
    inputs user_in {std::atoi(argv[1]), std::atoi(argv[2]),
                    *argv[3], *argv[4] };

    int start_num = 1;

    for(auto i{0}; i<user_in.height; i++)
    {
        for (auto j{0}; j<user_in.width; j++)
        {
            if(prime_detect(start_num))
            {
                std::cout << (user_in.prime) << "\n";
            }
            else
            {
                std::cout << (user_in.noprime) << "\n";
            }
            start_num++;
        }

    }

    return 0;
}