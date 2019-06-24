#ifndef UART_FormaElementaSprImageGrpCFH                  
#define UART_FormaElementaSprImageGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_FormaElementaSprImageGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_FormaElementaSprImageGrpCF();                                                           
   ~TART_FormaElementaSprImageGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
