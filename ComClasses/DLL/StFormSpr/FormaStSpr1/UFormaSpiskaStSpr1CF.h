#ifndef UFormaSpiskaStSpr1CFH                  
#define UFormaSpiskaStSpr1CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaStSpr1CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaStSpr1CF();                                                           
   ~TFormaSpiskaStSpr1CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
