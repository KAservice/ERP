#ifndef UART_FormaElementaSprImageCFH                  
#define UART_FormaElementaSprImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaElementaSprImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaElementaSprImageCF();                                                           
   ~TART_FormaElementaSprImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
