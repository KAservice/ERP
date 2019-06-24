#ifndef UDMDocCheckCFH                  
#define UDMDocCheckCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocCheckCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocCheckCF();                                                           
   ~TDMDocCheckCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
