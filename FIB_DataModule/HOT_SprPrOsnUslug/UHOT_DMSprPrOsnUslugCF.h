#ifndef UHOT_DMSprPrOsnUslugCFH                  
#define UHOT_DMSprPrOsnUslugCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMSprPrOsnUslugCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMSprPrOsnUslugCF();                                                           
   ~THOT_DMSprPrOsnUslugCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
