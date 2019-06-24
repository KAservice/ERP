#ifndef UART_FormaSpiskaSprNaborInfBlockSostavCFH                  
#define UART_FormaSpiskaSprNaborInfBlockSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaSpiskaSprNaborInfBlockSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaSpiskaSprNaborInfBlockSostavCF();                                                           
   ~TART_FormaSpiskaSprNaborInfBlockSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
