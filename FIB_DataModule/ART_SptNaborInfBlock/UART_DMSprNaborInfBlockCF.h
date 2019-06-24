#ifndef UART_DMSprNaborInfBlockCFH                  
#define UART_DMSprNaborInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprNaborInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprNaborInfBlockCF();                                                           
   ~TART_DMSprNaborInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
