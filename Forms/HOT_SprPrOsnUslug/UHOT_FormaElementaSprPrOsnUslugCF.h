#ifndef UHOT_FormaElementaSprPrOsnUslugCFH                  
#define UHOT_FormaElementaSprPrOsnUslugCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaElementaSprPrOsnUslugCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaElementaSprPrOsnUslugCF();                                                           
   ~THOT_FormaElementaSprPrOsnUslugCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
