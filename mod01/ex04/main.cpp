#include <iostream>
#include <fstream>
#include <string>

int main(int argn, char *argv[])
{
	if (argn != 4)
	{
		std::cout << "Error. 3 args expected: filename string1 string2" << std::endl;
		return (1);
	}
	
	// in ----
	std::string filename = argv[1];
	std::ifstream fin(filename.c_str(), std::ios::in); // fstream
	if (!fin)
	{
		std::cout << "Error. " << filename << " not found or allowed" << std::endl;
		return (2);	
	}

	// out ---
	std::string newFilename = filename.append(".replace");
	std::ofstream fout;
	fout.open(newFilename.c_str(), std::ios::out | std::ios::trunc); // fstream
	if (!fout)
	{
		std::cout << newFilename << " could not be created" << std::endl;
		return (3);	
	}	

	// reading and replacing
	std::string str1 = argv[2];
	char *&str2 = argv[3];
	std::string line;
	size_t pos;
    while (std::getline(fin, line)) {
		while ((pos = line.find(str1)) != std::string::npos)
			line = line.substr(0, pos).append(str2).append(line.substr(pos+str1.length()));
        fout << line << std::endl;
    }
	std::cout << "Done. " << newFilename << " created" << std::endl;
	fin.close();
	fout.close();
	return 0;
}