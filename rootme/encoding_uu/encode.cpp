#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

string	processLine(string &line)
{
	int	bits;
	unsigned char	remainder;
	string	ret;
	
	bits = 6;
	remainder = line[1] - 32;
	for (int i = 2; i < line.length(); i++)
	{
		remainder <<= 8 - bits;
		remainder |= (unsigned char)((line[i] - 32) << 2) >> bits;
		bits += 6;
		if (bits >= 8)
		{
			ret.push_back(remainder);
			bits -= 8;
			remainder = ((unsigned char)((line[i] - 32) << (8 - bits))) >> (8 - bits); 
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	int	end;
	string	begin, mode, file, line, ret;
	ifstream   input(argv[1]);

	end = 0;
	input >> begin >> mode >> file;
	cout << begin << mode << file << endl;
	while (1)
	{
		getline(input, line);
		if (input.fail())
		{
			cerr << "a file error occured" << endl;
			return 1;
		}
		if (input.eof())
			break ;
		if (line.compare("`"))
			end = 1;
		else if (line.compare("end") && end)
			break ;
		cout << line << endl;
		ret = processLine(line);
		cout << ret << endl;
	}
	return 0;
}