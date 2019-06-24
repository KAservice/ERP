#ifndef UDMDocPlPCFH                  
#define UDMDocPlPCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocPlPCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocPlPCF();                                                           
   ~TDMDocPlPCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
