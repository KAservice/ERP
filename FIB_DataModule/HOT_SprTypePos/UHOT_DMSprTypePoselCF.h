#ifndef UHOT_DMSprTypePoselCFH                  
#define UHOT_DMSprTypePoselCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMSprTypePoselCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMSprTypePoselCF();                                                           
   ~THOT_DMSprTypePoselCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
