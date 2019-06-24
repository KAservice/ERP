#ifndef UART_FormaElementaSprInfBlockGrpCFH                  
#define UART_FormaElementaSprInfBlockGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaElementaSprInfBlockGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaElementaSprInfBlockGrpCF();                                                           
   ~TART_FormaElementaSprInfBlockGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
