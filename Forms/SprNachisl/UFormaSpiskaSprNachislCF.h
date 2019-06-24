#ifndef UFormaSpiskaSprNachislCFH                  
#define UFormaSpiskaSprNachislCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprNachislCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprNachislCF();                                                           
   ~TFormaSpiskaSprNachislCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
