#ifndef UHLP_DMSprNaborInfBlockSostavGrpCFH                  
#define UHLP_DMSprNaborInfBlockSostavGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprNaborInfBlockSostavGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprNaborInfBlockSostavGrpCF();                                                           
   ~THLP_DMSprNaborInfBlockSostavGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
