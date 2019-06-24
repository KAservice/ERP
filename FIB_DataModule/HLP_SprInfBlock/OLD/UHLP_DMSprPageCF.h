#ifndef UHLP_DMSprPageCFH                  
#define UHLP_DMSprPageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprPageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprPageCF();                                                           
   ~THLP_DMSprPageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
