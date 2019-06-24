#ifndef UHOT_DMSprSostNomCFH                  
#define UHOT_DMSprSostNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMSprSostNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMSprSostNomCF();                                                           
   ~THOT_DMSprSostNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
