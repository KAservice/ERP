#ifndef UDMViborOborudCFH                  
#define UDMViborOborudCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMViborOborudCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMViborOborudCF();                                                           
   ~TDMViborOborudCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
