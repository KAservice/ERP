#ifndef UDMSprOborudParamCFH                  
#define UDMSprOborudParamCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprOborudParamCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprOborudParamCF();                                                           
   ~TDMSprOborudParamCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
