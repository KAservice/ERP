#ifndef UHOT_DMSprCatNomCFH                  
#define UHOT_DMSprCatNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMSprCatNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMSprCatNomCF();                                                           
   ~THOT_DMSprCatNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
