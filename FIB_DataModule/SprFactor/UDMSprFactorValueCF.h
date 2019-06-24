#ifndef UDMSprFactorValueCFH                  
#define UDMSprFactorValueCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprFactorValueCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprFactorValueCF();                                                           
   ~TDMSprFactorValueCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
