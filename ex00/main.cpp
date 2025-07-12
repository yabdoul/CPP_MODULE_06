#include "Converter.hpp"  
#include <iostream> 
int main() 
{     
    try 
    {  
        Converter::handle_convert("97.2f") ;   
    } 
    catch(std::exception &e)  
    { 
         std::cerr<<e.what()<<std::endl ;   
    }
    return 0 ;  
} ;  