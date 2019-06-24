#ifndef UART_DMSprInfBlockPrivCFH                  
#define UART_DMSprInfBlockPrivCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprInfBlockPrivCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprInfBlockPrivCF();                                                           
   ~TART_DMSprInfBlockPrivCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
