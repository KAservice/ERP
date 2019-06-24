#ifndef UART_FormaElementaSprInfBlockCFH                  
#define UART_FormaElementaSprInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaElementaSprInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaElementaSprInfBlockCF();                                                           
   ~TART_FormaElementaSprInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
