#include "Converter.hpp"  
#include <iostream> 
int main() 
{       
    std::string input;   
    while (true) 
    {   
        std::cout << "Enter a value (empty to quit): ";
        std::getline(std::cin, input);

        if (input.empty())
            break;

        std::cout << "You entered: " << input << std::endl;

        try 
        {  
            Converter::handle_convert(input);   
        } 
        catch(const std::exception &e)  
        { 
            std::cerr << "Error: " << e.what() << std::endl;   
        }
    }
    return 0;
}