#ifndef UHLP_DMSprInfBlockSostavCFH                  
#define UHLP_DMSprInfBlockSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprInfBlockSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprInfBlockSostavCF();                                                           
   ~THLP_DMSprInfBlockSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
