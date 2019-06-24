#ifndef UHLP_DMSprNaborInfBlockSostavCFH                  
#define UHLP_DMSprNaborInfBlockSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprNaborInfBlockSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprNaborInfBlockSostavCF();                                                           
   ~THLP_DMSprNaborInfBlockSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
