#ifndef UHLP_DMSprInfBlockCFH                  
#define UHLP_DMSprInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprInfBlockCF();                                                           
   ~THLP_DMSprInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
