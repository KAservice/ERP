#ifndef UFormaStrObjectTouchCFH                  
#define UFormaStrObjectTouchCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaStrObjectTouchCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaStrObjectTouchCF();                                                           
   ~TFormaStrObjectTouchCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
