#ifndef UDMSprCountryCFH                  
#define UDMSprCountryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprCountryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprCountryCF();                                                           
   ~TDMSprCountryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
