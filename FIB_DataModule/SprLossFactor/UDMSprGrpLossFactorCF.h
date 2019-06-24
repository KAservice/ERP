#ifndef UDMSprGrpLossFactorCFH                  
#define UDMSprGrpLossFactorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprGrpLossFactorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprGrpLossFactorCF();                                                           
   ~TDMSprGrpLossFactorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
