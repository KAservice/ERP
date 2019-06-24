#ifndef UART_FormaElementaSprNaborInfBlockCFH                  
#define UART_FormaElementaSprNaborInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaElementaSprNaborInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaElementaSprNaborInfBlockCF();                                                           
   ~TART_FormaElementaSprNaborInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
