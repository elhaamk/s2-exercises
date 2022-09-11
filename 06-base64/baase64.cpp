#include <iostream>
#include <vector>

const char* base64_chars = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
    };

char table_base6 [64] {};
int gen_base64_table(std::string in_str)
{
    
    int i{};
    for (const char &c :in_str)
    {
        std::cout << c << ' ';
        table_base6 [i++] = c;
    }
    std::cout << '\n';

    for (int j =0; j < 64; j++)
    {
        std::cout << table_base6 [j] << ' ';
    }
    std::cout << '\n';

    return 0;

}

std::vector<char> encoder(std::string input_str, int len_str)
{
    std::vector<char> res_str;
	
	int idx, bits = 0, padding = 0;
    int group = 0, state = 0, val;
	int i, j, k = 0;
	len_str -= 1;

	for (i = 0; i < len_str; i += 3)
		{
			group = 0, state = 0, bits = 0;

			for (j = i; j < len_str && j <= i + 2; j++)
			{
				group = group << 8;				
				group = group | input_str[j];
				state++;			
			}

			bits = state * 8;
			padding = bits % 3;

			while (bits != 0)
			{
				if (bits < 6)
				{
                    idx = (group << val) & 63;
                    val = 6 - bits;
					bits = 0;		
				}
				else
				{
					idx = (group >> val) & 63;
                    val = bits - 6;
					bits -= 6;									
				}

                res_str.push_back(base64_chars[idx]);
			}
	}

	for (i = 1; i <= padding; i++)
	{
        res_str.push_back('=');
	}

	return res_str;

}


int main(int argc, char* argv[])
{
    
   // std::string input_str = argv[1];
    std::string input_str = argv[1];
    std::vector<char> out;
    int len_str;

	len_str = sizeof(input_str) / sizeof(input_str[0]);

    out = encoder(input_str, len_str);

	std::cout << input_str << '\n';

    for (int i=0;i<sizeof(out); i++)
    {
        std::cout << out[i];   
    }
    std::cout << '\n';

	return 0;
    
}