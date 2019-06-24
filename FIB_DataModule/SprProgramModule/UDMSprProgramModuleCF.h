#ifndef UDMSprProgramModuleCFH                  
#define UDMSprProgramModuleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprProgramModuleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprProgramModuleCF();                                                           
   ~TDMSprProgramModuleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
