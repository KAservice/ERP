#ifndef UFormaSpiskaSprTypeAnalogCFH                  
#define UFormaSpiskaSprTypeAnalogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprTypeAnalogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprTypeAnalogCF();                                                           
   ~TFormaSpiskaSprTypeAnalogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
