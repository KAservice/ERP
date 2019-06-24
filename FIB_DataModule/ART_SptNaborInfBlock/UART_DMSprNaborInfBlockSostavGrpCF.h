#ifndef UART_DMSprNaborInfBlockSostavGrpCFH                  
#define UART_DMSprNaborInfBlockSostavGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprNaborInfBlockSostavGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprNaborInfBlockSostavGrpCF();                                                           
   ~TART_DMSprNaborInfBlockSostavGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
