#ifndef UDMSprStrObjectCFH                  
#define UDMSprStrObjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprStrObjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprStrObjectCF();                                                           
   ~TDMSprStrObjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
