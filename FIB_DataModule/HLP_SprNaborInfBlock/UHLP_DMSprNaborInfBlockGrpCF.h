#ifndef UHLP_DMSprNaborInfBlockGrpCFH                  
#define UHLP_DMSprNaborInfBlockGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_DMSprNaborInfBlockGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_DMSprNaborInfBlockGrpCF();                                                           
   ~THLP_DMSprNaborInfBlockGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
