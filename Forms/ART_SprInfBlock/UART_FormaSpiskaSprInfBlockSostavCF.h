#ifndef UART_FormaSpiskaSprInfBlockSostavCFH                  
#define UART_FormaSpiskaSprInfBlockSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaSpiskaSprInfBlockSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaSpiskaSprInfBlockSostavCF();                                                           
   ~TART_FormaSpiskaSprInfBlockSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
