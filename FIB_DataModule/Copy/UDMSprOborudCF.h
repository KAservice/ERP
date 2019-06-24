#ifndef UDMSprOborudCFH                  
#define UDMSprOborudCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprOborudCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprOborudCF();                                                           
   ~TDMSprOborudCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
