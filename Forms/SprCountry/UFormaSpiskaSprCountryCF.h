#ifndef UFormaSpiskaSprCountryCFH                  
#define UFormaSpiskaSprCountryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprCountryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprCountryCF();                                                           
   ~TFormaSpiskaSprCountryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
