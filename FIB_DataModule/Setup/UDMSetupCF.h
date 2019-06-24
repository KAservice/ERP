#ifndef UDMSetupCFH                  
#define UDMSetupCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSetupCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSetupCF();                                                           
   ~TDMSetupCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
