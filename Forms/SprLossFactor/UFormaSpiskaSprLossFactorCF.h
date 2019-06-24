#ifndef UFormaSpiskaSprLossFactorCFH                  
#define UFormaSpiskaSprLossFactorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprLossFactorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprLossFactorCF();                                                           
   ~TFormaSpiskaSprLossFactorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
