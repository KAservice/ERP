#ifndef UART_DMSprNaborInfBlockSostavCFH                  
#define UART_DMSprNaborInfBlockSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprNaborInfBlockSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprNaborInfBlockSostavCF();                                                           
   ~TART_DMSprNaborInfBlockSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
