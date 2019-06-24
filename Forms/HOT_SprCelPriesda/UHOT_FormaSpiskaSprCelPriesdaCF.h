#ifndef UHOT_FormaSpiskaSprCelPriesdaCFH                  
#define UHOT_FormaSpiskaSprCelPriesdaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaSpiskaSprCelPriesdaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaSpiskaSprCelPriesdaCF();                                                           
   ~THOT_FormaSpiskaSprCelPriesdaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
