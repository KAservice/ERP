#ifndef UART_FormaSpiskaSprNaborInfBlockCFH                  
#define UART_FormaSpiskaSprNaborInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaSpiskaSprNaborInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaSpiskaSprNaborInfBlockCF();                                                           
   ~TART_FormaSpiskaSprNaborInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
