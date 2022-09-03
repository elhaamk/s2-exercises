#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

const char * classmenu = R""""(
#####################################
#      Class Grades Management      #
# --------------------------------- #
#                                   #
# 1. Display All Grades             #
# 2. Show The Best Grade            #
# 3. Calculate Class Average Grade  #
# 4. Get List of Failed Students    #
# 0. Exit                           #
#####################################

Select Command (0-4):
)"""";

struct result {
    std::string name;
    double grade;
};

std::vector<result> class_result;

int display_grades(const std::vector<result> & result_inst){

  for (auto &i : result_inst)
  {
    std::cout << i.grade << '\t' << i.name << '\n';
  }
}

int best_grade(const std::vector<result> & result_inst){

    double temp_max{0.0};
    std::string name;
    
    for (auto &i : result_inst)
    {
        if(i.grade > temp_max){
            temp_max = i.grade;
            name = i.name;
        }
    }    
    std::cout << "The Best Grade is " << temp_max << " from "  << name << "\n" ;
}

int failed_grades(const std::vector<result> & result_inst){

    for(auto &i : result_inst){  

        if(i.grade < 10 ){
            std::cout << i.grade << "  "  << i.name << "\n" ;
        }
    }
}

int average_grade(const std::vector<result> & result_inst){

    double sum {0.0};
    for (auto &i : result_inst)
    {
        sum += i.grade;
    }  
    std::cout << "Class average grade is " << sum/result_inst.size() << "\n" ;
}

std::vector<result> display_cmd(const std::string file_path)
{
    std::string line;
    std::string name; 
    double grade;

    std::ifstream reader( file_path ) ;

    if( ! reader ) {
        std::cout << "Error opening input file" << "\n" ;
        exit(-1);
    }

   for( int i = 0; ! reader.eof() ; i++ ) {
        std::getline( reader , line ) ;
        std::stringstream s(line);
        s.str(line);
        s >> grade; 
        s >> name;

        class_result.push_back({name, grade});
    }

    reader.close() ;
    return class_result;

}

int main(int argc, char* argv[])
{
    std::string path;
    int cmd;

    if(argc>2){
        path = argv[2];
    }
    else{
        path = "grades.txt";
    }

    auto class_result = display_cmd(path);

    std::cout <<  "\n" << classmenu << "\n" ;
    std::cin >> cmd ;

    switch(cmd)
    {

        case 1:
            std::cout << "\n" << "Class Grades: " << "\n" ;
            display_grades(class_result);
        break;

        case 2:
            std::cout << "\n" << "Show The Best Grade: " << "\n" ;
            best_grade(class_result);
        break;

        case 3:
            std::cout << "\n" << "Calculate Class Average Grade: " << "\n" ;
            average_grade(class_result);
        break;

        case 4:
            std::cout << "\n" << "List of Failed Students: " << "\n" ;
            failed_grades(class_result);
        break;

        case 0:
            std::cout << "\n" << "Exit " << "\n" ;
            exit(-1);
        break;

        default:
            std::cout << "Invalid command! " << "\n" ;
            exit(-1);
        break;

    }

    return 0;
}