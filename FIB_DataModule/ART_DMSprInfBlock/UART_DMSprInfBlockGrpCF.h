#ifndef UART_DMSprInfBlockGrpCFH                  
#define UART_DMSprInfBlockGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprInfBlockGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprInfBlockGrpCF();                                                           
   ~TART_DMSprInfBlockGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
