#ifndef UDMProgramSetupCFH                  
#define UDMProgramSetupCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMProgramSetupCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMProgramSetupCF();                                                           
   ~TDMProgramSetupCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
