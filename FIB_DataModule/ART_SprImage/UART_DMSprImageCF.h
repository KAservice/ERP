#ifndef UART_DMSprImageCFH                  
#define UART_DMSprImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TART_DMSprImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TART_DMSprImageCF();                                                           
   ~TART_DMSprImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
