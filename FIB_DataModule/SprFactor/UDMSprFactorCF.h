#ifndef UDMSprFactorCFH                  
#define UDMSprFactorCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprFactorCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprFactorCF();                                                           
   ~TDMSprFactorCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
