#ifndef UFormaDocCheckTouchCFH                  
#define UFormaDocCheckTouchCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocCheckTouchCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocCheckTouchCF();                                                           
   ~TFormaDocCheckTouchCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
