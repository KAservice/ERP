#ifndef UDMStSpr1CFH                  
#define UDMStSpr1CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMStSpr1CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMStSpr1CF();                                                           
   ~TDMStSpr1CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
