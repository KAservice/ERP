#ifndef UHLP_DMSprInfBlockPrivCFH                  
#define UHLP_DMSprInfBlockPrivCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprInfBlockPrivCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprInfBlockPrivCF();                                                           
   ~THLP_DMSprInfBlockPrivCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
