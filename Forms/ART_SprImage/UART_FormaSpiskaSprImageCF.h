#ifndef UART_FormaSpiskaSprImageCFH                  
#define UART_FormaSpiskaSprImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaSpiskaSprImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaSpiskaSprImageCF();                                                           
   ~TART_FormaSpiskaSprImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
