#ifndef UDMSprLossFactorCFH                  
#define UDMSprLossFactorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprLossFactorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprLossFactorCF();                                                           
   ~TDMSprLossFactorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
