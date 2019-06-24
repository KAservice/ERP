#ifndef UFormaSpiskaSprEdTouchCFH                  
#define UFormaSpiskaSprEdTouchCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprEdTouchCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprEdTouchCF();                                                           
   ~TFormaSpiskaSprEdTouchCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
