#ifndef UDMExtModuleCFH                  
#define UDMExtModuleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMExtModuleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMExtModuleCF();                                                           
   ~TDMExtModuleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
