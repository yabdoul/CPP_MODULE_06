#include <string>  
#include <exception>   

#pragma once 
  
#define CHAR 0
#define INT 1  
#define DOUBLE 2  
#define FLOAT 3  

class Converter
{
    public:
      Converter(){};  
      Converter(Converter &C){(void) C ;   }  ;   
      ~Converter(){};     
      
    //   Converter operator=(Converter  &C ) { (void) C ;   } ;  

      static int typeGet(std::string _value )  ;      
      static bool fullDegit(std::string _value )  ;  
      static void  convert_char(std::string _char ) ;  
      static void  convert_int(std::string _int )   ;   
      static void  convert_double(std::string _double)  ;  
      static void  convert_float(std::string _float )   ;    
      static void handle_convert(std::string _value  )   ;        

   class typeNotFoundException : public std::exception
    {
        public:
            typeNotFoundException(const char* message = "Type not found exception") 
            : msg_(message) {}
            virtual const char* what() const throw() {return msg_;}
        private:
            const char* msg_;
    };

};
   