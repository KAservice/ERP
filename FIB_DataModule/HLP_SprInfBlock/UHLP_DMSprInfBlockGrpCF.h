#ifndef UHLP_DMSprInfBlockGrpCFH                  
#define UHLP_DMSprInfBlockGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprInfBlockGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprInfBlockGrpCF();                                                           
   ~THLP_DMSprInfBlockGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
