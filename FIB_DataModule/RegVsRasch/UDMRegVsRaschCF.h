#ifndef UDMRegVsRaschCFH                  
#define UDMRegVsRaschCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMRegVsRaschCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMRegVsRaschCF();                                                           
   ~TDMRegVsRaschCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
