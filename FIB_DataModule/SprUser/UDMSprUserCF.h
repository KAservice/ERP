#ifndef UDMSprUserCFH                  
#define UDMSprUserCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprUserCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprUserCF();                                                           
   ~TDMSprUserCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
