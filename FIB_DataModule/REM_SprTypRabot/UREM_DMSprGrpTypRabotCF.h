#ifndef UREM_DMSprGrpTypRabotCFH                  
#define UREM_DMSprGrpTypRabotCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprGrpTypRabotCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprGrpTypRabotCF();                                                           
   ~TREM_DMSprGrpTypRabotCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
