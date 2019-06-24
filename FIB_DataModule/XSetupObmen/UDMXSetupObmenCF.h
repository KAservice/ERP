#ifndef UDMXSetupObmenCFH                  
#define UDMXSetupObmenCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMXSetupObmenCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMXSetupObmenCF();                                                           
   ~TDMXSetupObmenCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
