#ifndef UHLP_DMSprNaborInfBlockCFH                  
#define UHLP_DMSprNaborInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprNaborInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprNaborInfBlockCF();                                                           
   ~THLP_DMSprNaborInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
