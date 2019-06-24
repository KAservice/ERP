#ifndef UDMSprInvCFH                  
#define UDMSprInvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprInvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprInvCF();                                                           
   ~TDMSprInvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
