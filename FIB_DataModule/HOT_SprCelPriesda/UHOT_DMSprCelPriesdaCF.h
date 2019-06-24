#ifndef UHOT_DMSprCelPriesdaCFH                  
#define UHOT_DMSprCelPriesdaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMSprCelPriesdaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMSprCelPriesdaCF();                                                           
   ~THOT_DMSprCelPriesdaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
