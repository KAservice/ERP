#ifndef UHLP_DMSprPageElementCFH                  
#define UHLP_DMSprPageElementCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprPageElementCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprPageElementCF();                                                           
   ~THLP_DMSprPageElementCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
