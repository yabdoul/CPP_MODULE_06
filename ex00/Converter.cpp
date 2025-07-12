#include  "Converter.hpp"   
#include <iostream> 
#include <iomanip>  
#include <limits>
 

Converter::Converter(Converter &C )
{ 
  (void)  C ;     
}   
Converter Converter::operator=(Converter &C)  
{ 
     (void)  C ;  
} ;     

bool  Converter::fullDegit(std::string  _value ) 
{ 
     for(int i =  0 ;  i  < _value.size( )  ;  i++  )  
        { 
              if(!isdigit(_value[i])  && !(_value[i] == '-'  || _value[i] == '+')) 
                return false ;  
        }  
    return true  ;   
}
int  Converter::typeGet(std::string _value  ) 
{   
   if(_value == "nan" or _value == "nanf")  
    return NAN ;   
   if(_value.length()  == 1  &&  !isdigit(_value[0]) )  
        {  
            return CHAR  ;    
        } ;   
   if(Converter::fullDegit(_value)) 
        return INT ;     
    if(_value.find('.') != std::string::npos )
    {   
        if( (_value.back() == 'f') ||  ( _value  ==  "-inff")  || (_value  ==  "+inff") ) 
             return FLOAT   ;    
        else if(!(_value.back() == 'f') || (_value ==  "-inf") |  (_value ==  "+inf"))  
            return DOUBLE ;    
    }  
   throw Converter::typeNotFoundException() ;    
} ;   



void Converter::convert_char(std::string _char )  
{ 
    std::cout << std::fixed << std::setprecision(1); 
    std::cout<<"CHAR  :"<<_char<<std::endl ;   
    std::cout<<"INT   :"<<static_cast<int>(_char[0])<<std::endl;    
    std::cout<<"FLOAT :"<<static_cast<float>(_char[0]) <<"f"<<std::endl ;    
    std::cout<<"DOUBLE :"<<static_cast<float>(_char[0])<<std::endl ;    
    std::cout<<"FLOAT :"<<static_cast<float>(_char[0])<<std::endl ;    
} ;    

void Converter::convert_int(std::string _int )  
{    
    
    std::cout << std::fixed << std::setprecision(1); 
    (atoi(_int.c_str())>= 32 &&  atoi(_int.c_str()) <= 126 )?
    (std::cout<<"CHAR   :"<< static_cast<char> (atoi(_int.c_str()))<<std::endl ): 
    (std::cout<<"CHAR   :"<<"Non displayable"<<std::endl  ) ;  
    std::cout<<"INT     :"<<atoi(_int.c_str())<<std::endl ;
    std::cout<<"FLOAT   :"<<static_cast<float>(atoi(_int.c_str())) <<"f"<<std::endl ;    
    std::cout<<"DOUBLE  :"<<static_cast<double>(atoi(_int.c_str()))<<std::endl ;   
}   

void  Converter::convert_float(std::string _float  )  
{ 
  (((atof(_float.c_str())  -   (static_cast <int>  (atof(_float.c_str()))  )) == 0 )  ||  (atoi(_float.c_str())< 32 &&  atoi(_float.c_str()) > 126 ))?
    (std::cout<<"CHAR   :"<< static_cast<char> (atoi(_float.c_str()))<<std::endl ): 
    (std::cout<<"CHAR   :"<<"Non displayable"<<std::endl  ) ;  
    std::cout << std::fixed << std::setprecision(1);  
    std::cout<<"FLOAT   :"<<atof(_float.c_str()) <<"f"<<std::endl ;   
    std::cout<<"DOUBLE  :"<<atof(_float.c_str()) <<std::endl ;    
}  ;  

void  Converter::convert_double(std::string _float  )  
{ 
  (((atof(_float.c_str())  -   (static_cast <int>  (atof(_float.c_str()))  )) == 0 )  ||  (atoi(_float.c_str())< 32 &&  atoi(_float.c_str()) > 126 ))?
    (std::cout<<"CHAR   :"<< static_cast<char> (atoi(_float.c_str()))<<std::endl ): 
    (std::cout<<"CHAR   :"<<"Non displayable"<<std::endl  ) ;  
    std::cout << std::fixed << std::setprecision(1);  
    std::cout<<"FLOAT   :"<<atof(_float.c_str()) <<"f"<<std::endl ;   
    std::cout<<"DOUBLE  :"<<atof(_float.c_str()) <<std::endl ;    
}  ;  

void Converter::convertNans(std::string _NAN  ) 
{ 
  std::cout<<"CHAR  :impossible"<<std::endl  ;  
  std::cout<<"INT   :impossible"<<std::endl ;   
  std::cout<<"FLOAT :"<<_NAN +'f'<<std::endl ;  
    std::cout<<"DOUBLE  :"<<_NAN<<std::endl ;    
} ;  
void Converter::handle_convert(std::string _value  ) 
{  
   void (*funcArray[5])(std::string) = { convert_char , convert_int , convert_double ,  convert_float   ,  convertNans}  ;    
   funcArray[typeGet(_value)](_value) ;  
}