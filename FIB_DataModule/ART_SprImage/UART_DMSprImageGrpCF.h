#ifndef UART_DMSprImageGrpCFH                  
#define UART_DMSprImageGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprImageGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprImageGrpCF();                                                           
   ~TART_DMSprImageGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
