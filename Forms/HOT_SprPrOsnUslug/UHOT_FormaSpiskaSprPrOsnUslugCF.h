#ifndef UHOT_FormaSpiskaSprPrOsnUslugCFH                  
#define UHOT_FormaSpiskaSprPrOsnUslugCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaSpiskaSprPrOsnUslugCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaSpiskaSprPrOsnUslugCF();                                                           
   ~THOT_FormaSpiskaSprPrOsnUslugCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
