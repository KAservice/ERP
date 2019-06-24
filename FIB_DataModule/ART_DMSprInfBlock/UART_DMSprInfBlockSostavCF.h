#ifndef UART_DMSprInfBlockSostavCFH                  
#define UART_DMSprInfBlockSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprInfBlockSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprInfBlockSostavCF();                                                           
   ~TART_DMSprInfBlockSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
