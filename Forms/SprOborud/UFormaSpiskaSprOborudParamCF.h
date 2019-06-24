#ifndef UFormaSpiskaSprOborudParamCFH                  
#define UFormaSpiskaSprOborudParamCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprOborudParamCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprOborudParamCF();                                                           
   ~TFormaSpiskaSprOborudParamCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
