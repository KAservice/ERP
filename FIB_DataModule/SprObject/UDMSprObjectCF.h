#ifndef UDMSprObjectCFH                  
#define UDMSprObjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprObjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprObjectCF();                                                           
   ~TDMSprObjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
