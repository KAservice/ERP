#ifndef UART_DMSprInfBlockCFH                  
#define UART_DMSprInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprInfBlockCF();                                                           
   ~TART_DMSprInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
