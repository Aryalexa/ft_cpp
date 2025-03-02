#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("ShrubberyCreationForm", 145, 137), _target("no-target")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : 
    AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
    AForm(other), _target(other._target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        // nonsense
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it
void ShrubberyCreationForm::doExecute() const
{
    using std::string;
    const int TIMES = 2;
    const string TREE_FILE = "tree";

    std::string outfile = "";
    outfile.append(_target).append("_shrubbery");
    
    // open ascii-tree file
    std::ifstream fin(TREE_FILE.c_str(), std::ios::in);
    if (!fin)
	{
		string msg = "Error. Tree file '";
        msg.append(TREE_FILE);
        msg.append("' not found or not enough permissions.");
        throw std::runtime_error(msg);
	}
    fin.close();

    // open outfile
	std::ofstream fout(outfile.c_str(), std::ios::out | std::ios::trunc); // fstream
	if (!fout)
	{
		string msg = "Output file could not be created.";
        throw std::runtime_error(msg);
	}	
    for (int i = 0; i < TIMES; ++i)
    {
        fin.open(TREE_FILE.c_str(), std::ios::in);
        if (!fin)
        {
            string msg = "Error reading.";
            fout.close();
            throw std::runtime_error(msg);
        }
        fout << fin.rdbuf(); // entire file content
        fin.close();
    }
    fout.close();
    std::cout << TIMES << " tress in " << outfile << std::endl;
}
    
