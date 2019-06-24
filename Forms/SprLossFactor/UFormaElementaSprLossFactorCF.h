#ifndef UFormaElementaSprLossFactorCFH                  
#define UFormaElementaSprLossFactorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprLossFactorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprLossFactorCF();                                                           
   ~TFormaElementaSprLossFactorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
