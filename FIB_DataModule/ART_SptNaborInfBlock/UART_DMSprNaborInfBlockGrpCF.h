#ifndef UART_DMSprNaborInfBlockGrpCFH                  
#define UART_DMSprNaborInfBlockGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprNaborInfBlockGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprNaborInfBlockGrpCF();                                                           
   ~TART_DMSprNaborInfBlockGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
