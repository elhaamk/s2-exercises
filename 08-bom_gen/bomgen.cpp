#include "rapidcsv.h"
#include <iostream>
#include <fstream>


int main(int argc, char* argv[])
{
    const char* in_f  = argv[1];
    auto out_f = argv[2];
    
    rapidcsv::Document doc(in_f);

    std::vector<std::string> part_column = doc.GetColumn<std::string>("part");
    std::vector<std::string> desig_column = doc.GetColumn<std::string>("designator");
    std::vector< std::tuple <int, std::string> > repeated_parts {};

 //   std::vector<std::string> in_rows = doc.GetRow<std::string>("");

    int temp=0, count=0;
    for(int i=0; i<part_column.size(); i++)
    {
    //    if(count>1) {std::cout << "count: " << count << "\n";}
        count = 1;

        for(int j=i+1; j<part_column.size(); j++)
        {
            if(part_column[i] == part_column[j])
            {
                
                count++;

                std::cout << "Equal: " << i << "\t" << j << "\t" << part_column[i] << "\t" << count << "\n";
                repeated_parts.push_back( std::tuple <int, std::string> (i, part_column[i]) );

            }

        }

    }

    std::cout << "Col " << part_column.size() << " values." << std::endl;

    for(int i=0; i<desig_column.size(); i++)
    {
        std::cout << i << " " << desig_column[i] << std::endl;
    }

    std::ofstream writer( out_f ) ;

    int a; std::string b;
    for( int i = 0; ! writer.eof() ; i++ )
    {
        
    }

    return 0;

}

