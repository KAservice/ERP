#ifndef UART_FormaElementaSprNaborInfBlockGrpCFH                  
#define UART_FormaElementaSprNaborInfBlockGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaElementaSprNaborInfBlockGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaElementaSprNaborInfBlockGrpCF();                                                           
   ~TART_FormaElementaSprNaborInfBlockGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
