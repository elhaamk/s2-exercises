#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> topchart(std::vector<int> input_data, std::vector<int> falsevar);
std::vector<int> falsevar;


void draw(std::vector<int> chart)
{
    char c;

    for (int j = *std::max_element(chart.begin(), chart.end()); j >= 0; j--)
    {
        auto max = topchart(chart, falsevar);
        if (chart[max[0]] == j)
        {
            falsevar.push_back(chart[max[0]]);
        }

        for (int i = 0; i < chart.size(); i++)
        {
            c =  (std::find(falsevar.begin(), falsevar.end(), chart[i]) != falsevar.end() ) ? '*' : ' ';
            std::cout << c;
        }
        std::cout << "\n";
    }
}

std::vector<int> topchart(std::vector<int> input_data, std::vector<int> falsevar)
{
    std::vector<int> maxidx;
    std::vector<int> max_indexes;

    auto m = [falsevar](int lower, int higher)
    {
        if (std::find(falsevar.begin(), falsevar.end(), higher) != falsevar.end())
        {
            return false;
        }
        if (std::find(falsevar.begin(), falsevar.end(), lower) != falsevar.end())
        {
            return true;
        }
        return (lower < higher);
    };


    auto max = std::max_element(input_data.begin(), input_data.end(), m);
    for (int i = 0; i < input_data.size(); i++)
    {
        if (input_data[i] == *max)
        {
            maxidx.push_back(i);
        }
    }
    return maxidx;
}


std::vector<int> input_bar(int argc, char *argv[])
{
    std::vector<int> chart;
    for(int i = 1 ; i < argc; i++)
    {
        chart.push_back(std::atoi(argv[i]));
    }

    draw(chart);
}

int main(int argc, char *argv[])
{
    input_bar(argc,argv);
    
    return 0;
}