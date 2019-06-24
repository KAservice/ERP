#ifndef UHOT_DMSprObjectCFH                  
#define UHOT_DMSprObjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMSprObjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMSprObjectCF();                                                           
   ~THOT_DMSprObjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
