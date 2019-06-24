#ifndef UFormaSpiskaSprFirmCFH                  
#define UFormaSpiskaSprFirmCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprFirmCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprFirmCF();                                                           
   ~TFormaSpiskaSprFirmCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
