#ifndef UART_FormaElementaSprNaborInfBlockSostavGrpCFH                  
#define UART_FormaElementaSprNaborInfBlockSostavGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaElementaSprNaborInfBlockSostavGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaElementaSprNaborInfBlockSostavGrpCF();                                                           
   ~TART_FormaElementaSprNaborInfBlockSostavGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
